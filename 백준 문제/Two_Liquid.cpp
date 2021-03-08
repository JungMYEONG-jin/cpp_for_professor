#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <climits>
using namespace std;










int main()
{
    
    
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    
    
    
    int n;
    cin>>n;
    long long arr[100000];
for(int i=0;i<n;i++)
	cin>>arr[i];

sort(arr, arr+n);

int left=0;
int right = n-1;
long long min_val=LLONG_MAX;
int l=0;
    int r=0;
while(left<right)
{
long long val = (arr[left]+arr[right]);

if(abs(val)<min_val)
{
    min_val = abs(val);
    l=left;
    r = right;
}
    
    
    
if(val>0)
{

right--;
}else
{

left++;

}


}
    
    
    cout<<arr[l]<<" "<<arr[r];
    
}
