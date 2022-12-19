## dfs, bfs를 이용해 maxArea 구하기다.

원래는 visited 배열을 이용했으나 생각해보니 어차피 1, 0으로 구분되므로 다른값을 줘서 방문한셈 치면 되지 않나? 싶어서 방문 한 지점은 2로 세팅을 해줬다.
그 결과 시간 성능이 약 90퍼 효율 증가하였다.


```c++
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int maxArea = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    grid[i][j] = 2;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int cnt = 0;
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        int x = it.first;
                        int y = it.second;
                        cnt++;
                        for(int d=0;d<4;d++){
                            int nx = x+dx[d];
                            int ny = y+dy[d];
                            if(nx<0 || ny<0 || nx>=row || ny>=col)
                                continue;
                            if(grid[nx][ny]==1){
                                grid[nx][ny] = 2;
                                q.push({nx, ny});
                            }
                        }

                    }
                    maxArea = max(maxArea, cnt);
                }
            }
        }
        return maxArea;
        
    }
};
```
