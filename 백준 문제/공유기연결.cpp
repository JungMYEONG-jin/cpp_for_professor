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
    
    
int N, C;
cin>>N>>C;
vector<long long> arr(N);
for(int i=0;i<N;i++)
{
cin>>arr[i];
}

sort(arr.begin(),arr.end()); // sort array

long long left = 1; //min
long long right = arr[N-1]-arr[0]; // max

long long max_val=0;

while(left<=right)
{

long long mid = (left+right)/2;
long long prev=arr[0];
long long cnt=0;
cnt++;
for(int i=1;i<N;i++)
{
if(arr[i]-prev>=mid)
{
prev = arr[i];
cnt++;
}

}

if(cnt>=C)
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
