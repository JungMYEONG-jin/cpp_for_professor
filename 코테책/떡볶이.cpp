#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>

using namespace std;



int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> res(n);
	for (int i = 0; i < n; i++)
		cin >> res[i];

	sort(res.begin(), res.end());
	int start = 0;
	int end = res.back();
	int mval = 0;
	while (start <= end)
	{
		int mid = (start + end) >> 1;
		int sum = 0;
		for (auto& i : res)
		{
			if (i > mid)
				sum += (i - mid);
		}
		if (sum < m)
			end = mid - 1;
		else
		{
			start = mid + 1;
			mval = max(mval, mid);
		}
	}

	cout << mval << endl;
	
	

}
