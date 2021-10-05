#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>

using namespace std;

int n, m;
vector<string> res;
bool dfs(int x, int y)
{
	if (x <= -1 || x >= n || y <= -1 || y >= m)
		return false;

	if (res[x][y] == '0')
	{
		res[x][y] = '1'; // visit

		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x + 1, y);
		dfs(x, y - 1);
		return true;
	}
	return false;

}


int main()
{
	cin >> n >> m;
	string line;
	res.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> res[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dfs(i, j))
				cnt++;
		}
	}
	
	cout << cnt;

	

}
