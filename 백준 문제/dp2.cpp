#include <iostream>


using namespace std;

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int tile[1000001];

tile[1]=1;
tile[2]=2;

int n;
cin>>n;


for(int i=3;i<=n;i++)
{
tile[i]=(tile[i-1]+tile[i-2])%15746;
}

cout<<tile[n]%15746;

}
