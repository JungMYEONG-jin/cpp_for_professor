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

int n, m, start;

vector<pair<int, int>> graph[100001];

int main()
{
	int n, v;
	cin >> n >> v;

	vector<vector<int>> res(n + 1, vector<int>(n + 1,INF));
	for (int i = 1; i <= n; i++)
		res[i][i] = 0;
	int start, end, weight;
	for (int i = 0; i < v; i++)
	{
		cin >> start >> end >> weight;
		res[start][end] = weight;
	}

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

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (res[i][j] == INF)
				cout << "INF" << " ";
			else
				cout << res[i][j] << " ";
		}
		cout << endl;
	}


}
