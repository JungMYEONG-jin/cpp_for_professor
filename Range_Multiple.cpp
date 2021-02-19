#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <cstring>

using namespace std;

typedef long long ll;

vector<long long> tree;
ll arr[1000001];

const int mod = 1000000007;


ll init(int node, int start, int end)
{
    if(start==end)
    {
        
        return tree[node] = arr[start];
        
    }   
    
   return tree[node] = (init(2*node, start, (start+end)/2)*init(2*node+1, (start+end)/2+1, end))%mod;
}


ll update(int node, int start, int end, int idx, ll val)
{
    
    if(idx<start || idx>end)
        return tree[node];
    if(start==end)
    {
        arr[idx] = val;
        return tree[node] = val;
    }
    
      
   return tree[node] = (update(2*node, start, (start+end)/2, idx, val) * update(2*node+1, (start+end)/2+1, end, idx, val))%mod;   
    
}


ll sum(int node, int start, int end, int left ,int right)
{
    if(left>end || right<start)
        return 1;
    if(start==end)
        return tree[node];
    
    if(start>=left && right>=end)
        return tree[node];
    
    
    return (sum(2*node, start, (start+end)/2, left, right) * sum(2*node+1, (start+end)/2+1, end, left, right))%mod;
    
}


int main()
{
    int n, m, t;
    cin>>n>>m>>t;
    
    m+=t;
    ll size = 1<<static_cast<ll>(ceil(log2(n)+1));
    tree.resize(size);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        
    }
    init(1, 1, n);
    
    
    int a;
    while(m>0)
    {
        cin>>a;
        if(a==1)
        {
            int idx;
            long long val;
            cin>>idx>>val;
            //arr[idx] = val;
            update(1, 1, n, idx, val);
        }else if(a==2)
        {
            int left, right;
            cin>>left>>right;
            cout<<sum(1, 1, n, left, right)<<'\n';
        }
        
        
        
        
        
        
        m--;
    }
    
    return 0;
    
}
