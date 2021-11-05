#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>


using namespace std;


int db[50][50];
bool visited[50][50];
int n, l, r;

int dx[4] = {1,-1,0,0};
int dy[4] = {0, 0, 1, -1};

using namespace std;


int main()
{
    
    cin>>n>>l>>r;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>db[i][j];
    }
    
    
    int cnt = 0;
    bool flag = true;
    while(flag)
    {
        flag =false;
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!visited[i][j])
            {
                queue<pair<int, int>> q;
                q.push({i,j});
                vector<pair<int, int>> res;
                visited[i][j] = true;
                while(!q.empty())
                {
                    auto it = q.front();
                    int x = it.first;
                    int y = it.second;
                    q.pop();
                    res.push_back({x,y});
                    for(int k = 0;k<4;k++)
                    {
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        int diff = abs(db[x][y]-db[nx][ny]);
                        if(nx>=0 && ny>=0 && nx<n && ny<n)
                        {
                            if(!visited[nx][ny] && diff>=l && diff<=r)
                            {
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                    
                    
                }
                if(res.size()>1)
                {
                    int total = 0;
                    for(auto& i : res)
                    {
                        total+=db[i.first][i.second];
                    }
                    
                    total/=(static_cast<int>(res.size()));
                    for(auto& i : res)
                    {
                        db[i.first][i.second] = total;
                    }
                    
                    flag = true;
                    //memset(visited, false, sizeof(visited));
                }
                
                
                
            }
            
        }
     }
     if(flag)
         cnt++;
     memset(visited, false, sizeof(visited));
    }
    
    
    cout<<cnt<<endl;
    
    
    
    
    
    
}
