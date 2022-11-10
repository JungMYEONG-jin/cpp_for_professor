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



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    

	int dp[50001];
	dp[1] = 1;

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int minValue = INF;
		for (int j = 1; j <= sqrt(i); j++) {
			int tmp = i - j * j;
			minValue = min(minValue, dp[tmp]);
		}
		dp[i] = minValue + 1;
	}
	cout << dp[n] << endl;



    return 0;

}
