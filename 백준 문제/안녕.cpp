#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <numeric>

#define INF 999999999

using namespace std;



int dp[21][101];
pair<int, int> arr[21];
int main()
{
    int n;
    cin>>n;
    int minus, plus;
     // lost, get happy
    for(int i=1;i<=n;i++)
        cin>>arr[i].first;
    for(int i=1;i<=n;i++)
        cin>>arr[i].second;

    int maxHappy = -1e9;
    for(int i=1;i<=n;i++){
      for(int j=100;j>=1;j--){
        if(j-arr[i].first>0){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i].first]+arr[i].second);
        }else
            dp[i][j] = dp[i-1][j];

        maxHappy = max(maxHappy, dp[i][j]);
      }
    }

    cout<<maxHappy<<endl;

    return 0;
}
