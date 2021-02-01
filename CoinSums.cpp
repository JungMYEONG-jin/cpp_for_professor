#include <iostream>

using namespace std;

int main()
{

int T,k;
cin>>T>>k;


int coin[101];
int res[10001];
fill(res+1, res+10001, 0);
res[0]=1;


for(int i=1;i<=T;i++)
  cin>>coin[i];

for(int i=1;i<=T;i++)
{
for(int j=i;j<=k;j++)
{
if(j>=coin[i])
  res[j]+=res[j-coin[i]];

}



}


cout<<res[k]<<endl;








}
