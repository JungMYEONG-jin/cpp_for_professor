# 벨만포드 알고리즘은 negative일때도 가능
# 맨 마지막 단계에 edge의 개수만큼 다시 repeat하여 만약 최소가 되는 거리가 존재시 음의 cycle이 존재한다는것.


```c++

#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <stack>

#define inf INT_MAX

using namespace std;

struct Edge
{
	int from, to, weight;
};

struct Graphs {
	int V, E;

	struct Edge* edge;
};

struct Graphs* createGraph(int V, int E)
{
	struct Graphs* graph = new Graphs;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
};

void BellmanFord(struct Graphs* graph, int start)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	fill(dist, dist + V, inf);
	dist[start] = 0;

	for (int i = 1; i <= V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int from = graph->edge[j].from;
			int to = graph->edge[j].to;
			int weight = graph->edge[j].weight;

			if (dist[from] != inf && dist[from] + weight < dist[to])
			{
				dist[to] = dist[from] + weight;
			}
		}
	}

	// 마지막으로 negative가 있는지 체크

	for (int i = 0; i < E; i++)
	{
		int from = graph->edge[i].from;
		int to = graph->edge[i].to;
		int weight = graph->edge[i].weight;
		if (dist[from] != inf && dist[from] + weight < dist[to])
		{
			cout << "음의 사이클이 존재합니다!\n";
			return;
		}
	}

	for (int i = 0; i < V; i++)
		cout << i << " " << dist[i]<<'\n';

	return;

}













int main()
{

	int V, E;
	cin >> V >> E;

	struct Graphs* graph = createGraph(V, E);

	for (int i = 0; i < E; i++)
	{
		cin >> graph->edge[i].from >> graph->edge[i].to >> graph->edge[i].weight;
	}

	BellmanFord(graph, 0);

	return 0;


}




```
