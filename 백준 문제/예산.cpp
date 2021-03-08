#include <map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++)
	cin>>arr[i];
long long m;
cin>>m;
sort(arr.begin(), arr.end());
int left = 1;
int right = arr[n-1];
int max_val = 0;
while(left<=right)
{

int mid = (left+right)/2;
long long tot=0;
for(auto i: arr)
{
if(i<mid)
	tot+=i;
else
	tot+=mid;

}

if(tot<=m)
{
left = mid+1;
max_val = max(max_val, mid);
}else
{
right = mid-1;
}


}
	

cout<<max_val;    
    return 0;
    
}
