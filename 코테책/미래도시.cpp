#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#define INF 999999999

using namespace std;

int main()
{
	int n, v;
	cin >> n >> v;

	vector<vector<int>> res(n + 1, vector<int>(n + 1,INF));
	for (int i = 1; i <= n; i++)
		res[i][i] = 0;
	int start, end;
	for (int i = 0; i < v; i++)
	{
		cin >> start >> end;
		res[start][end] = 1;
		res[end][start] = 1;
	}
	int X, K;
	cin >> X >> K;
	// floyd warshall
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
			}
		}
	}

	int dist = res[1][K] + res[K][X];

	if (dist >= INF)
		cout << -1 << endl;
	else
		cout << dist << endl;


}
