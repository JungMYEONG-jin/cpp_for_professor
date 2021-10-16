#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    vector<string> res;
    int n,m;
    cin>>n>>m;
    string temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        res.push_back(temp);
    }
    
    int db[n][m];
    bool visited[n][m];
    int dist[n][m];
    memset(db, 0, sizeof(db));
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            db[i][j] = res[i][j]-'0';
        }
    }
    
    queue<pair<int, int>> q;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    q.push({0,0});
    visited[0][0] = true;
    dist[0][0]=1;
    
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n &&ny>=0 &&ny<m)
            {
                if(visited[nx][ny]==false && db[nx][ny]==1)
                {
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                    dist[nx][ny] = dist[x][y]+1;
                }
            }
        }
    }
    
    cout<<dist[n-1][m-1]<<endl;
    
    
    
    
    
    
    
    
}
