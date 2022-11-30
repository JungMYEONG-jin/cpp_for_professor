#include <queue>
#include <iostream>


using namespace std;


int main()
{

int N, k;
cin>>N>>k;
queue<int> res;
for(int i=1;i<=N;i++)
	res.push(i);

int num;
cout<<"<";
while(!res.empty())
{


for(int i=0;i<k-1;i++)
{
num = res.front();
res.pop();
res.push(num);

}
num = res.front();
res.pop();
if(res.size()>0)
	cout<<num<<", ";
else
	cout<<num<<">";




}

return 0;


}
