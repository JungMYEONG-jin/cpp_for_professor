## DFS

0에서부터 출발해서 각 인덱스로 DFS 돌리면 됨.

```c++
class Solution {
public:
    vector<vector<int>> res;
    vector<int> arr[16];

    void dfs(vector<vector<int>>& graph, int idx, vector<int>& temp, vector<vector<int>>& res){
        if(idx+1 == graph.size()){
            res.push_back(temp);
            return;
        }
        for(int next : graph[idx]){
            temp.push_back(next);
            dfs(graph, next, temp, res);
            temp.pop_back();
        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> temp;
        temp.push_back(0);
        dfs(graph, 0, temp, res);
        return res;
    }
};
```
