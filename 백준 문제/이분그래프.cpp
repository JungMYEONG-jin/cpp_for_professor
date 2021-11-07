#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>
#include <list>

using namespace std;
typedef enum class color { Red, Blue, Default };
int visited[20001];
list<int> adj[20001];
int v, e;
bool is_bi()
{
    for (int i = 1; i <= v; i++)
    {
        for (auto next : adj[i]) // 인접 정점과 같으면 false임
        {
            if (visited[i] == visited[next])
                return false;
        }
    }
    return true;
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    int temp = 1;
    visited[x] = temp;
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        if (visited[cur] == 1) // red
        {
            temp = 2; // blue
        }
        else if (visited[cur] == 2) // blue
        {
            temp = 1; // red
        }
        for (auto i : adj[cur])
        {
            if (visited[i] == 0) // not visited
            {
                visited[i] = temp;
                q.push(i);
            }
        }
            
    }
}


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        
        cin >> v >> e;
        memset(visited, 0, sizeof(visited)); // init
        for (int i = 0; i <= v; i++)
            adj[i].clear();
        for (int i = 0; i < e; i++)
        {
            int l, r;
            cin >> l >> r;
            adj[l].push_back(r);
            adj[r].push_back(l);
        }

        for (int i = 1; i <= v; i++)
        {
            if (visited[i] == 0) // not visited
            {
                bfs(i);
            }
        }

        if (is_bi())
            cout << "YES\n";
        else
            cout << "NO\n";

        

    }
    
}
