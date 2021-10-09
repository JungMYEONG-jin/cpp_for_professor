#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

#define INF 999999999

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> res(n);
	for (int i = 0; i < n; i++)
		cin >> res[i];

	sort(res.begin(), res.end());
	int target = 1;
	for (auto i : res)
	{
		if (target < i)
			break;
		target += i;
	}
	cout << target << endl;
}
