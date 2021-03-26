#include <iostream>
#include <vector>


using namespace std;

int cnt=0;

void merge(vector<int>& arr, vector<int>& temp, int low, int mid, int high)
{


int idx = low;
int i=low;
int j=mid+1;
//int len = arr.size();
while(i<=mid && j<=high)
{

if(arr[i]<=arr[j])
{
temp[idx++] = arr[i++];

}else
{
cnt+=(mid-i+1);
temp[idx++] = arr[j++];
}


}


while(i<=mid)
	temp[idx++]=arr[i++];

while(j<=high)
	temp[idx++]=arr[j++];

for(int k=low;k<=high;k++)
	arr[k] = temp[k];

}



void Merge_sort(vector<int>& arr, vector<int>& temp, int low, int high)
{

if(low<high)
{

int mid = (low+high)>>1;
Merge_sort(arr, temp, low, mid);
Merge_sort(arr, temp, mid+1, high);

merge(arr, temp, low, mid ,high);


}

}





int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


int n;
cin>>n;

vector<int> res(n);

for(int i=0;i<n;i++)
	cin>>res[i];

auto temp = res;
int high = n;
int low = 0;
int mid = n>>1;


Merge_sort(res, temp, low, high-1);

cout<<cnt;








}
