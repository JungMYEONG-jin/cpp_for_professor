## dfs를 이용해서 컬러 채우기


```c++
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int row = image.size();
        int col = image[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int prevColor = image[sr][sc];
        visited[sr][sc] = true;
        image[sr][sc] = color;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=row || ny>=col)
                    continue;

                if(!visited[nx][ny] && image[nx][ny]==prevColor)
                {
                    visited[nx][ny] = true;
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;

    }
};
```
