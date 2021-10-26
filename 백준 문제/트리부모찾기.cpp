#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <tuple>
#include <list>

using namespace std;

bool visited[100001];
int parent[100001];
vector<int> adj[100001];

void find_parent(int node)
{
    visited[node] = true;
    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            parent[i] = node;
            find_parent(i);
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin>>n;
	
	for(int i=1;i<=n-1;i++)
	{
	    int a,b;
	    cin>>a>>b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	    
	}
	
	
	find_parent(1);
	
	for(int i=2;i<=n;i++)
	    cout<<parent[i]<<'\n';
	    
	return 0;
	
	
}
