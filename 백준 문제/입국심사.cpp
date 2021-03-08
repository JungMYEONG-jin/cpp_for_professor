#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


int n;
long long m;
cin>>n>>m;

vector<long long> arr(n);
for(int i=0;i<n;i++)
	cin>>arr[i];



sort(arr.begin(), arr.end());

long long left = 1;
long long right = m*arr[n-1];

long long min_val = right;

while(left<=right)
{
long long mid = (left+right)/2;
long long people = 0;

for(auto i : arr)
	people+=mid/i;

if(people<m)
{
left = mid+1;

}else
{
min_val = min(min_val, mid);
right = mid-1;


}



}
   
 cout<<min_val<<'\n';
return 0;   
    
    
}
