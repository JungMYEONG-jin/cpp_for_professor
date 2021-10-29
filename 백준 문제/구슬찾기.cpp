#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <set>
#include <list>
#include <cstring>


using namespace std;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int n, m;
int ans = 0;
char db[10][10];
bool visited[10][10][10][10];
int hx, hy;

int bfs(int x, int y, int z, int d)
{
    queue<tuple<int, int, int, int>> q; // red x y      blue x y
    q.push({ x,y,z,d });
    visited[x][y][z][d] = true;
    while (!q.empty())
    {
        
        int len = q.size();
        for (int j = 0; j < len; j++)
        {

            int rx, ry, bx, by;
            tie(rx, ry, bx, by) = q.front();
            q.pop();
            if (rx == hx && ry == hy)
                return 1;

            for (int i = 0; i < 4; i++)
            {
                int nrx = rx;
                int nry = ry;
                int nbx = bx;
                int nby = by;
                while (db[nrx + dx[i]][nry + dy[i]] != '#' && db[nrx][nry] != 'O') // 계속이동
                {
                    nrx += dx[i];
                    nry += dy[i];
                }
                while (db[nbx + dx[i]][nby + dy[i]] != '#' && db[nbx][nby] != 'O') // 계속이동
                {
                    nbx += dx[i];
                    nby += dy[i];
                }

                if (nrx == nbx && nry == nby) // 겹치는경우
                {
                    if (nrx == hx && nry == hy) // 겹치는데 구멍은 오류
                        continue;
                    if ((abs(nrx - rx) + abs(nry - ry)) > (abs(nbx - bx) + abs(nby - by)))
                    {
                        nrx -= dx[i];
                        nry -= dy[i];
                    }
                    else
                    {
                        nbx -= dx[i];
                        nby -= dy[i];
                    }
                }

                if (visited[nrx][nry][nbx][nby])
                    continue;
                visited[nrx][nry][nbx][nby] = true;
                q.push({ nrx, nry, nbx, nby });


            }
        }
        if (ans == 10)
            return 0;
        ans++;
    }
    return 0;
}




int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;
    //memset(visited, false, sizeof(visited));
    int srx, sry, sbx, sby; // start of red x, y        start of blue x, y
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            db[i][j] = str[j];
            if (str[j] == 'R')
            {
                srx = i;
                sry = j;
            }
            else if (str[j] == 'B')
            {
                sbx = i;
                sby = j;
            }
            else if (str[j] == 'O')
            {
                hx = i;
                hy = j;
            }
        }
    }

    cout << bfs(srx, sry, sbx, sby) << endl;
   




}
