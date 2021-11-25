#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <tuple>
#include <set>


#define INF 999999999

using namespace std;


int n, m;
int dx[4] = { 1,-1, 0,0 };
int dy[4] = { 0,0,1,-1 };

int mx, my; // my start position
set<pair<int, int>> escape; // escape position

bool is_valid(int x, int y)
{
	if (x >= 0 && y >= 0 && x < n && y < m)
		return true;
	return false;
}

void solve()
{
   bool visited[1000][1000];
   char db[1000][1000];
   int fire[1000][1000];

   memset(visited, false, sizeof(visited));
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            fire[i][j] = INF;
    }
    
    string str;
    queue<pair<int, int>> fq;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        for(int j=0;j<m;j++)
        {
            db[i][j] = str[j];
            
			   if(db[i][j] == '@')
			   {
			   	mx = i;
			   	my = j;
			   }
			   else if (db[i][j] == '*')
			   {
			   	fq.push({ i, j });
			   	fire[i][j] = 0;
			   }
        }
    }
    
    while(!fq.empty())
    {
        int len = fq.size();
        for(int i=0;i<len;i++)
        {
            auto it = fq.front();
            fq.pop();
            int x = it.first;
            int y = it.second;
            for(int k=0;k<4;k++)
            {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(is_valid(nx, ny))
                {
                    if(db[nx][ny]=='.' && fire[nx][ny]>fire[x][y]+1)
                    {
                        fire[nx][ny] = fire[x][y]+1;
                        fq.push({nx, ny});
                    }
                }
            }
        }
        
    }
    

    queue<tuple<int, int, int>> q;
    q.push({mx, my, 0});
    visited[mx][my] = true;
    bool flag = false;
    while(!q.empty())
    {
        int x, y, cnt;
        tie(x,y,cnt) = q.front();
        q.pop();
        
        if(x==0 || y==0 || x==n-1 || y==m-1)
        {
            cout<<cnt+1<<endl;
            return;
        }
        
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(is_valid(nx, ny))
            {
                if(!visited[nx][ny] && db[nx][ny]!='#' && fire[nx][ny]>cnt+1)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, cnt+1});
                }
            }
        }
        
        
    }
    
    if (!flag)
		cout << "IMPOSSIBLE\n";
    return;
}


int main()
{
    
 int t;
 cin>>t;
 while(t)
 {
    solve();
    t--;
 }
    
}





