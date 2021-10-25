#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[8] = {-1,0,1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};


int main()
{
	int w, h;
	vector<int> result;
	int cnt = 0;
	vector<int> total;
	while(true)
	{
		
		cin>>w>>h;
		if(w==0 && h==0)
			break;
		int db[h][w];
		bool visited[h][w];
		memset(db, 0, sizeof(db));
		memset(visited, false, sizeof(visited));
		result.clear();
		queue<pair<int, int>> q;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cin>>db[i][j]; // 0 sea 1 land
			}
		}
		
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
			  if(!visited[i][j] && db[i][j]==1)
			  {
				  visited[i][j] = true;
				  //db[i][j]=0;
				  q.push({i,j});
				  cnt=0;
				  while(!q.empty())
				  {
					  int x = q.front().first;
					  int y = q.front().second;
					  q.pop();
					  cnt++;
					  for(int d=0;d<8;d++)
					  {
						  int nx = x+dx[d];
						  int ny = y+dy[d];
						  
						  if(nx>=0 && nx<h && ny>=0 && ny<w)
						  {
							  if(!visited[nx][ny] && db[nx][ny]==1)
							  {
								  visited[nx][ny] = true;
								  db[nx][ny] = 0;
								  q.push({nx,ny});
								  
							  }
							  
						  }
						  
					  }
					  
					  
				  }
				 
				  
				  result.push_back(cnt);
			  }
				
			}
			
			
		}
		int num = count_if(result.begin(), result.end(), [](auto e){return e>0;});
		total.push_back(num);
		
	}

	for(auto i : total)
		cout<<i<<endl;
	
	return 0;
	
	
	
	
	
	
	
}
