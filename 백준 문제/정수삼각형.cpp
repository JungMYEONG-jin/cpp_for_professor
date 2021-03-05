#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <regex>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <sstream>
#include <functional>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    int n;
    cin >> n;
    int tri[501][501] = { 0 };
    int dp[501][501] = { 0 };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }
    dp[0][0] = tri[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + tri[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tri[i][j];
        }
    }
    int ans=-1;
   for(int i=0;i<n;i++)
       ans = max(ans, dp[n-1][i]);
    cout<<ans;


}
