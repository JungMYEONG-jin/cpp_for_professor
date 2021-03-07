#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


bool bin_search(vector<int>& arr, int m)
{

int len = arr.size();

int left = 0;
int right = len-1;
while(left<=right)
{

int mid = (left+right)/2;

if(arr[mid]==m)
{
return true;
}
else if(arr[mid]<m)
{
left= mid+1;
}else
{
right = mid-1;

}


}

return false;

}







int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


int n;
cin>>n;
vector<int> arr(n);

for(int i=0;i<n;i++)
	cin>>arr[i];
sort(arr.begin(), arr.end());


int m;
cin>>m;
int x;
for(int i=0;i<m;i++)
{
	cin>>x;
	cout<<bin_search(arr,x)<<'\n';
}
return 0;



}
