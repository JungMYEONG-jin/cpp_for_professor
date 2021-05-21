# graph 알고리즘

1. BFS란 무엇인가?
2. FIFO queue를 이용해 주변 vertices를 search하는 알고리즘이다.
3. Line 상반기 마지막 문제 트리 구조의 문제였음.
4. BFS는 트리 구조에 사용할 수 있어 준비해야함.



```c++
#include <vector>
#include <iostream>
#include <list>
#include <queue>

using namespace std;


// BFS 다시 방문하지 않기 위해 방문 표시를 해주자
class Graph
{
	int V;
	// pointer to an array containing adjacency

	list<int>* adj;
public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}

	void addEdge(int v, int w)
	{
		adj[v].push_back(w);

	}
	
	void bfs(int s)
	{
		vector<bool> visited(V, false);
		// 초기 방문 X

		queue<int> que;

		visited[s] = true;
		que.push(s);

		while (!que.empty())
		{

			// dequeue a vertex from queue and print it
			s = que.front();
			cout << s << " ";
			que.pop();

			// get all adjacent vertices of the dequeued
			// vertex s If a adjacent has not been visited
			// then mark it visited and push it to the queue

			for (auto i : adj[s]) // s의 인접 vertices
			{
				if (!visited[i])
				{
					visited[i] = true;
					que.push(i);
				}
			}




		}

	}
};



void addEdge(vector<int> arr[], int u, int v)
{
	arr[u].push_back(v);
	arr[v].push_back(u);
}

int main()
{
	int V = 13;
	Graph g(V);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 5);
	g.addEdge(0, 6);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(7, 8);
	g.addEdge(9, 10);
	g.addEdge(9, 11);
	g.addEdge(9, 12);
	g.addEdge(11, 12);

	g.bfs(4);

}

```
