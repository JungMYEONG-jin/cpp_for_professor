## BFS를 이용해 콤비네이션 구현

```c++
class Solution {
public:

    vector<vector<int>> ans;
    bool visited[21];

    void bfs(int idx, int n, int k, int cnt, vector<int>& temp){
        if(cnt==k){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<=n;i++){
            if(!visited[i])
            {
                visited[i] = true;
                temp.push_back(i);
                bfs(i+1,n,k,cnt+1,temp);
                visited[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        bfs(1,n,k, 0, temp);
        return ans;
    }
};
```
