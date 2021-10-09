#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>
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
	int result = 0;
	int cnt = 0;
	for (auto i : res)
	{
		cnt += 1;
		if (cnt >= i)
		{
			result += 1;
			cnt = 0;
		}
	}
	cout << result << endl;
}
