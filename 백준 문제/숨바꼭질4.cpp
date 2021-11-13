#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX 100001

using namespace std;

bool visited[MAX];
queue<pair<int, int>> q;
vector<int> db;
int path[MAX];
int n, k, ttime, ans_idx;

void bfs()
{

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int cur = it.first;
        int cur_time = it.second;
        
        if(cur==k)
        {
            ttime = cur_time;
            ans_idx = cur;
            while(ans_idx!=n)
            {
                db.push_back(ans_idx);
                ans_idx = path[ans_idx];
            }
            db.push_back(n);
            return;
        }
        
        if(cur-1>=0 && !visited[cur-1])
        {
           
            q.push({cur-1, cur_time+1}); 
            visited[cur-1] = true;
            path[cur-1] = cur;
        }
        if(cur+1<MAX && !visited[cur+1])
        {
      
            q.push({cur+1, cur_time+1});
            visited[cur+1] = true;
            path[cur+1] = cur;
        }
        if(2*cur<MAX && !visited[2*cur])
        {
            q.push({2*cur, cur_time+1});
            visited[2*cur] = true;
            path[2*cur] = cur;
        }
    
    }
    return ;
}

int main()
{
    
    cin>>n>>k;
    q.push({n, 0});
    visited[n] = true;
    bfs();
    cout<<ttime<<endl;
    reverse(db.begin(), db.end());
    for(const auto i : db)
        cout<<i<<" ";
    
    
}
