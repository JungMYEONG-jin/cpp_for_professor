#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <tuple>


#define INF 999999999

using namespace std;

bool visited[50][50];
char db[50][50];
int water[50][50];
int n, m;
int dx[4] = { 1,-1, 0,0 };
int dy[4] = { 0,0,1,-1 };

int sx, sy; // 고슴도치
int ex, ey; // 비버

bool is_valid(int x, int y)
{
	if (x >= 0 && y >= 0 && x < n && y < m)
		return true;
	return false;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            water[i][j] = INF;
    }
    
    string str;
    queue<pair<int, int>> wq;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        for(int j=0;j<m;j++)
        {
            db[i][j] = str[j];
            if (db[i][j] == 'D')
			{
				ex = i;
				ey = j;
			}
			else if (db[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			else if (db[i][j] == '*')
			{
				wq.push({ i, j });
				water[i][j] = 0;
			}
        }
    }
    
    while(!wq.empty())
    {
        int len = wq.size();
        for(int i=0;i<len;i++)
        {
            auto it = wq.front();
            wq.pop();
            int x = it.first;
            int y = it.second;
            for(int k=0;k<4;k++)
            {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(is_valid(nx, ny))
                {
                    if(db[nx][ny]=='.' && water[nx][ny]>water[x][y]+1)
                    {
                        water[nx][ny] = water[x][y]+1;
                        wq.push({nx, ny});
                    }
                }
            }
        }
        
    }
    
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 0});
    visited[sx][sy] = true;
    bool flag = false;
    while(!q.empty())
    {
        int x, y, cnt;
        tie(x,y,cnt) = q.front();
        q.pop();
        if(x==ex && y==ey)
        {
            flag = true;
            cout<<cnt<<endl;
            break;
        }
        
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(is_valid(nx, ny))
            {
                if(!visited[nx][ny] && db[nx][ny]!='X' && water[nx][ny]>cnt+1)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, cnt+1});
                }
            }
        }
        
        
    }
    
    if (!flag)
		cout << "KAKTUS" << endl;
    
    
    
    
    
}




