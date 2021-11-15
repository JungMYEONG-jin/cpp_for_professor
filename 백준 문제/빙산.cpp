#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>

#define INF 999999999

using namespace std;

bool visited[300][300];
int db[300][300];
map<pair<int, int>, int> res;
int n, m;
int dx[4] = { 1,-1, 0,0 };
int dy[4] = { 0,0,1,-1 };

bool is_valid(int x, int y)
{
	if (x >= 0 && y >= 0 && x < n && y < m)
		return true;
	return false;
}

int get_zero(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (is_valid(nx, ny) && db[nx][ny] == 0)
			cnt++;
	}
	return cnt;
}



int get_cnt()
{
	int total = 0;
	while (true)
	{
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		res.clear();
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visited[i][j] && db[i][j] > 0)
				{
					cnt++;
					visited[i][j] = true;
					queue<pair<int, int>> q;
					q.push({ i, j });

					while (!q.empty())
					{
						auto it = q.front();
						q.pop();
						int x = it.first;
						int y = it.second;

						int num = get_zero(x, y);
						res[it] = num;

						for (int k = 0; k < 4; k++)
						{
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (is_valid(nx, ny))
							{
								if (!visited[nx][ny] && db[nx][ny] > 0)
								{
									visited[nx][ny] = true;
									q.push({ nx, ny });
								}
							}
						}
					}


				}
			}
		}

		if (cnt > 1) // 2개이상 분리된 경우
			return total;
		else if(cnt==1) // 1개로 이어진경우 근처 0갯수만큼 제거
		{
			for (const auto& it : res)
			{
				db[it.first.first][it.first.second] = db[it.first.first][it.first.second] - it.second >= 0 ? db[it.first.first][it.first.second] - it.second : 0;
			}

		}
		else // 결국 분리되지 않고 끝난경우 cnt = 0 
			break;


		total++;
	}

	return 0; // 실패한경우

}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> db[i][j];
	}

	
	cout << get_cnt() << endl;
	
}
