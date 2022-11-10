#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <set>
#include <numeric>
#include <cmath>
#include <stack>

#define INF 1000000000

using namespace std;


long long t[1001][1001];
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long mod = 1e9 + 7;
    
	int n, m;
	cin >> n>>m;
	t[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			t[i][j] = (t[i - 1][j] + t[i][j - 1] + t[i - 1][j - 1]) % mod;
		}
	}


	
	cout << t[n][m] << endl;


    return 0;

}
