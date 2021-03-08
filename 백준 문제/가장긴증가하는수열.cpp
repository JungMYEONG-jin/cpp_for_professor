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
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    
    vector<long long> res;
    res.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(res.back()<arr[i])
            res.push_back(arr[i]);
        else
        {
            auto it = lower_bound(res.begin(), res.end(), arr[i]);
            *it = arr[i];
        }
    }
    
    
    
    cout<<res.size();
    return 0;
    
    
    
    
    
    
}
