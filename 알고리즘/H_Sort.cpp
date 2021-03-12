#include <iostream>


using namespace std;

int main()
{
{
	// h sort ascending

	int arr[10] = { 8, 9, 11, 3, 1, 19,2,7,14,15 };

	int len = sizeof(arr) / sizeof(int);


	cout << "h sort 오름차순 정렬전\n\n";
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << "\n\nh sort 오름차순 정렬후\n\n";

	int h = 1;

	while (h < len / 3) h = 3 * h + 1;

	while (h >= 1)
	{
		for (int i = h; i < len; i++)
		{
			for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h)
			{
				swap(arr[j], arr[j - h]);
			}
		}

		h /= 3;
	}




	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;

}

{
	// h sort descending

	int arr[10] = { 8, 9, 11, 3, 1, 19,2,7,14,15 };

	int len = sizeof(arr) / sizeof(int);

	cout << "h sort 내림차순 정렬전\n\n";
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << "\n\nh sort 내림차순 정렬후\n\n";

	int h = 1;

	while (h < len / 3) h = 3 * h + 1;

	while (h >= 1)
	{
		for (int i = h; i < len; i++)
		{
			for (int j = i; j >= h && arr[j] > arr[j - h]; j -= h)
			{
				swap(arr[j], arr[j - h]);
			}
		}

		h /= 3;
	}




	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;

}
}
