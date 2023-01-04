## BFS, DFS

Union Find 문제

```c++
class Solution {
public:

    int findParent(map<int,int>& parent, int node){
        if(node == parent[node])
            return node;
        int nodeParent = findParent(parent, parent[node]);
        parent[node] = nodeParent;
        return nodeParent;
    }

    bool Union(map<int,int>& parent, map<int,int>& rank, int node, int node2){
        int parent1 = findParent(parent, node);
        int parent2 = findParent(parent, node2);

        if(parent1==parent2)
            return false;
        
        int rank1 = rank[parent1];
        int rank2 = rank[parent2];

        if(parent1<parent2){
            parent[parent1] = parent2;
        }else if(parent2<parent1){
            parent[parent2] = parent1;
        }else{
            parent[parent1] = parent2;
            rank[parent2] = rank[parent2]+1;
        }
        return true;
    }



    int findCircleNum(vector<vector<int>>& isConnected) {
        map<int, int> parent;
        map<int, int> rank;

        int row = isConnected.size();
        int col = row;

        int cnt = 0;

        for(int i=0;i<row;i++){
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isConnected[i][j] == 1 && Union(parent, rank, i, j)){
                    cnt++;
                }
            }
        }
        return col - cnt;
    }
};
```
