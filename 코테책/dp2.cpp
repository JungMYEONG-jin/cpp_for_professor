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

	vector<int> dp(n);
	vector<int> res(n);
	for (int i = 0; i < n; i++)
		cin >> res[i];
	
	dp[0] = res[0];
	dp[1] = max(res[0], res[1]);

	for (int i = 2; i < n; i++)
		dp[i] = max(dp[i], dp[i - 2] + res[i]);

	cout << dp[n-1] << endl;
	
	

}
