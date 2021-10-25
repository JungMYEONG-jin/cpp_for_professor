#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;


int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main()
{
	int n;
	cin>>n;
	set<int> res;
	vector<vector<int>> db(n, vector<int>(n,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>db[i][j];
			res.insert(db[i][j]);
		}
		
	}
	//auto it_last = prev(res.end());
	//res.erase(it_last); // 가장 마지막 원소는 삭제

	vector<int> total;
	int mval = 1;
	bool visited[100][100];
	
	
	for(auto it : res) // brute force
	{
		memset(visited, false ,sizeof(visited));
		total.clear();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!visited[i][j] && db[i][j]>it)
				{
					queue<pair<int, int>> q;
					q.push({i,j});
					visited[i][j] = true;
					int cnt=0;
					while(!q.empty())
					{
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						cnt++;
						for(int d=0;d<4;d++)
						{
							int nx = x+dx[d];
							int ny = y+dy[d];
							if(nx>=0 && nx<n && ny>=0 && ny<n)
							{
								if(!visited[nx][ny] && db[nx][ny]>it)
								{
									visited[nx][ny] = true;
									q.push({nx, ny});
								}
								
							}
							
						}
						
						
						
					}
					total.push_back(cnt);
				}
			}
		}
		mval = max(mval, static_cast<int>(total.size()));
		
	}
	
	cout<<mval<<endl;
	
}
