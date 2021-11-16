#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>

#define INF 999999999

using namespace std;


int main()
{
	
	int t;
	cin >> t;

	while (t)
	{
		int a, b;
		cin >> a >> b;
		int prev = a;
		queue<pair<int, string>> q;
		q.push({ a,"" });
		bool visited[10000];
		memset(visited, false, sizeof(visited));
		visited[a] = true;
		string s;
		while (!q.empty())
		{
			int x = q.front().first;
			string op = q.front().second;
			q.pop();
			if (x == b)
			{
				s = op;
				cout << s << endl;
				break;
			}
			int x1 = x - 1 >= 0 ? x - 1 : 9999;
			if (!visited[x1])
			{
				visited[x1] = true;
				q.push({ x1,op + 'S' });
			}

			x1 = (2 * x) > 9999 ? (2 * x) % 10000 : 2 * x;
			if (!visited[x1])
			{
				visited[x1] = true;
				q.push({ x1, op + 'D' });
				
			}
			x1 = (x % 1000) * 10 + x / 1000;
			if (!visited[x1])
			{
				visited[x1] = true;
				q.push({ x1,op+'L' });
			}
			x1 = (x % 10) * 1000 + x / 10;
			if (!visited[x1])
			{
				visited[x1] = true;
				q.push({ x1, op + 'R' });
			}

		}



		t--;
	}

	
	

}
