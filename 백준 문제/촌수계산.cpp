#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

bool visited[101];
int parent[101];
vector<int> adj[101];
queue<pair<int, int>> q;

int n;
int s, e;
int num;

int bfs(int node)
{
    visited[node] = true;
    q.push({ node, 0 });
    while (!q.empty())
    {
        int temp = q.front().first;
        int dist = q.front().second;
        q.pop();
        for (auto i : adj[temp])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push({ i,dist + 1 });
                if (i == e)
                    return dist + 1;
            }
        }
    }
    return -1;
}


int main()
{
   
    cin >> n;
    cin >> s >> e;
    cin >> num;


    for (int i = 0; i < num; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << bfs(s) << endl;;
    




}
