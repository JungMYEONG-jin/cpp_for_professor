#include <stack>
#include <algorithm>
#include <iostream>


using namespace std;


int main()
{



ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int n;
long long ans=0;
long long x;
while(true)
{

cin>>n;
if(n==0) break;

ans=0;
stack<pair<long long, long long>> res;

for(int i=0;i<=n;i++)
{

if(i<n)
	cin>>x;
else
	x=-1;

int prev=i;
while(!res.empty()  &&x<res.top().second)
{
ans = max(ans, res.top().second*(i-res.top().first));
prev = res.top().first;
res.pop();

}
res.push({prev, x});



}

cout<<ans<<'\n';





}









}
