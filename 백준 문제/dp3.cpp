#include <iostream>
#include <vector>


using namespace std;

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


int n;

int r, g, b;
cin>>n;
int res[n+1][3];
res[0][0]=0;
res[0][1]=0;
res[0][2]=0;
for(int i=1;i<=n;i++)
{
cin>>res[i][0]>>res[i][1]>>res[i][2];

}

// r g b 3 cases

int rgb[n+1][3];
rgb[0][0]=0;
rgb[0][1]=0;
rgb[0][2]=0;

for(int i=1;i<=n;i++)
{
rgb[i][0]=min(rgb[i-1][1], rgb[i-1][2])+res[i][0];
rgb[i][1]=min(rgb[i-1][0], rgb[i-1][2])+res[i][1];
rgb[i][2]=min(rgb[i-1][0], rgb[i-1][1])+res[i][2];
}


cout<<min(rgb[n][0], min(rgb[n][1], rgb[n][2]));


}
