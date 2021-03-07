#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


long long n,m;
    
cin>>n>>m;
vector<long long> arr(n);
for(long long i=0;i<n;i++)
	cin>>arr[i];
sort(arr.begin(), arr.end());




long long left =0;
long long right = arr[n-1];

long long mval=0;
while(left<=right)
{
long long mid = (left+right)/2;
long long tot=0;

for(auto i : arr)
{
    
    if(i>mid)
        tot+=i-mid;
}
    
    
    
if(tot>=m)
{
    mval = max(mval, mid);
left=mid+1;

}else
{
right = mid-1;


}


}



cout<<mval<<'\n';



return 0;



}
