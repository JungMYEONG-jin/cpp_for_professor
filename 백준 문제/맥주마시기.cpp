#include <iostream>
#include <queue>
#include <string>
#include <cstring>

#define INF 999999999

using namespace std;

bool visited[102];


int main()
{
	int t;
	cin >> t;
	while (t)
	{
		int store;
		cin >> store;
		vector<pair<int, int>> res;
		vector<int> graph[102];
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < store + 2; i++)
		{
			int x, y;
			cin >> x >> y;
			res.push_back({ x,y });
		}

		for (int i = 0; i < store + 2; i++)
		{
			for (int j = i + 1; j < store + 2; j++)
			{
				if (abs(res[i].first - res[j].first) + abs(res[i].second - res[j].second) <= 1000)
				{
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		queue<int> q;
		q.push(0); // start
		visited[0] = true;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (auto next : graph[x])
			{
				if (!visited[next])
				{
					visited[next] = true;
					q.push(next);
						
				}
			}
		}



		if (visited[store + 1])
			cout << "happy\n";
		else
			cout << "sad\n";


		t--;
	}
}
