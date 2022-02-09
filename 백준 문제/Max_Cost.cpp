#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    
    int coin[1001]={0,};
    long res[1001]={0,};
    for(int i=1;i<=t;i++)
        cin>>coin[i];
  
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=i;j++)
        {
            res[i] = max(res[i], res[i-j]+coin[j]);
        }
    }
    
    cout<<res[t]<<endl;
}
