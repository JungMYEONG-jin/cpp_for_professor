#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>

#define INF 999999999

using namespace std;

int n, k, r;
int db[101][101];
bool visited[101][101];
vector<pair<int, int>> adj[101][101];
pair<int, int> cows[101];
int reach[101][101]; // 만남 유무
int dx[] = { 1,-1,0,0 };
int dy[] = { 0, 0, 1, -1 };


void bfs(int idx)
{
    int x = cows[idx].first;
    int y = cows[idx].second;
    
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        
        x = it.first;
        y = it.second;
        
        if(db[x][y]!=0)
            reach[idx][db[x][y]] = 1;
        
        if(adj[x][y].empty())
        {
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx>=1 && ny>=1 && nx<=n && ny<=n)
                {
                    if(!visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                
            }

        }else
        {
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                bool banned = false;
                
                for(auto it : adj[x][y])
                {
                    if(nx==it.first && ny==it.second)
                        banned = true;
                }
                
                if(banned)
                    continue;
                
                if(nx>=1 && ny>=1 && nx<=n && ny<=n)
                {
                    if(!visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
               
            }
        }
        
        
    }
    
    
    
    
}


int main()
{
	cin >> n >> k >> r;

	int x, y, x2, y2;
	for (int i = 1; i <= r; i++)
	{
		cin >> x >> y >> x2 >> y2;
		adj[x][y].push_back({ x2, y2 });
		adj[x2][y2].push_back({ x, y });
	}
	
	for (int i = 1; i <= k; i++)
	{
		cin >> cows[i].first >> cows[i].second;
		db[cows[i].first][cows[i].second] = i; // 소 번호

	}

	for (int i = 1; i <= k; i++)
	{
		memset(visited, false, sizeof(visited));
		bfs(i);
	}

	int ans = 0;

	for (int i = 1; i <= k; i++)
	{
		for (int j = i+1; j <= k; j++)
		{
			if (reach[i][j] == 0)
				ans++;
		}
	}

	cout << ans << endl;

}



