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

	vector<int> dp(n+1);
	// tile
	dp[1] = 1; //2 by 1
	dp[2] = 3; // 2 by 2, 2 by 1 2 by 1, 1 by 2, 1 by 2;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 796796;
	cout << dp[n] << endl;
	
	

}
