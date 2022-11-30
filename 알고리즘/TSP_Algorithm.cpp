#include <iostream>

using namespace std;

int city[16][16];
int dp[16][1<<16];
int n;
int inf = 1e9+1;
int tsp(int cur, int visited)
{
    
    if(visited == (1<<n)-1)
    {
        if(city[cur][0]==0)
            return inf;
        return city[cur][0];
    }
    
    if(dp[cur][visited]!=0)
        return dp[cur][visited];
    
    dp[cur][visited] = inf;
    
    for(int i=0;i<n;i++)
    {
        int next = 1<<i;
        
        if(city[cur][i]==0 || (visited & next)>0)
            continue;
        
        dp[cur][visited] = min(dp[cur][visited], tsp(i, visited | next )+city[cur][i]);
        
    }
    
    return dp[cur][visited];
    
    
}



void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>city[i][j];
    }
    
    cout<<tsp(0, 1);
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
    
    
    
    
    
}
