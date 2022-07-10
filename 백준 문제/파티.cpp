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

int dist[1001];
int result[1001];
vector<pair<int, int>> arr[1001];
int n, m, r, x;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


bool isValid(int x, int y) {
	if (x >= 0 && y >= 0 && x < m && y < n)
		return true;
	return false;
}

void dijkstra(int pos) {

	fill(dist, dist + 1001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[pos] = 0;
	pq.push({ 0, pos });

	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		int cur = it.second;
		int w = it.first;

		for (auto it2 : arr[cur]) {
			int next = it2.first;
			int nextW = it2.second;

			if (dist[next] > w + nextW) {
				dist[next] = w + nextW;
				pq.push({ w + nextW, next });
			}
		}
	}

}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> x;
	int start, end, cost;
	for (int i = 0; i <m; i++) {
		cin >> start >> end >> cost;
		arr[start].push_back({ end, cost });
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i); // 각 마을에서 x로 가는 최단거리 구함
		result[i] = dist[x]; // 
	}


	dijkstra(x);
	int maxTime = -1;
	for (int i = 1; i <= n; i++) {
		result[i] += dist[i]; // x에서 각 마을 최단거리
		maxTime = max(maxTime, result[i]);
	}


	cout << maxTime << endl;



	
	return 0;

}
