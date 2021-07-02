#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <climits>

#define inf INT_MAX
using namespace std;


int main()
{
  


    int target = 680;
    vector<int> coin{ 500,100,50,10,40 };
    sort(coin.begin(), coin.end());
    vector<int> dp(target + 1, inf);

    

    dp[0] = 0;
    for (auto c : coin)
    {
        for (int i = 1; i <= target; i++)
        {
            if (i >= c)
                dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    cout << dp[target];

}
