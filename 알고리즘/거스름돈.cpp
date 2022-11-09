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
    int n;
    cin>>n;
    
    vector<int> coin{2, 5};
    vector<int> dp(n+1, 99999999);


    dp[0] = 0;
    for(auto c : coin){
        for(int i=1;i<=n;i++){
            if(i>=c)
                dp[i] = min(dp[i], dp[i-c]+1);
        }
    }
    if(dp[n]==99999999)
        cout<<-1;
    else
        cout<<dp[n];
}
