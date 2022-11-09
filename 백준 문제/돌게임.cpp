#include <iostream>

using namespace std;

int dp[1001];

int main()
{
    int n;
    cin>>n;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1; // 승
    dp[3] = 0; // 패
    dp[4] = 1;
    for(int i=4;i<=n;i++){
        if(dp[i-1]==0 || dp[i-3]==0)
            dp[i] = 1;
        else
            dp[i] = 0; 
    }
    if (dp[n])
    {
        /* code */
        cout<<"SK";
    }else
        cout<<"CY";
    

    
}
