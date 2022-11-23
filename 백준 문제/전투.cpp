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

bool visited[101][101];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	vector<string> res(m);
	for (int i = 0; i < m; i++)
		cin >> res[i];
	
	int w = 0, b = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n;j++) {
			if (res[i][j] == 'W' && !visited[i][j]) {
				int cnt = 1;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = true;
				while (!q.empty()) {
					auto it = q.front();
					q.pop();
					int x = it.first;
					int y = it.second;
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx >= m || ny >= n)
							continue;
						if (!visited[nx][ny] && res[nx][ny] == 'W')
						{
							visited[nx][ny] = true;
							q.push({ nx, ny });
							cnt++;
						}
					}
				}
				w += (cnt * cnt);
			}else if(res[i][j]=='B' && !visited[i][j]) {
				int cnt = 1;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = true;
				while (!q.empty()) {
					auto it = q.front();
					q.pop();
					int x = it.first;
					int y = it.second;
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx >= m || ny >= n)
							continue;
						if (!visited[nx][ny] && res[nx][ny] == 'B')
						{
							visited[nx][ny] = true;
							q.push({ nx, ny });
							cnt++;
						}
					}
				}
				b += (cnt * cnt);
			}
		}
	}

	cout << w << " " << b;



    return 0;

}
// 2335
