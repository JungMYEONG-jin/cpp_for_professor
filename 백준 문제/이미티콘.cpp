#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>

#define INF 999999999

using namespace std;

bool visited[1001][1001];

int n;

bool is_valid(int num)
{
	if (num >= 0 && num < 1001)
		return true;
	return false;
}


int main()
{
	cin >> n;
	queue<tuple<int, int, int>> q;
	q.push({ 1, 0, 0 }); // 현재갯수 clipboard time
	visited[1][0] = true; // 1 0 init
	while (!q.empty())
	{
		auto it = q.front();
		q.pop();
		int cur, clip, dtime;
		tie(cur, clip, dtime) = it;

		if (cur == n)
		{
			cout << dtime << endl;
			break;
		}

		if (cur > 0 && cur < 1001)
		{
			if (!visited[cur - 1][clip])
			{
				visited[cur - 1][clip] = true;
				q.push({ cur - 1, clip, dtime + 1 });
			}

			if (!visited[cur][cur])
			{
				visited[cur][cur] = true;
				q.push({ cur , cur, dtime + 1 });
			}
		}

		if (cur > 0 && cur + clip < 1001)
		{
			if (!visited[cur+clip][clip])
			{
				visited[cur+clip][clip] = true;
				q.push({ cur+clip , clip, dtime + 1 });
			}
		}


		
	}
	
}
