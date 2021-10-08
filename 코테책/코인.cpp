#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>

using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> res(n);
	for (int i = 0; i < n; i++)
		cin >> res[i];

	vector<int> dp(m + 1, 99999);
	dp[0] = 0;
	
	for (auto j : res)
	{
		for (int i = j; i <= m; i++)
			dp[i] = min(dp[i], dp[i - j] + 1);
	}

	cout << dp[m] << endl;

	
	

}
