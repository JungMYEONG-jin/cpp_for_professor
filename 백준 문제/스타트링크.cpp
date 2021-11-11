#include <iostream>
#include <queue>

using namespace std;

bool visited[1000001];
queue<pair<int, int>> q;
int f, s, g, u, d, cnt;

void dfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == g)
        {
            cnt = y;
            return;
        }
        if (x-d>0 && !visited[x-d])
        {
            q.push({ x - d, y + 1 });
            visited[x - d] = true;
        }
        if ((x + u)<=f && !visited[x+u])
        {
            q.push({ x + u, y + 1 });
            visited[x + u] = true;
        }
        
    }
    return;
}

int main()
{
    cin >> f >> s >> g >> u >> d;
    cnt = -1;
    visited[s] = true;
    q.push({ s,0 });
    dfs();
    if (cnt >= 0)
        cout << cnt << endl;
    else
        cout << "use the stairs";
}
