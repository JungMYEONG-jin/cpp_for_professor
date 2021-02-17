/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll arr[1000001];
vector<ll> tree;


ll init(int node, int start, int end)
{
    if(start==end)
    {
        return tree[node] = arr[start];
    }
    return tree[node] =init(node*2, start, (start+end)/2)+init(node*2+1, (start+end)/2+1, end);
}

void update(int node, int start, int end, int idx, ll diff)
{
    if(idx<start || idx>end) 
        return ;
    tree[node]+=diff;
    if(start!=end)
    {
        update(node*2, start, (start+end)/2, idx, diff);
        update(node*2+1, (start+end)/2+1, end, idx, diff);
    }
}



ll sum(int node, int start, int end, int left, int right)
{
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
    
    init(1,0,n-1);
    m+=t;
    while(m>0)
    {
    int a, b, c;
    cin>>a;
    if(a==1)
    {
        int idx;
        ll temp;
        cin>>idx>>temp;
        ll diff = temp-arr[idx-1];
        arr[idx-1] = temp;
        update(1, 0, n-1, idx-1, diff);
    }else if(a==2)
    {
        cin>>b>>c;
        cout<<sum(1, 0, n-1, b-1, c-1)<<'\n';
    }
        
    
    m--;
    }
    return 0;
}
