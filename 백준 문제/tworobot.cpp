#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>
#include <set>
#include <map>

#define INF 999999999

using namespace std;

vector<pair<int,int>> graph[100001];
bool visited[100001];

void bfs(int x, int y)
{
    //x start y end
    memset(visited, false, sizeof(visited));
    queue<tuple<int, int, int>> q;
    q.push({x, 0, 0});
    visited[x] = true;
    
    while(!q.empty())
    {
        auto it = q.front();
        int cur, cost, mval;
        tie(cur, cost, mval) = it;
        q.pop();
        
        if(cur==y)
        {
            cout<<cost-mval<<endl;
            break;
        }
        
        for(const auto& it : graph[cur]) // end cost
        {
            if(!visited[it.first])
            {
                visited[it.first] = true;
                q.push({it.first, it.second+cost, max(it.second, mval)});
            }
        }
    }
}




int main()
{
    int n, s, e;
    cin>>n>>s>>e;
    for(int i=0;i<n-1;i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    
    bfs(s, e);
    
    return 0;
    
    
}




