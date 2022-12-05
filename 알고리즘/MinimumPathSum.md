다익스트라로 해결

근데 그냥 dp로 푸는게 더 성능이 좋은걸..?


```c++
class Solution {
public:

    
struct Cell {
    int x, y, cost;
};

class mycomparison {
public:
    bool operator()(const Cell& lhs, const Cell& rhs) const
    {
        return (lhs.cost > rhs.cost);
    }
};

int dp[201][201] = { 101, };
bool visited[201][201];


    int minPathSum(vector<vector<int>>& grid) {
        int sx = 0, sy = 0;
    int ex = grid.size();
    int ey = grid[0].size();

    int dx[] = { 1, 0}; // 아래
    int dy[] = { 0, 1}; // 오른쪽
    for (int i = 0; i < 201; i++)
        fill(dp[i], dp[i] + 201, 999);
    priority_queue < Cell, vector<Cell>, mycomparison> q;
    q.push({ sx, sy, grid[sx][sy] });
    dp[sx][sy] = grid[sx][sy];

    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int x = it.x;
        int y = it.y;
        int cost = it.cost;

        if (visited[x][y])
            continue;
        visited[x][y] = true;

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= ex || ny >= ey)
                continue;

            if (!visited[nx][ny]) {
                dp[nx][ny] = min(dp[nx][ny], dp[x][y] + grid[nx][ny]);
                q.push({ nx, ny, dp[nx][ny] });
            }
        }
    }
    
    return dp[ex-1][ey-1];
    }
    
    
    
    /// 이게 더 빠름//
    
    int minPathSum(vector<vector<int>>& grid) {
    int sx = 0, sy = 0;
    int ex = grid.size();
    int ey = grid[0].size();

    for (int i = 0; i < ex; i++) {
        for (int j = 0; j < ey; j++) {
            if (i == 0 && j == 0)
                continue;
            else if (i == 0) {
                grid[i][j] += grid[i][j - 1];
                continue;
            }
            else if (j == 0) {
                grid[i][j] += grid[i - 1][j];
                continue;
            }
            else {
                grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
    }
    
    return grid[ex-1][ey-1];
    }
};
```
