#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{

vector<int> res(10);


for(int i=0;i<10;i++)
	cin>>res[i];
int f;
cin>>f;

for(int i=0;i<10;i++)
{
for(int j=i;j>0;j--)
{
if(res[j]<res[j-1])
	swap(res[j], res[j-1]);
else
	break;
}

}

for(auto i : res)
	cout<<i<<" ";
cout<<endl;

cout<<find(res.begin(), res.end(), f)-res.begin()+1<<endl;




}
