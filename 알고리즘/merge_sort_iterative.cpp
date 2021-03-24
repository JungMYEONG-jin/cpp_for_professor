#include <vector>
#include <iostream>


using namespace std;


void merge(vector<int>& arr, vector<int>& temp, int low, int mid ,int high)
{

int i = low;
int j = mid+1;
int idx = low;

int len = arr.size();
while(i<=mid && j<=high)
{

if(arr[i]<=arr[j])
	temp[idx++] = arr[i++];
else
	temp[idx++] = arr[j++];


}

while(i<len && i<=mid)
	temp[idx++] = arr[i++];


for(int k=low;k<=high;k++)
{

 arr[k] = temp[k];

}


}


void MergeSort_iter(vector<int>& arr, vector<int>& temp, int low, int high)
{

	for(int w=1;w<=high-low;w*=2)
	{

	 for(int i=low;i<high;i+=2*w)
	{
		int left = i;
		int mid = i+w-1;
		int right = min(i+2*w-1, high);
		
		merge(arr, temp, left, mid, right);

	}






	}


}





int main()
{


vector<int> res = {21, 10, 12, 20, 25, 13, 15, 22};

int len = res.size();

vector<int> temp = res;


cout<<"정렬전"<<endl;

for(auto i : res)
	cout<<i<<" ";
cout<<endl;

MergeSort_iter(res, temp, 0, len-1);

cout<<"정렬후"<<endl;

for(auto i : res)
	cout<<i<<" ";
cout<<endl;






}







