#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int dir;

void left()
{
	dir--;
	if (dir < 0)
		dir = 3; // n e s w
}


int main()
{

	int n, m;
	int x, y;
	cin >> n >> m;
	cin >> x >> y >> dir;
	vector<vector<int>> res(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> res[i][j];
		}
	}

	int dx[] = { -1,0,1,0 };
	int dy[] = { 0, 1, 0, -1 };


	int turn = 0;
	int cnt = 0;
	vector<vector<bool>> visited(n, vector<bool>(m));
	visited[x][y] = true;
	int nx, ny;
	while (true)
	{
		left();
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (visited[nx][ny] == false && res[nx][ny] != 1)
		{
			cnt++;
			x = nx;
			y = ny;
			turn = 0;
			visited[nx][ny] = true;
		}
		else
		{
			turn++;
		}

		if (turn == 4)
		{
			nx = x - dx[dir];
			ny = y - dy[dir];

			if (res[nx][ny] == 0)
			{
				x = nx;
				y = ny;
			}
			else
				break;
			turn = 0;

		
		}

	}

	cout << cnt << endl;


	

}
