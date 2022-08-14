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

int maxVal = -1000000000;
int minVal = 1000000000;
int Plus, Minus, divide, multi;

int n;
int num[11];

void dfs(int p, int m, int d, int ml, int init, int idx) {
	if (idx == n) {
		maxVal = max(maxVal, init);
		minVal = min(minVal, init);
		return;
	}

	if (p < Plus) {
		dfs(p + 1, m, d, ml, init + num[idx], idx + 1);
	}
	if (m < Minus) {
		dfs(p, m+1, d, ml, init - num[idx], idx + 1);
	}
	if (ml < multi) {
		dfs(p, m, d, ml + 1, init * num[idx], idx + 1);
	}
	if (d < divide) {
		dfs(p, m, d + 1, ml, init / num[idx], idx + 1);
	}

}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	cin >> Plus >> Minus >> multi >> divide;

	dfs(0, 0, 0, 0, num[0], 1);

	cout << maxVal << "\n" << minVal << endl;

	return 0;

}
