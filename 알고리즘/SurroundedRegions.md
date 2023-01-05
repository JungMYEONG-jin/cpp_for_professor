## BFS

BFS 문제인데 생각만 잘하면 쉬운 문제다. 경계선과 닿은 O들은 X가 될수 없으므로 

```c++
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // 경계선 O와 닿는 부분만 체크하면됨.
        // 어차피 그 외 O는 둘러쌓여서 사라질거임
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col));
        queue<pair<int, int>> q;
        for(int i=0;i<col;i++){
            if(board[0][i]=='O')
                q.push({0, i});
            if(board[row-1][i]=='O')
                q.push({row-1, i});
        }

        for(int i=0;i<row;i++){
            if(board[i][0]=='O')
                q.push({i, 0});
            if(board[i][col-1]=='O')
                q.push({i, col-1});
        }

        

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            visited[x][y] = true;

            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0|| ny<0 || nx>=row || ny>=col)
                    continue;
                if(board[nx][ny]=='O' && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }

        }

        // true는 경계선과 닿은 부분들 그외 다 X 로
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(visited[i][j])
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }


    }
};

```
