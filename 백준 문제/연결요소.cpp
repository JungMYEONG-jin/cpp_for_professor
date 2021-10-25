#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void bfs(vector<int>* adj, bool* visited, int n)
{
	visited[n] = true;
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		int idx = q.front();
		q.pop();
		for(auto i : adj[idx])
		{
			if(!visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
			
		}
		
	}
	return;
	
}


int main()
{
	int n, v;
	cin>>n>>v;
	vector<int> adj[n+1];
	int x, y;
	bool visited[n+1];
	memset(visited, false, sizeof(visited));
	for(int i=0;i<v;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		
	}
	
	
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i])
			continue;
		bfs(adj,visited, i);
		ans++;
	}
	cout<<ans<<endl;
	
	
}
