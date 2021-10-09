#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#define INF 999999999

using namespace std;

vector<pair<int, int>> graph[1000001];

int d[1000001];


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
		
		for (auto i : graph[cur])
		{
			int cost = i.second + dist;
			if (cost < d[i.first])
			{
				d[i.first] = cost;
				pq.push({ cost, i.first });
			}
		}



	}

}


int main()
{
	int n, m, c;
	cin >> n >> m >> c;

	
	fill(d, d + 1000001, INF);
	int start, end, weight;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end, weight });
	}

	dijkstra(c);

	int cnt = 0;
	int maxVal = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] != INF)
		{
			cnt++;
			maxVal = max(maxVal, d[i]);
		}
	}
	cout << cnt - 1 << " " << maxVal << endl;
}
