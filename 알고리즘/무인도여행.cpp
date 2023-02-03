#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int row = maps.size();
    int col = maps[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    for(int i = 0;i<row;i++){
        for(int j=0;j<col;j++){
            if(!visited[i][j] && maps[i][j]!='X'){
                queue<pair<int, int>> q;
                q.push({i, j});
                int val = 0;
                val+=static_cast<int>(maps[i][j] - '0');
                visited[i][j] = true;
                while(!q.empty()){
                    auto it = q.front();
                    q.pop();
                    int x = it.first;
                    int y = it.second;
                    
                    for(int d = 0; d<4;d++){
                        int nx = x+dx[d];
                        int ny = y+dy[d];
                        if(nx<0 || ny<0 || nx>=row || ny>=col)
                            continue;
                        if(!visited[nx][ny] && maps[nx][ny] != 'X'){
                            q.push({nx, ny});
                            val+=static_cast<int>(maps[nx][ny] - '0');
                            visited[nx][ny] = true;
                        }
                    }
                }
                answer.push_back(val);
            }
        }
    }
    
    if(answer.empty())
        answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}
