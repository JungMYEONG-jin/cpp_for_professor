> 간단한 다익스트라 문제. 나는 최소거리, x좌표, y좌표를 tuple로 구성하여 우선순위큐를 작성함
> 유효하면서 이전에 방문기록이 없으며 건설하지 못하는(-1)이 아니면 체크를 시작하기로 함
> 현재거리에 다음 좌표의 거리를 더한걸 다음 거리와 비교하며 최단 거리 구함



``` c++

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
int graph[1000][1000];
int dist[1000][1000];
bool visited[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<pair<int, int>> arr[201];
int n, m, A, B, C;
int answer = 0;

bool isValid(int x, int y);

void dijkstra(int start) {
	
	for (int i = 0; i < n; i++)
	{
		fill(visited[i], visited[i] + 1000, false);
		fill(dist[i], dist[i] + 1000, INF);
	}
	if (graph[0][0] == -1)
		return;

	visited[0][0] = true;
	dist[0][0] = graph[0][0];

	priority_queue < tuple<int, int, int>, vector < tuple<int, int, int>>, greater < tuple<int, int, int>>> pq;
	pq.push({ dist[0][0],0, 0 });

	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		int cost, x, y;
		tie(cost, x, y) = it;

		if (x == n - 1 && y == m - 1)
			return;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isValid(nx, ny) && !visited[nx][ny] && graph[nx][ny] != -1) {
				// 유효하며 방문하지 않았고 갈수없는곳이 아님
				dist[nx][ny] = min(dist[x][y] + graph[nx][ny], dist[nx][ny]);
				visited[nx][ny] = true;
				pq.push({ dist[nx][ny], nx, ny });
			}
		}
	}

}

bool isValid(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	dijkstra(0);
	int ans = dist[n - 1][m - 1] == INF ? -1 : dist[n - 1][m - 1];
	cout << ans << endl;

	return 0;

}

```


