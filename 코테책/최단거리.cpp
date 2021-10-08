#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int n, m, start;

vector<pair<int, int>> graph[100001];

int d[100001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start }); // start = 0
	d[start] = 0; //min distance 0

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// 이미 처리된 노드라면 무시
		if (d[cur] < dist)
			continue;
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int cost = dist + graph[cur][i].second;
			if (cost < d[graph[cur][i].first])
			{
				d[graph[cur][i].first] = cost;
				pq.push({ cost, graph[cur][i].first });
			}
		}



	}

}


int main()
{
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		// a to b cost is c

	}

	fill(d, d + 100001, 987654321);

	dijkstra(start);

	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 987654321)
			cout << "Not exist" << endl;
		else
			cout << d[i] << endl;
	}




}
