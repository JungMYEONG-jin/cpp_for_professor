#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;


string lcs(const string& x, const string& y) {
    if (x.length() == 0 || y.length() == 0) return "";
    int n = x.length(), m = y.length();

    auto dp = vvs(n + 1, vs(m + 1, ""));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (x[i-1] == y[j-1]) dp[i][j] = dp[i-1][j-1] + string(1, x[i-1]);
            else dp[i][j] = dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j] : dp[i][j-1];
        }
    }

    return dp[n][m];
}


int main()
{
    string a,b;
    cin>>a>>b;
    
    string k = lcs(a,b);
    if(k.empty())
    {
        cout<<0<<endl;
        return 0;
    }
    
    cout<<k.size()<<'\n'<<k<<endl;
    
    
    
}
