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
	cin >> n;
	vector<int> res(n);
	for (int i = 0; i < n; i++)
		cin >> res[i];
	sort(res.begin(), res.end());
	cin >> m;
	vector<int> check(m);
	for (int i = 0; i < m; i++)
		cin >> check[i];

	int elen = res.size();
	for (auto i : check) // bin search 
	{
		int start = 0;
		int end = elen;
		bool flag = false;
		while (start < end)
		{
			int mid = (start + end) >> 1;
			if (res[mid] < i)
				start = mid + 1;
			else if (res[mid] == i)
			{
				flag = true;
				break;
			}
			else
				end = mid - 1;
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	

}
