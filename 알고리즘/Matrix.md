## BFS를 이용해 품

0과 가장 가까운 거리를 구하는 문제였다. 따라서 0인것들만 큐에 넣어서 시작해주면 됨.

```c++
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0)
                    q.push({i, j}); // 0 에서 부터 시작이니까 
                else
                    mat[i][j] = -1;
               
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx<0 || ny<0 || nx>=row || ny>=col || mat[nx][ny]!=-1)
                    continue;
                mat[nx][ny] = mat[x][y]+1;
                q.push({nx, ny});
            }
        }

        return mat;
    }

};
```
