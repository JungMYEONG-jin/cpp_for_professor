#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> jew(n+1);
    for (int i = 1; i <= n; i++)
        cin >> jew[i].first >> jew[i].second;

    
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(j>=jew[i].first)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-jew[i].first]+jew[i].second);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    cout<<dp[n][k]<<endl;
  
  /*
  
   vector<int> dp(k+1);
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=k;j>=1;j--)
        {
            if(j>=jew[i].first)
                dp[j] = max(dp[j], dp[j-jew[i].first]+jew[i].second);
        }
    }
  
  // 일차원 배열 선언시 메모리 15배 절약 속도는 약 2.5배 정도 좋은 성능을 보임
  
  
  
  
  
  
  
  */
    
    
}
