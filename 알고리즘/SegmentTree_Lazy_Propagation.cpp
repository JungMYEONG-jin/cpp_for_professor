#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll arr[1000001];
vector<ll> tree;
vector<ll> lazy;

ll init(int node, int start, int end)
{
    if(start==end)
    {
        return tree[node] = arr[start];
    }
    return tree[node] =init(node*2, start, (start+end)/2)+init(node*2+1, (start+end)/2+1, end);
}



void lazy_propagation(int node, int start, int end)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node] = 0;
        
    }
}




void update(int node, int start, int end, int idx,int idx2, ll val)
{
    
    lazy_propagation(node,start, end);
    if(idx2<start || idx>end ||idx>idx2) 
        return ;
    if(idx<=start && idx2>=end)
    {
        tree[node]+=(end-start+1)*val;
        if(start!=end)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return ;
    }
    
    update(2*node, start, (start+end)/2, idx, idx2, val);
    update(2*node+1, (start+end)/2+1, end, idx, idx2, val);
    
    tree[node] = tree[2*node]+tree[2*node+1];
}



ll sum(int node, int start, int end, int left, int right)
{
    
   lazy_propagation(node, start, end);
    
    
    if(left>end || right<start) 
        return 0;
    if(start>=left && right>=end)
        return tree[node];

    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);

}








int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t;
    cin>>n>>m>>t;
    int size = 1<<static_cast<int>(ceil(log2(n)+1));
    for(int i=0;i<n;i++)
        cin>>arr[i];
    tree.resize(size);
    lazy.resize(size);
    init(1,0,n-1);
    //lazy_propagation(1,0,n-1);
    m+=t;
    while(m>0)
    {
    int a, b, c;
    cin>>a;
    if(a==1)
    {
        int idx;
        int idx2;
        ll temp;
        cin>>idx>>idx2>>temp;
        
        update(1, 0, n-1, idx-1, idx2-1, temp);
        
        
    }else if(a==2)
    {
        cin>>b>>c;
        cout<<sum(1, 0, n-1, b-1, c-1)<<'\n';
    }


    m--;
    }
    return 0;
}
