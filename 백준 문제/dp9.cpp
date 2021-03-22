#include <iostream>
#include <vector>

using namespace std;


int main()
{

int n;
cin>>n;

int asc[n+1];
int desc[n+1];

int arr[n+1];


fill(asc, asc+n+1,1);
fill(desc, desc+n+1,1);


for(int i=0;i<n;i++)
	cin>>arr[i];

int total=0;
for(int i=0;i<n;i++)
{

int val = arr[i];

for(int j=0;j<i;j++)
{
	if(val>arr[j])
		asc[i] = max(asc[i], asc[j]+1);
	if(arr[n-i-1]>arr[n-j-1])
		desc[n-i-1] = max(desc[n-i-1], desc[n-j-1]+1);
}


}


for(int i=0;i<n;i++)
	total = max(total, asc[i]+desc[i]-1);








cout<<total<<endl;


}
