#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>




using namespace std;

const int MAX = 1e5+1;
const int inf = 1e9+1;

long long arr[MAX];
long long seg[4*MAX];

long long init(int left, int right, int node)
{
    if(left==right)
    {
        return seg[node] = arr[left];
    }
    int mid = (left+right)/2;
    
    return seg[node] = min(init(left, mid, node*2), init(mid+1, right, node*2+1));
    
}

long long input(int left, int right, int node, int n_left, int n_right)
{
    
    
    if(n_left > right || n_right < left)
    {
        return inf;
    }
    
    if(n_left>=left && right>=n_right)
    {
        return seg[node];
    }
    
    
    int mid = (n_left+n_right)/2;
    return min(input(left, right, node*2, n_left, mid), input(left, right, node*2+1, mid+1, n_right));
    
    
    
}

int main()
{
    

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
    cin>>arr[i];


init(1, n, 1);


int left, right;
for(int i=0;i<m;i++)
{
    cin>>left>>right;
    
    cout<<input(left, right, 1, 1, n)<<'\n';
}

return 0;

    
}
