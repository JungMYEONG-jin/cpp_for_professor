#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


long long n;
long long k;
cin>>n>>k;


long long left=1;
long long right =k;
long long val=1;
while(left<=right)
{

long long mid = (left+right)/2;
long long cnt=0;
for(int i=1;i<=n;i++)
	cnt+=min(mid/i, n);

if(cnt<k)
{
left = mid+1;

}else
{
val = mid;
right = mid-1;
}



}

cout<<val<<'\n';

   
}
