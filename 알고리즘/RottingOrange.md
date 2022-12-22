## BFS가 핵심인데 for도 활용해야됨.

오렌지가 동시에 썩으니까 큐에 있는 원소만큼을 한번에 돌려야됨. 따라서 for 이용 필수

```c++
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++){
                if(grid[i][j]==2)
                    q.push({i, j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        int cnt = 0;
        if(fresh==0)
            return cnt;
        while(!q.empty()){
            if(fresh==0)
                return cnt;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second;
                cout<<x<<" "<<y<<" "<<cnt<<endl;
                for(int i=0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx<0 || ny<0 || nx>=row || ny>=col || grid[nx][ny]!=1)
                        continue;
                    q.push({nx, ny});
                    grid[nx][ny] = 2;
                    fresh--;
                }
         }
        cnt++;
    }
    return -1;

}
};

```
