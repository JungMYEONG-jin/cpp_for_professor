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
	int n;
	cin >> n;

	vector<int> dp(n + 1);
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2]+1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3]+1);
		if (i % 5 == 0)
			dp[i] = min(dp[i], dp[i / 5]+1);
	}

	cout << dp[n] << endl;
	
	

}
