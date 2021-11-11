#include <iostream>
#include <queue>

#define INF 999999999

using namespace std;

int visited[100001];
int n, k, cnt;
queue<int> q;
const int mval = 100001;
void dfs()
{

    q.push(n);
    visited[n] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == k)
        {
            cnt = visited[k];
            return;
        }
        if (x - 1 >= 0 && visited[x - 1] > visited[x] + 1)
        {
            q.push({ x - 1 });
            visited[x - 1] = visited[x] + 1;
        }
        if ((x + 1) < mval && visited[x + 1] > visited[x] + 1)
        {
            q.push(x + 1);
            visited[x + 1] = visited[x] + 1;
        }
        if (2 * x < mval && visited[2 * x]>visited[x])
        {
            q.push(2 * x);
            visited[2 * x] = visited[x];
        }

    }
    return;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < mval; i++)
        visited[i] = INF;
    dfs();
    cout << cnt << endl;
}
