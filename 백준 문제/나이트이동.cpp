#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <tuple>

using namespace std;

int dx[8] = {1,-1,2,-2,2,-2,1,-1};
int dy[8] = {-2,-2,-1,-1,1,1,2,2};
bool visited[300][300];
int dist[300][300];

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
        memset(visited, false, sizeof(visited));
        memset(dist, 0 ,sizeof(dist));
		//int db[n][n];
		//bool visited[n+1][n+1];
		int a, b, c, d;
		cin>>a>>b;
		cin>>c>>d;
		queue<pair<int, int>> q;
		q.push({a,b});
		visited[a][b] = true;
		dist[a][b]=0;
		while(!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if(x==c && y==d)
			{
                cout<<dist[x][y]<<endl;
				break;
			}
			
			for(int k=0;k<8;k++)
			{
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=0 && ny>=0 && nx<n && ny<n)
				{
					if(!visited[nx][ny])
					{
						visited[nx][ny]=true;
						q.push({nx,ny});
						dist[nx][ny] = dist[x][y]+1;
					}
					
				}
				
			}
			
		}

		
		
	}
	
	
}
