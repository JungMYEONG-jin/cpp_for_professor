#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

using namespace std;

vector<int> dp;
long long total;

void left_sum(int i, int weight, int half, map<int, int>& m)
{
    if(i==half)
    {
        m[weight]++;
        return ;
    }
    
    left_sum(i+1, weight, half, m);
    left_sum(i+1, weight+dp[i], half, m);
}

void right_sum(int i, int weight, int end, map<int, int>& m, long long& cnt)
{
    
    if(i==end)
    {
        cnt+=m[total-weight];
        return;
    }
    right_sum(i+1, weight, end, m, cnt);
    right_sum(i+1, weight+dp[i], end, m, cnt);
    
    
    
}

int main()
{
    int n;
    cin>>n>>total;
    
    dp.resize(n);
    for(int i=0;i<n;i++)
        cin>>dp[i];
    long long cnt=0;
    
    int half = n>>1;
    map<int, int> m;
    left_sum(0,0, half, m);
    right_sum(half, 0, n, m, cnt);
    if(total==0)
        cnt--;
    cout<<cnt;
}
