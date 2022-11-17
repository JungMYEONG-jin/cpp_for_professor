#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <set>
#include <numeric>
#include <cmath>
#include <stack>

#define INF 1000000000

using namespace std;

long long getPair(vector<int>& res, double base, int idx)
{
	int left = 0;
	int right = idx - 1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (res[mid] < base * 0.9) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}
	return idx - left;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, num;
	cin >> n;
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		cin >> res[i];
	}
	long long ans = 0;
	sort(res.begin(), res.end());
	for (int i = 1; i < n; i++) {
		ans += getPair(res, res[i], i);
	}
	cout << ans << endl;

    return 0;

}
// 2335
