# dfs 재귀버전

1. 방문을 나타내는 변수를  추가해 backtracking처럼 하면된다.

```c++
#include <vector>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class Graph
{
public:
	map<int, bool> visited;
	map<int, list<int>> adj;

	void dfs(int s)
	{
		visited[s] = true;
		cout << s << " ";
		for (auto i : adj[s])
			if (!visited[i])
				dfs(i);
	}

	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

};


int main()
{

	Graph g;
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 3);
	g.addEdge(4, 5);
	int num = 0;
	for (int i = 1; i <= 6; i++)
	{
		if (!g.visited[i])
		{
			g.dfs(i);
			num++;
		}
		cout << endl;
	}
	cout << endl;
	cout << num << endl;
}


```

```
해당 코드를 실행하면 1,2,3  4,5  6 이렇게 총 3개의 connected components가 존재하게 되므로 3개가 나오고 각 component의 원소가 출력된다.

```
