#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <set>
#include <numeric>
#include <cmath>
#include <stack>

#define INF 1000000000

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


int bfs(int x, int y, int tx, int ty, vector<string>& maps) {
    int row = maps.size();
    int col = maps[0].size();

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    int cnt = 0;
    while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            auto it = q.front();
            q.pop();
            if (it.first == tx && it.second == ty) {
                return cnt;
            }
            for (int d = 0; d < 4; d++) {
                int nx = it.first + dx[d];
                int ny = it.second + dy[d];
                if (nx < 0 || ny < 0 || nx >= row || ny >= col) {
                    continue;
                }

                if (!visited[nx][ny] && maps[nx][ny] != 'X') {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
        cnt++;
    }
    return 0;
}



int solution(vector<string> maps) {
    int answer = 0;

    int row = maps.size();
    int col = maps[0].size();

    int sx, sy, ex, ey, rx, ry;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maps[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (maps[i][j] == 'E') {
                ex = i;
                ey = j;
            }
            else if (maps[i][j] == 'L') {
                rx = i;
                ry = j;
            }
        }
    }

    int start = bfs(sx, sy, rx, ry, maps);
    int end = bfs(rx, ry, ex, ey, maps);

    return start == 0 || end == 0 ? -1 : start + end;
}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> maps = { "SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE" };
    vector<string> maps2 = { "LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO" };
    vector<string> maps3 = { "SOOOO", "XXXXX", "LOOOO", "XXXXX", "EOOOO" };
    vector<string> maps4 = { "SOOOL", "OXXXO", "OOOOO", "OXXXX", "EOOOO" };
    cout << solution(maps) << endl;
    cout << solution(maps2) << endl;
    cout << solution(maps3) << endl;
    cout << solution(maps4) << endl;

}
// 2335
