#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

char db[1000][1000];
bool visited[1000][1000];
int dx[4] = {0, 0, 1,-1};
int dy[4] = {1, -1, 0, 0};
int n, m;

bool check()
{
    for(int i=n-1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(db[i][j]=='0' && visited[i][j])
                return true;
        }
    }
    return false;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m)
            {
                if(!visited[nx][ny] && db[nx][ny]=='0')
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    
}


int main()
{

 string str;
 cin>>n>>m;
 int x, y;
 bool flag = true;
 queue<pair<int, int>> q;
 for(int i=0;i<n;i++)
 {
	cin>>str;
	for(int j=0;j<m;j++)
	{
	    db[i][j] = str[j];
	    if(i==0 && str[j]=='0')
	    {
	       q.push({i,j});
	    }
	}
 }
 
while(!q.empty())
{
    auto it = q.front();
    q.pop();
    bfs(it.first, it.second);
}

if(check())
    cout<<"YES\n";
else
    cout<<"NO\n";
 
 
	
}
