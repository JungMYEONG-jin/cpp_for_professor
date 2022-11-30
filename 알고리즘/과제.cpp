#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin>>n;

    vector<pair<int, int>> res(n);

    for(int i=0;i<n;i++)
    {
        cin>>res[i].first>>res[i].second;
    }

    sort(res.begin(), res.end(), [](auto e, auto k){return e.second>k.second || e.second==k.second && e.first>k.first;});

    int arr[1001]={0};
    
    for(int i=0;i<n;i++)
    {
        for(int j=res[i].first;j>0;j--)
        {
            if(arr[j]==0)
            {
                arr[j] = res[i].second;
                break;
            }
        }
    }
    
    ll sum=0;
    
    for(int i=0;i<1001;i++)
        sum+=arr[i];
        
        
    cout<<sum<<endl;
    
    
    return 0;
}
