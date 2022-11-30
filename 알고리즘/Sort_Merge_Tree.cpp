#include <vector>
#include <iostream>
#include <algorithm>

#define range(res) res.begin(), res.end()

using namespace std;

int arr[1000001];
int n;
vector<int> tree[1<<18];
const int number = 1<<17;


void add(int x, int value)
{
    x|=number;
    tree[x].push_back(value);
}

void init()
{
    for(int i=1;i<=n;i++)
        add(i, arr[i]);
    
    for(int i = number-1;i>0;i--)
    {
        tree[i].resize(tree[2*i].size() + tree[2*i+1].size());
        merge(range(tree[2*i]), range(tree[2*i+1]), tree[i].begin());
    }
}

int find(int left, int right, int k)
{
    // k번째 수보다 큰걸 모두 더한다
    
    int sum=0;
    left|=number;
    right|=number;
    while(left<=right)
    {
        if(left & 1)
            sum+=tree[left].end()-upper_bound(range(tree[left]), k); left++;
        if(~right & 1)
            sum+=tree[right].end() - upper_bound(range(tree[right]), k); right--;
        
        left>>=1;
        right>>=1;
    }
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    
    init();
    
    int query;
    cin>>query;
    
    int i, j, k;
    for(int p=0;p<query;p++)
    {
        cin>>i>>j>>k;
        cout<<find(i, j, k)<<'\n';
    }
    
    return 0;
    
}
