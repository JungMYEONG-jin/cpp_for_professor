#include <iostream>
#include <queue>
#include <string>
#include <cstring>

#define INF 999999999

using namespace std;

char db[12][6];
bool visited[12][6];
int dx[4] = { 1,-1, 0,0 };
int dy[4] = { 0, 0, 1, -1 };


int main()
{
	string str;
	for (int i = 0; i < 12; i++)
	{
		cin >> str;
		for (int j = 0; j < 6; j++)
			db[i][j] = str[j];
	}
	bool flag;
	int boom = 0;
	vector<pair<int, int>> pos;
	while (true)
	{
		flag = false;
		memset(visited, false, sizeof(visited));
		pos.clear();
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (!visited[i][j] && db[i][j]!='.')
				{
					vector<pair<int, int>> res;
					queue<pair<int, int>> q;
					visited[i][j] = true;
					q.push({ i,j });

					while (!q.empty())
					{
						auto it = q.front();
						q.pop();
						int x = it.first;
						int y = it.second;
						res.push_back(it);
						for (int k = 0; k < 4; k++)
						{
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx >= 0 && ny >= 0 && nx < 12 && ny < 6)
							{
								if (!visited[nx][ny] && db[nx][ny] == db[i][j] )
								{
									visited[nx][ny] = true;
									q.push({ nx, ny });
								}
							}
						}
					}

					if (res.size() > 3)
					{
						flag = true;
						for (auto it : res)
							pos.push_back(it); // 4개이상인 경우 저장시켜줌
					
					}

				}
			}
		}

		for (auto it : pos)
			db[it.first][it.second] = '.'; // 폭파

		for (int i = 10; i >= 0; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (db[i][j] == '.')
					continue;
				int temp = i;
				while (true)
				{
					if (temp == 11 || db[temp + 1][j] != '.')
						break;
					db[temp + 1][j] = db[temp][j];
					db[temp][j] = '.';
					temp++; // 내려주기
				}
			}
		}

		if (flag)
			boom++;
		else
			break;


	}

	cout << boom << endl;



}
