#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{


int n,k;
cin>>n>>k;

deque<int> res;

for(int i=1;i<=n;i++)
{

res.push_back(i);

}





int x;
int cnt=0;
for(int i=0;i<k;i++)
{
cin>>x;

if(res.front()==x)
{
res.pop_front();
continue;

}

int j = find(res.begin(), res.end(), x)-res.begin();


if(j<res.size()-j)
{

while(j)
{
cnt++;
res.push_back(res.front());
res.pop_front();

j--;

}
res.pop_front();


}else
{

int k = res.size()-j;
while(k)
{

cnt++;
res.push_front(res.back());
res.pop_back();
k--;

}


res.pop_front();
}


}







cout<<cnt<<endl;



}
