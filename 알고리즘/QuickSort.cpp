#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

void merge(vector<int>& arr, vector<int>& temp, int low, int mid, int high)
{
	int idx = low;
	int left = low;
	int right = mid + 1;
	int len = arr.size();
	while (left <= mid && right <= high)
	{
		if (arr[left] <= arr[right])
			temp[idx++] = arr[left++];
		else
			temp[idx++] = arr[right++];
	}

	// 남은 원소 갱신
	while (left<len && left <= mid)
		temp[idx++] = arr[left++];
	
	// 나머지 절반은 이미 올바른 위치, 갱신할 필요 없음

	//정렬된 결과를 원본에 반영
	for (int i = low; i <= high; i++)
		arr[i] = temp[i];

}

void Merge_Sort(vector<int>& arr, vector<int>& temp, int low, int high)
{
	for (int w = 1; w <= high - low; w *= 2)
	{
		// 처음에는 1개씩 merge하고 
		// 이후 2개 4개 ....merge함
		// 1개씩 merge
		// w =1 i=0, 2, 4, 6, 8, 10, ...
		// 2개씩 merge
		// w=2, i=0, 4, 8, 12...
		for (int i = low; i < high; i += 2 * w)
		{
			int left = i;
			int mid = i + w - 1;
			int right = min(i + 2 * w - 1, high); // To make sure right lower than the array size


			merge(arr, temp, left, mid, right);
		}
	}

}


void merge_recur(vector<int>& arr, int low, int mid, int high)
{
	int idx = low;
	int left = low;
	int right = mid + 1;
	int len = arr.size();
	vector<int> temp(len);

	while (left <= mid && right <= high)
	{
		if (arr[left] <= arr[right])
			temp[idx++] = arr[left++];
		else
			temp[idx++] = arr[right++];
	}

	while (left <= mid)
		temp[idx++] = arr[left++];
	while (right <= high)
		temp[idx++] = arr[right++];

	for (int k = low; k <= high; k++)
		arr[k] = temp[k];

}

void merge_sort_recur(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) >> 1;
		merge_sort_recur(arr, low, mid);
		merge_sort_recur(arr, mid + 1, high);
		merge_recur(arr, low, mid, high);
	}
}


int partition(vector<int>& arr, int low, int high)
{
	if (arr.empty() || low < 0)
		return -1;

	int i = low - 1;
	int pivotVal = arr[high];

	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivotVal)
		{
			
			swap(arr[++i], arr[j]);
		}
	}
	swap(arr[++i], arr[high]);

	return i;
}




void quicksort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}


int main()
{

	vector<int> res = { 22,21,16,-3,1000, 1, 10,14, 9, 5, 2, 8, 0,13 ,99,13,100 };
	int len = res.size();
	vector<int> tot = res;
	int low = 0;
	int high = len;


	cout << "Original" << endl;
	for (auto i : res)
		cout << i << " ";
	cout << endl;

	/*
	cout << "Merge Sort" << endl;
	Merge_Sort(res, tot, low, high - 1);
	for (auto i : res)
		cout << i << " ";
	cout << endl;
	*/
	cout << "Quick Sort" << endl;
	quicksort(res, low, high-1);
	for (auto i : res)
		cout << i << " ";
	cout << endl;


}
