#include <iostream>
#include <vector>

using namespace std;


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
int n, k;

    cin>>n>>k;
    
    vector<pair<int, int>> jew(n+1);
    
    for(int i=1;i<=n;i++)
        cin>>jew[i].first>>jew[i].second;
    
    vector<int> dp(k+1);
    
    for(int i=1;i<=n;i++)
    {
        for(int j=k;j>=1;j--)
        {
            if(jew[i].first<=j)
            {
                dp[j] = max(dp[j], dp[j-jew[i].first]+jew[i].second);
            }
        }
    }





cout<<dp[k];


}
