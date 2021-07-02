# 백준 고난이도 배낭문제.
1. Divide and Conquer Opt 방법을 사용해야함.
2. 구현이 상당히 까다로웠음.


```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;
const long long inf = -1e18;
long long dp[305][100005];
vector<vector<long long>> prevs(301);
vector<vector<long long>> temp(301);
void knapsack(int w, int start, int end, int opt_start, int opt_end, int offset)
{
    if(start>end) return;
    int mid = (start+end)>>1;
    
    long long &ans = dp[w][mid*w+offset];
    ans = inf;
    int opt_mid = opt_end;
    
    for(int i=opt_start;i<=min(mid, opt_end);++i)
    {
        if(mid-i>static_cast<int>(temp[w].size()))
            continue;
        long long t = dp[w-1][i*w+offset]+prevs[w][mid-i];
        if(ans<t)
        {
            ans = t;
            opt_mid = i;
        }
    }
    knapsack(w, start, mid-1, opt_start, opt_mid, offset);
    knapsack(w, mid+1, end, opt_mid, opt_end, offset);
    
    
    
}




int main()
{
    
    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    
    int n,W;
    cin>>n>>W;
  
    
    for(int i=0;i<n;i++)
    {
        long long w, value;
        cin>>w>>value;
        temp[w].push_back(value);
     }
    
    for(int i=1;i<=300;i++)
        sort(temp[i].begin(), temp[i].end(), [](auto e, auto k){return e>k;});
    //  desc
    
    for(int i=1;i<=300;i++)
    {
        prevs[i].push_back(0);
        for(int j=1;j<=static_cast<int>(temp[i].size());j++)
        {
            prevs[i].push_back(prevs[i][j-1]+temp[i][j-1]);
        }
    }
    
    for(int i=1;i<=300;i++)
        for(int j=0;j<i;j++)
            knapsack(i, 0, (W-j)/i, 0, (W-j)/i, j);
    
    vector<long long> answer(W+1);
    for(int i=1;i<=300;i++)
        for(int j=1;j<=W;j++)
            answer[j] = max(answer[j], dp[i][j]);
    
    
    for(int i=1;i<=W;i++)
        cout<<answer[i]<<" \n"[i==W];
    
    return 0;
    
}

```
