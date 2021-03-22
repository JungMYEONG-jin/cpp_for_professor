#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main()
{

int n;
cin>>n;
vector<pair<int, int>> res(n);

for(int i=0;i<n;i++)
{

cin>>res[i].first>>res[i].second;
}

sort(res.begin(), res.end());


int dp[n+1];

fill(dp, dp+n+1,1);

int cnt=0;
for(int i=0;i<n;i++)
{
int val = res[i].second;
for(int j=0;j<i;j++)
{
if(val>res[j].second)
	dp[i] = max(dp[i], dp[j]+1);

}
cnt = max(cnt, dp[i]);

}

cout<<n-cnt;


}
