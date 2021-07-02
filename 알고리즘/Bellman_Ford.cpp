#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <stack>

#define inf LONG_MAX

using namespace std;


int main()
{
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int V, E;
	cin >> V >> E;

	vector<pair<int, int>> arr[V+1];
	long long dist[V+1];

	fill(dist, dist + V+1, inf);
	bool cycle = false;

	dist[1] = 0; // start

	for (int i = 0; i < E; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		arr[from].push_back({ to, weight });
	}


	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			for (auto& k : arr[j])
			{
				int next = k.first;
				int next_weight = k.second;
				if (dist[j] != inf && dist[next] > dist[j] + next_weight)
				{
					dist[next] = dist[j] + next_weight;
					if (i == V)
						cycle = true;
				}
			}
		}
	}

	if (cycle)
		cout << "-1\n";
	else
	{
		for (int i = 2; i <= V; i++)
		{
            if(dist[i]==inf)
                cout<<"-1\n";
            else
			    cout << dist[i] << '\n';
		}
	}



}
