// 세그먼트 트리로 해볼까

#include <iostream>
#include <vector>
#include <cmath>

#define INF 100000

using namespace std;


vector<int> tree;
int n;
int arr[INF];

void init()
{
    tree.clear();
    
}

void make_tree(int node ,int start, int end)
{
    if(start==end)
    {
        tree[node]=start;
        return ;
    }
    int mid = (start+end)>>1;
    make_tree(2*node, start, mid);
    make_tree(2*node+1, mid+1, end);
    
    if(arr[tree[2*node]]<=arr[tree[2*node+1]])
        tree[node] = tree[2*node];
    else
        tree[node] = tree[2*node+1];
    
}

int get_idx(int node, int start, int end, int left, int right)
{
    
    if(right<start || left>end)
        return -1;
    if(left<=start && right>=end)
        return tree[node];
    
    int mid = (start+end)>>1;
    
    int l = get_idx(2*node, start, mid, left, right);
    int r = get_idx(2*node+1, mid+1, end, left, right);
    if(l==-1)
        return r;
    if(r==-1)
        return l;
    if(arr[l]<=arr[r])
        return l;
    
    
    return r;
    
}

long long get_width(int start, int end)
{
    
    int midx = get_idx(1, 0, n-1, start, end);
    long long ans = static_cast<long long>(end-start+1)*static_cast<long long>(arr[midx]);
    
    
    if(start<=midx-1)
    {
        long long lwidth = get_width(start, midx-1);
        ans = max(ans, lwidth);
    }
    if(midx+1<=end)
    {
        long long rwidth = get_width(midx+1, end);
        ans = max(ans, rwidth);
    }
    
    return ans;
    
    
}


void solution()
{
    int h = (int)ceil(log2(n));
    int tree_size = 1<<(h+1);
    
    tree.resize(tree_size);
    make_tree(1,0,n-1);
    long long res = get_width(0, n-1);
    cout<<res<<'\n';
}



int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    
    while(true)
    {
        init();
        
        cin>>n;
        if(n==0)
            break;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        solution();
        
    }
    
    
    
    
    
    return 0;
    
    
}
