#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int k;
long long n;
cin>>k>>n;
vector<int> res(k);
long long max_cm=1;
for(int i=0;i<k;i++)
{
cin>>res[i];
}

sort(res.begin(), res.end());

long long left=1;
long long right = res[k-1];

while(left<=right)
{

long long mid = (left+right)/2;
long long tot=0;
for(auto i : res)
{
	tot+=i/mid;
}

if(tot>=n)
{
max_cm = max(max_cm, mid);
left = mid+1;
}else
{
right = mid-1;
}







}


cout<<max_cm<<'\n';

return 0;



}
