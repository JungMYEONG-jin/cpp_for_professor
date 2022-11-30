#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int n;
    cin>>n;
    priority_queue<int> pos;
    priority_queue<int, vector<int>, greater<int>> neg;
    
    ll sum=0;
    ll x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x>0) pos.push(x);
        else neg.push(x);
    }
    
    
    ll a=1, b=1;
    while(!pos.empty())
    {
        a = pos.top();
        pos.pop();
        if(pos.size()>0)
        {
            b = pos.top();
            pos.pop();
            if(a>1 && b>1)
                sum+=a*b;
            else
                sum+=a+b;
        }else
        {
            sum+=a;
        }
        
    }

    while(!neg.empty())
    {
        a = neg.top();
        neg.pop();
        if(neg.size()>0)
        {
            b = neg.top();
            neg.pop();
        }else
            b=1;
        
        sum+=a*b;
    }
    
    cout<<sum<<'\n';
    
    return 0;


}
