#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

bool visited[11][11][11][11] = { false, };
char db[11][11];
int n, m;
int hx, hy;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int x, int y, int z, int d)
{
    queue<tuple<int, int, int, int>> q; // red and blue
    q.push({ x,y,z,d });
    visited[x][y][z][d] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int rx, ry, bx, by;
            tie(rx, ry, bx, by) = q.front();
            q.pop();
            if (rx == hx && ry == hy)
            {
                return cnt;
            }
            for (int j = 0; j < 4; j++)
            {
                int nrx = rx;
                int nry = ry;
                int nbx = bx;
                int nby = by;
                // 벽 만나기 전까지
                while (db[nrx + dx[j]][nry + dy[j]] != '#' && db[nrx][nry] != 'O')
                {
                    nrx += dx[j];
                    nry += dy[j];
                }
                while (db[nbx + dx[j]][nby + dy[j]] != '#' && db[nbx][nby] != 'O')
                {
                    nbx += dx[j];
                    nby += dy[j];
                }
                // 둘이 충돌시
                if (nrx == nbx && nry == nby)
                {
                    if (nrx == hx && nry == hy)
                        continue; // pass
                    if ((abs(nrx - rx) + abs(nry - ry)) > (abs(nbx - bx) + abs(nby - by))) // 더밀러서오면 다시 back
                    {
                        nrx -= dx[j];
                        nry -= dy[j];
                    }
                    else
                    {
                        nbx -= dx[j];
                        nby -= dy[j];
                    }
                }

                if (visited[nrx][nry][nbx][nby])
                    continue;
                visited[nrx][nry][nbx][nby] = true;
                q.push({ nrx, nry, nbx, nby });

            }

        }
        if (cnt == 10)
            return -1;
        cnt++;
    }


    return -1;
}

int main()
{
    cin >> n >> m;
    string str;
    int rx = 0, ry = 0, bx = 0, by = 0; //red ball x y    blue ball x y
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            db[i][j] = str[j];
            if (str[j] == 'R')
            {
                rx = i;
                ry = j;

            }
            else if (str[j] == 'B')
            {
                bx = i;
                by = j;
            }
            else if (str[j] == 'O')
            {
                hx = i;
                hy = j;
            }
        }
    }
    int num = bfs(rx, ry, bx, by);
    cout << num << endl;

    return 0;


}
