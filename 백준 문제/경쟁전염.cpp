#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m, s, x, y;
int dx[4] = {-1,0,1,0};
int dy[4] = {0, 1, 0, -1};

vector<tuple<int, int, int, int>> vs;

int db[202][202];

void bfs()
{
    if(s==0)
    {
        return;
    }
    
    queue<tuple<int, int, int, int>> q;
    for(auto& it : vs)
        q.push(it);
    
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int xx, yy, t, val;
        tie(xx, yy, t, val) = it;
        if(t==s)
            break;
        for(int i=0;i<4;i++)
        {
           int nx = xx+dx[i];
           int ny = yy+dy[i];
           if(nx>=1 && nx<=n && ny>=1 && ny<=n)
           {
               if(db[nx][ny]==0)
               {
                   db[nx][ny] = val;
                   q.push({nx, ny, t+1, val});
               }
           }
        }
        
    }
    return;
}



int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>db[i][j];
            if(db[i][j]>0)
                vs.push_back({i,j,0,db[i][j]});
        }
    }
    
    sort(vs.begin(), vs.end(), [](auto e, auto k){return get<3>(e)<get<3>(k);});
    
    
    cin>>s>>x>>y;
    bfs();
    if(db[x][y]>0)
        cout<<db[x][y]<<endl;
    else
        cout<<0<<endl;
    
}
