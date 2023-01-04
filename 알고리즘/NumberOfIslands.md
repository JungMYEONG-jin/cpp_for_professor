##  Number of Islands

BFS, DFS 문제 정형화된 패턴이라 간단하다.

```c++
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    ans++;
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        int x = it.first;
                        int y = it.second;
                        for(int d=0;d<4;d++){
                            int nx = x+dx[d];
                            int ny = y+dy[d];

                            if(nx<0 || ny<0 || nx>=row || ny>=col)
                                continue;
                            if(!visited[nx][ny] && grid[nx][ny]=='1'){
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```
