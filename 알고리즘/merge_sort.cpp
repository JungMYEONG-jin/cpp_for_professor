#include <vector>
#include <iostream>

using namespace std;


void merge(vector<int>& arr, vector<int>& temp, int low, int mid, int high)
{

int idx = low;
int i = low;
int j = mid+1;

while(i<=mid && j<=high)
{

	if(arr[i]<=arr[j])
	{
	 temp[idx++] = arr[i++];
	}else
	{

	 temp[idx++] = arr[j++];
	}


}


while(i<=mid)
	temp[idx++] = arr[i++];

while(j<=high)
	temp[idx++] = arr[j++];


for(int k=low;k<=high;k++)
	arr[k] = temp[k];

}


void MergeSort(vector<int>& arr, vector<int>& temp, int low, int high)
{

if(low<high)
{

int mid = (low+high)>>1;

MergeSort(arr,temp, low, mid);
MergeSort(arr,temp,  mid+1, high);

merge(arr, temp, low, mid, high);


}

}








int main()
{

vector<int> res = {1, 13,0,-3, 22, 99, 11};

cout<<"정렬전"<<endl;

for(auto i : res)
	cout<<i<<" ";
cout<<endl;

int len = res.size();
vector<int> temp(len);
MergeSort(res, temp, 0, len-1);

cout<<"정렬후"<<endl;

for(auto i : res)
	cout<<i<<" ";
cout<<endl;




}

