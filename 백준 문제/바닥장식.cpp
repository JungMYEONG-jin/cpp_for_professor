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

bool visited[51][51];
int dx[] = { 1, -1};
int dy[] = { 1, -1 };
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				if (arr[i][j] == '-') {
					visited[i][j] = true;
					ans++;
					queue<pair<int, int>> q;
					q.push({ i,j });
					while (!q.empty()) {
						auto it = q.front();
						int x = it.first;
						int y = it.second;
						q.pop();
						for (int d = 0; d < 2; d++) {
							int nx = x;
							int ny = y + dy[d];
							if (nx < 0 || ny < 0 || nx >= n || ny >= m)
								continue;
							if (!visited[nx][ny] && arr[nx][ny] == '-') {
								visited[nx][ny] = true;
								q.push({ nx, ny });
							}
						}
					}
				}
				else if (arr[i][j] == '|')
				{
					visited[i][j] = true;
					ans++;
					queue<pair<int, int>> q;
					q.push({ i,j });
					while (!q.empty()) {
						auto it = q.front();
						int x = it.first;
						int y = it.second;
						q.pop();
						for (int d = 0; d < 2; d++) {
							int nx = x + dx[d];
							int ny = y;
							if (nx < 0 || ny < 0 || nx >= n || ny >= m)
								continue;
							if (!visited[nx][ny] && arr[nx][ny] == '|') {
								visited[nx][ny] = true;
								q.push({ nx, ny });
							}
						}
					}
				}
			}
		}
	}
	
	cout << ans << endl;



    return 0;

}
// 2335
