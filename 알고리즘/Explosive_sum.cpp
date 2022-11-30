#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

ll get_sum(ll n)
{

if(n<0)
  return 0;


vector<ll> res(n+1, 0);

res[0]=1;

for(int i=1;i<=n;i++)
{
    for(int j=i;j<=n;j++)
    {
        res[j]+=res[j-i];
    }
    
    
    
    
}

return res[n];

}

int main()
{
    
    
    
    
    cout<<get_sum(1)<<endl;
    cout<<get_sum(2)<<endl;
    cout<<get_sum(4)<<endl;
    cout<<get_sum(10)<<endl;
    cout<<get_sum(50)<<endl;
    cout<<get_sum(100)<<endl; //190569292
}
