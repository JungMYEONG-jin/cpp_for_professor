#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long arr[500001];
    int n,m;
    cin>>n;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    sort(arr, arr+n);
   
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        long long h = upper_bound(arr, arr+n, x)-arr;
        long long low = lower_bound(arr, arr+n, x)-arr;
        cout<<h-low<<" ";
    }
    
    
    return 0;
    
}
