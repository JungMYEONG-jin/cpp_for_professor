/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[101];
bool visited[101];

int main()
{
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    map<int, int> db;
    for(int i=1;i<=n;i++)
    {
        queue<pair<int, int>> q;
        q.push({i,0}); // 본인은 0
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int cur = it.first;
            int dist = it.second;
            for(auto next : adj[cur])
            {
                if(!visited[next])
                {
                    q.push({next, dist+1});
                    visited[next] = true;
                    db[i]+=(dist+1);
                }
                
            }
        
        }
    }
    auto it = min_element(db.begin(), db.end(), [](auto e, auto k){return e.second<k.second;});
    cout<<it->first<<endl;
    
}
