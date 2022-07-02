#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>

#define INF 999999999

using namespace std;

int times[360000]; // hour to sec

int start, dest;

long long dist[1001];
int graph[1001][1001];
int navi[1001];


void dijkstra(int start, int busNum) {
	
	fill(dist, dist + 1001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	
	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		int cur = it.second;
		int w = it.first;
		

		for (int i = 1; i <= busNum; i++) {
			int next = i;
			int nextW = graph[cur][i];

			if (nextW == INF)
				continue;
			long long sum = nextW + w;
			if (sum < dist[next]) {
				dist[next] = sum;
				pq.push({ nextW + w, next });
				navi[next] = cur;
			}
		}
	}


}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int x, y, cost;
	vector<int> answer;
	

	for (int i = 1; i <= n; i++)
	{
		fill(graph[i], graph[i] + 1001, INF);
		graph[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> cost;
		if (graph[x][y] > cost)
			graph[x][y] = cost;
	}

	
	cin >> start >> dest;
	dijkstra(start, n);

	cout << dist[dest] << endl;
	int idx = dest;
	
	while (idx != start) {
		answer.push_back(idx);
		idx = navi[idx];
	}
	answer.push_back(idx);
	reverse(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int path : answer)
		cout << path << " ";


	
	return 0;

}
