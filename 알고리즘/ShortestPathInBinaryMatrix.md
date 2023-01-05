## BFS

BFS 로 구현

```c++
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        pair<int,int> dir[] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        vector<vector<int>> dist(n, vector<int>(n, 9999));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        dist[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()){
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop();

            for(int i=0;i<8;i++){
                int nx = x+dir[i].first;
                int ny = y+dir[i].second;

                if(nx<0 || ny<0 || nx>=n || ny>=n)
                    continue;
                if(!visited[nx][ny] && grid[nx][ny]==0){
                    visited[nx][ny] = true;
                    dist[nx][ny] = min(dist[nx][ny], dist[x][y]+1);
                    q.push({nx, ny});
                }
            }

        }
        return dist[n-1][n-1] == 9999 ? -1 : dist[n-1][n-1];
    }
};
```
