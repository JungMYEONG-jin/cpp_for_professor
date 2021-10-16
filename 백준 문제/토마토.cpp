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

#define INF 999999999

using namespace std;
int n, m;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
int db[1000][1000];


void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (db[nx][ny] == 0)
                {
                    db[nx][ny] = db[x][y] + 1;
                    q.push({ nx, ny });
                }
            }
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> db[i][j];
            if (db[i][j] == 1)
                q.push({ i,j });
        }
    }

    bfs();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (db[i][j] == 0)
            {
                cout << -1 << endl;
                return 0;
            }

            cnt = max(cnt, db[i][j]);
        }
    }
    
    
    cout << cnt-1 << endl;
          

    
	
}
