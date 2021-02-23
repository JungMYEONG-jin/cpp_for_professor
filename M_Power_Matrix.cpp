// 행렬의 거듭제곱을 빠르게 표현하는 알고리즘

// 행렬의 거듭제곱을 빠르게 표현하는 알고리즘

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;


vector<vector<ll>> multiple(vector<vector<ll>>& a, vector<vector<ll>>& b)
{

    // equal sizeof
    int len  = a.size();
    vector<vector<ll>> res(len, vector<ll>(len));
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            for(int k=0;k<len;k++)
            {
                res[i][j] += a[i][k]*b[k][j];
            }
            res[i][j]%=1000;
        }
    }
    return res;


}


vector<vector<ll>> power_matrix(vector<vector<ll>>& a, ll m)
{
    int len = a.size();
    vector<vector<ll>> res(len, vector<ll>(len));
    
    for(int i=0;i<len;i++)
        res[i][i]=1;
        
        
    while(m>0)
    {
        if(m%2==1)
        {
            res = multiple(res, a);
        }
        m/=2;
        a = multiple(a, a);
    }
    return res;
    
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int n; ll m;
    cin>>n>>m;
    
    vector<vector<ll>> a(n, vector<ll>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    
    auto res = power_matrix(a, m);
    
    for(auto i : res)
    {
        for(auto j : i)
            cout<<j<<" ";
        cout<<'\n';
    }
    
    
    
    return 0;
}
