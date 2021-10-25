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

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
char db[100][100];
bool visited[100][100];
//bool visited2[100][100];
int n;

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({ i,j });
    visited[i][j] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (!visited[nx][ny] && db[nx][ny] == db[x][y])
                {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }
    return;
}




int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
 
    
    cin >> n;
    vector<string> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            db[i][j] = res[i][j];
        }
    }

    memset(visited, false, sizeof(visited));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                bfs(i, j);
                ans++;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (db[i][j] == 'G')
                db[i][j] = 'R'; // 적록색약
        }
    }
    int ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                bfs(i, j);
                ans2++;
            }
        }
    }

    cout << ans << " " << ans2 << endl;
	
}
