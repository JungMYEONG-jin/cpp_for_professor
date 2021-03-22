#include <iostream>


using namespace std;


int main()
{


int dp[1000002];

dp[2]=1;
dp[3]=1;
dp[4]=2;

int n;
cin>>n;



for(int i=5;i<=n;i++)
{
dp[i] = dp[i-1]+1;

if(i%2==0)
	dp[i] = min(dp[i], dp[i/2]+1);
if(i%3==0)
	dp[i] = min(dp[i], dp[i/3]+1);



}




cout<<dp[n];



}
