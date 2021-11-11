#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;

bool visited[MAX];
queue<pair<int, int>> q;
int n, k, cnt, min_time;

void bfs()
{
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int cur = it.first;
        int cur_time = it.second;
        
        visited[cur] = true;
        
        if(min_time && min_time==cur_time && cur==k)
            cnt++;
        if(min_time==0 && cur==k)
        {
            min_time = cur_time;
            cnt++;
        }
        
        if(cur-1>=0 && !visited[cur-1])
            q.push({cur-1, cur_time+1});
        if(cur+1<MAX && !visited[cur+1])
            q.push({cur+1, cur_time+1});
        if(2*cur<MAX && !visited[2*cur])
            q.push({2*cur, cur_time+1});
        
        
        
        
    }
    
    
    
}

int main()
{
    cin>>n>>k;
    q.push({n,0});
    visited[n] = true;
    bfs();
    cout<<min_time<<'\n'<<cnt;
       
}
