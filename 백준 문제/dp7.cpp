#include <iostream>


using namespace std;


int main()
{


int n;
cin>>n;
int drink[n+1];
int dp[n+1];

for(int i=1;i<=n;i++)
	cin>>drink[i];

dp[0] = 0;
dp[1] = drink[1];
dp[2] =drink[1]+drink[2];
int ans=0;
for(int i=3;i<=n;i++)
{

dp[i] = max(dp[i-3]+drink[i-1]+drink[i], dp[i-2]+drink[i]);
dp[i] = max(dp[i], dp[i-1]);
}

cout<<dp[n]<<endl;


}
