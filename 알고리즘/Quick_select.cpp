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

int quick_select(vector<int>& arr, int k)
{
	int right = arr.size() - 1;
	int left = 0;

	while (right > left)
	{
		int j = partition(arr, left, right);
		if (j < k)
			left = j + 1;
		else if (j > k)
			right = j - 1;
		else
			return arr[k];
	}

	return arr[k];
}
