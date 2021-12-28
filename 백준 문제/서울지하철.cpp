#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;


vector<int> graph[3001];
bool visited[3001];
bool cycle_station[3001];
bool cycle;



void dfs(int cur, int start, int num)
{
    if(cur==start && num>=2)
    {
        cycle = true;
        return;
    }
    
    visited[cur] = true;
    for(auto line : graph[cur])
    {
        if(!visited[line])
        {
            dfs(line, start, num+1);
        }else
        {
            if(line==start && num>=2)
            {
                dfs(line, start, num);
            }
        }
    }
    
    
    if(cycle)
    {
        return;
    }
}

int bfs(int x)
{
    memset(visited, false, sizeof(visited));
    visited[x] = true;
    queue<pair<int, int>> q;
    q.push({x, 0});
    
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int cur = it.first;
        int cnt = it.second;
        
        if(cycle_station[cur])
        {
            return cnt;
        }
        
        
        for(auto num : graph[cur])
        {
            if(!visited[num])
            {
                visited[num] = true;
                q.push({num, cnt+1});
            }
        }
        
        
        
    }
    
    
    
}


int main()
{
    int n;
    cin>>n;
    int a, b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    
    for(int i=1;i<=n;i++)
    {
        cycle = false;
        memset(visited, false, sizeof(visited));
        dfs(i, i, 0);
        if(cycle)
        {
            cycle_station[i] = true;
        }
    }
    vector<int> res;
    for(int i=1;i<=n;i++)
    {
        if(cycle_station[i])
        {
            res.push_back(0);
            continue;
        }
        res.push_back(bfs(i));
    }
    
    for(auto i : res)
        cout<<i<<" ";
    
    
}
