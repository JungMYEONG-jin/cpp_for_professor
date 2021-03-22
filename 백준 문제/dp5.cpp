#include <iostream>

using namespace std;

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


int n;
int dp[101][11]={0,};

int sum=0;
cin>>n;
for(int i=0;i<=9;i++)
	dp[1][i]=1;

for(int i=2;i<=n;i++)
{

dp[i][0] = dp[i-1][1];
dp[i][10]=0;
for(int j=0;j<=9;j++)
	dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%1000000000;

}


for(int i=1;i<=9;i++)
{
sum= (sum+dp[n][i])%1000000000;

}


cout<<sum<<endl;


}
