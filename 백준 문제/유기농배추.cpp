#include <queue>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main()
{
    int t;
    cin>>t;
    int m, n, k;
    for(int i=0;i<t;i++)
    {
        cin>>m>>n>>k;
        int db[m][n];
        bool visited[m][n];
        memset(db, 0, sizeof(db));
        memset(visited, false, sizeof(visited));
        int x, y;
        vector<int> res;
        for(int j=0;j<k;j++)
        {
            cin>>x>>y;
            db[x][y] = 1;
        }
        
        for(int p=0;p<m;p++)
        {
            for(int q=0;q<n;q++)
            {
                if(!visited[p][q] && db[p][q]==1)
                {
                    visited[p][q] = true;
                    queue<pair<int, int>> qq;
                    qq.push({p,q});
                    int cnt=0;
                    while(!qq.empty())
                    {
                        int xx = qq.front().first;
                        int yy = qq.front().second;
                        qq.pop();
                        cnt++;
                        for(int d=0;d<4;d++)
                        {
                            int nx = xx+dx[d];
                            int ny = yy+dy[d];
                            if(nx>=0 && nx<m && ny>=0 && ny<n)
                            {
                            if(db[nx][ny]==1 && visited[nx][ny]==false)
                            {
                                db[nx][ny]=0;
                                visited[nx][ny]=true;
                                qq.push({nx, ny});
                            }
                            }
                        }
                    }
                    res.push_back(cnt);
                    
                    
                }
            }
        }
        cout<<res.size()<<endl;
        
        
    }
    
    
    
    
    
    return 0;
    
}

// 2번째 풀이

#include <queue>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int db[50][50];
bool visited[50][50];
int cnt;
int t;
int m, n, k;
void dfs(int x, int y)
{
    visited[x][y] = true;
    cnt++;
    for(int i =0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx<m && ny>=0 && ny<n)
        {
            if(db[nx][ny]==1 && !visited[nx][ny])
                dfs(nx, ny);
        }
    }
}


int main()
{
    
    cin>>t;
   
    for(int i=0;i<t;i++)
    {
        cin>>m>>n>>k;
        memset(db, 0, sizeof(db));
        memset(visited, false, sizeof(visited));
        int x, y;
        vector<int> res;
        for(int j=0;j<k;j++)
        {
            cin>>x>>y;
            db[x][y] = 1;
        }
        
        for(int p=0;p<m;p++)
        {
            for(int q=0;q<n;q++)
            {
                if(!visited[p][q] && db[p][q]==1)
                {
                    cnt=0;
                    dfs(p,q);
                    res.push_back(cnt);
                }
                   
            }
        }
        cout<<res.size()<<endl;
        
        
    }
    
    
    
    
    
    return 0;
    
}
