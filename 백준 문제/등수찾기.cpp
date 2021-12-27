#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>

#define INF 999999999

using namespace std;

string base = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
vector<int> graph[100001];
vector<int> rev_graph[100001];
bool visited[100001];


int main()
{

	

	int n, m, x;
	cin >> n >> m >> x;

	
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		rev_graph[b].push_back(a);
	}


	queue<int> q;
	q.push(x);
	int cnt = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int num : graph[cur])
		{
			if (!visited[num])
			{
				q.push(num);
				visited[num] = true;
				cnt++;
			}
		}
	}

	int lower = n - cnt;
	memset(visited, false, sizeof(visited));
	cnt = 0;
	q.push(x);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int num : rev_graph[cur])
		{
			if (!visited[num])
			{
				visited[num] = true;
				cnt++;
				q.push(num);
			}
		}
	}
	int upper = cnt+1;

	cout << upper << " " << lower << endl;



}
