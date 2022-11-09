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

int main()
{
    int n, t;
    cin>>t;

    while(t--){

    cin>>n;
    
    vector<int> res(n);
    vector<int> dp(n, 1);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
        dp[i] = res[i];
    }
    int ans = res[0];
    for(int i=1;i<n;i++){
        dp[i] = max(dp[i], dp[i-1]+res[i]);
        ans = max(ans, dp[i]);
    }
        cout<<ans<<endl;
    }

    return 0;
}
