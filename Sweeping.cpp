// 행렬의 거듭제곱을 빠르게 표현하는 알고리즘

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int n;
    cin>>n;
    
    vector<pair<ll, ll>> res(n);
    
    for(int i=0;i<n;i++)
        cin>>res[i].first>>res[i].second;
        
    // x, y 범위 비교 하자
    ll sum=0;
    ll range=0;
    
    sort(res.begin(), res.end(), [](auto e, auto k){
        return e.first<k.first || e.first==k.first &&e.second<k.second;
    });
    
    ll x= -1000000001;
    ll y = -1000000001;
    
    for(int i=0;i<n;i++)
    {
        
       if(y<res[i].first)
       {
           sum+=y-x;
           x = res[i].first;
           y = res[i].second;
       }else
           y = max(y,res[i].second);
        
        
    }
    
    sum+=y-x;
    
    
    cout<<sum<<endl;
    
    return 0;
}
