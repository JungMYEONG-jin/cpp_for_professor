#include <iostream>
#include <cstring>

using namespace std;


long long mod = 1000007;


int main()
{
    
    long long dp[201][201];
    int m, n, x, y;
    cin>>m>>n;
    cin>>x>>y;
    for(int i=1;i<=200;i++)
    {
        for(int j=1;j<=200;j++)
        {
            if(i==1 || j==1)
                dp[i][j]=1;
            else
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    
    
    
    cout<<(dp[x][y]*dp[m-x+1][n-y+1])%mod;
    
    
    
}
