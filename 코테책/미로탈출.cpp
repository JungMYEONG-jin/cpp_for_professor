#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int n, m;
int res[201][201];
bool dfs(int x, int y)
{
	if (x <= -1 || x >= n || y <= -1 || y >= m)
		return false;

	if (res[x][y] == '0')
	{
		res[x][y] = '1'; // visit

		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x + 1, y);
		dfs(x, y - 1);
		return true;
	}
	return false;

}

int bfs(int x, int y)
{
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty())
	{
		auto it = q.front();
		q.pop();
		int x = it.first;
		int y = it.second;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <0 || ny <0 || nx >= n || ny >= m)
				continue;
			if (res[nx][ny] == 0)
				continue;

			if (res[nx][ny] == 1)
			{
				res[nx][ny] = res[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return res[n - 1][m - 1];

}


int main()
{
	cin >> n >> m;
	string line;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%1d", &res[i][j]);
		}
	}
	
	
	cout << bfs(0, 0) << endl;
	
	

	

}
