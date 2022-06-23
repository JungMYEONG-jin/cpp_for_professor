#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;



int lcs(const string& left, const string& right){
    int n = left.length();
    int m = right.length();
    if(n == 0 || m == 0)
        return 0;
    int ans = 0;
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        fill(dp[i], dp[i]+m+1, 0);
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(left[i-1]==right[j-1])
            {
                dp[i-1][j-1] = 1;
                if(i >= 2 && j >= 2){
                    dp[i-1][j-1] += dp[i-2][j-2];
                }
                ans = max(ans, dp[i-1][j-1]);
            }
        }
    }
    return ans;
}

int main()
{
    string left, right;
    cin>>left>>right;
    cout<<lcs(left, right)<<endl;
 
    return 0;

}
