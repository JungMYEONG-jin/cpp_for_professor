#include <vector>

using namespace std;

int minCoins(vector<int>& arr, int m, int V)
{
	
	if (V == 0) return 0;

	
	int res = INT_MAX;

	for (int i = 0; i < m; i++)
	{
		if (arr[i] <= V)
		{
			int sub_res = minCoins(arr, m, V - arr[i]);

		
			if (sub_res != INT_MAX && sub_res + 1 < res)
				res = sub_res + 1;
		}
	}
	return res;
}
