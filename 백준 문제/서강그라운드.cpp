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

int dist[101];
int item[101];
vector<pair<int, int>> arr[101];
int n, m, r;

void getMaxItem(int start) {
	
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	int cnt = 0;
	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		int w = it.first;
		int cur = it.second;
	
		for (auto it2 : arr[cur]) {
			int next = it2.first;
			int nextW = it2.second;

			if (dist[next] > w + nextW)
			{
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

	// 1~n 까지 완전탐색 ㄱㄱ
	
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	int x, y, cost;
	for (int i = 0; i < r; i++) {
		cin >> x >> y >> cost;
		arr[x].push_back({ y, cost });
		arr[y].push_back({ x, cost });
	}

	int val = 0;
	for (int i = 1; i <= n; i++) {
		fill(dist, dist + 101, INF);
		getMaxItem(i);
		int total = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[j] <= m)
				total += item[j];
		}
		val = max(val, total);
	}

	cout << val << endl;



	
	return 0;

}
