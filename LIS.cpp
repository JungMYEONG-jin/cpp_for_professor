#include <iostream>

using namespace std;

int main()
{
int arr[1001];
int res[1001];
int dp[1001];
int N;
cin>>N;
for(int i=0;i<N;i++)
{
cin>>arr[i];
dp[i]=1;
}
int max_val=1;




for(int i=0;i<N;i++)
{
for(int j=0;j<i;j++)
{
    if(arr[i]>arr[j] && dp[j]+1>dp[i])
    {
       dp[i]++; 
    }
    
}
max_val = max(max_val, dp[i]);

}
cout<<N-max_val<<endl;

}
