#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <set>
#include <numeric>
#include <cmath>
#include <stack>

#define INF 1000000000

using namespace std;

vector<int> station[100001];
vector<int> route[100001];

bool visited[100001];
int dist[100001];
int start, last;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	dist[start] = -1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		// 몇호선인지?
		for (int line : station[cur]) {
			if (visited[line])
				continue;
			visited[line] = true;
			for (int next : route[line]) {
				// 역 탐방
				if (dist[next] == INF) {
					dist[next] = dist[cur] + 1;
					q.push(next);
				}
			}

		}
	}
	dist[start] = 0;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	int idx = 1;
	while (m--) {
		int num;
		while (true) {
			cin >> num;
			if (num == -1)
				break;
			route[idx].push_back(num); // 2호선을 지나는역들
			station[num].push_back(idx); // 홍대역은 2호선 경의중앙선
		}
		idx++;
	}

	fill(dist, dist + 100001, INF);

	cin >> start >> last;
	bfs(start);
	if (dist[last] == INF)
		cout << -1 << endl;
	else
		cout << dist[last] << endl;


    return 0;

}
// 2335
