#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>

#define INF (long long)1e15

using namespace std;

int n, ans = 999999999;
int stats[21][21];
bool checked[21];


void dfs(int x, int pos) {


	if (x == n / 2) {
		int start = 0, link = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (checked[i] && checked[j])
					start += stats[i][j];
				else if (!checked[i] && !checked[j])
					link += stats[i][j];
			}
		}

		int val = abs(start - link);
		ans = min(ans, val);
		return;
	}

	for (int i = pos; i < n; i++)
	{
		checked[i] = true;
		dfs(x + 1, i + 1);
		checked[i] = false;
	}

}



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> stats[i][j];
		}
	}
	dfs(0, 1);

	cout << ans << endl;

	return 0;

}
