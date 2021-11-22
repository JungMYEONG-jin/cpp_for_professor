#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

bool visited[200][200][31]; // count
int db[200][200];
int k;
int w, h;

int dx[12] ={1,-1,0,0};
int dy[12] ={0,0,1,-1};

int hx[8] = {-1,-2,-2,-1,1,2,2,1};
int hy[8] = {-2,-1,1,2,-2,-1,1,2};


bool is_valid(int x, int y)
{
	if(x>=0 && x<h && y>=0 && y<w)
		return true;
	return false;
}


int main()
{
	cin>>k;
	cin>>w>>h;

	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			cin>>db[i][j];
	}

	queue<tuple<int, int, int, int>> q; // x y count like horse
	q.push({0,0,0, 0});
	int ans = -1;
	visited[0][0][0] = true;
	while(!q.empty())
	{
		auto it = q.front();
		q.pop();
		int x, y, cnt, hmove;
		tie(x,y,cnt, hmove) = it;

		if(x==h-1 &&y==w-1) // arrive at final stage
		{
			ans = cnt;
			break;
		}

		if(hmove<k)
		{
			for(int i=0;i<8;i++)
			{
				int nx = x+hx[i];
				int ny = y+hy[i];
				if(is_valid(nx, ny))
				{
					if(!visited[nx][ny][hmove+1] && db[nx][ny]==0)
					{
						q.push({nx, ny, cnt+1, hmove+1});
						visited[nx][ny][hmove+1] = true;
					}
				}
			}


		}
		
		for(int i=0;i<4;i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(is_valid(nx, ny))
			{
				if(!visited[nx][ny][hmove] && db[nx][ny]==0)
				{
					q.push({nx, ny, cnt+1, hmove});
					visited[nx][ny][hmove] = true;
				}
			}			
        }
		
	}


	cout<<ans<<endl;



}
