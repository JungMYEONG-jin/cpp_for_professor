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

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		cin >> res[i];
	}
	int left = *max_element(res.begin(), res.end());
	int right = accumulate(res.begin(), res.end(), 0);
	
	while (left <= right) {
		int mid = (left + right) >> 1;
		int cnt = 0;
		int sum = 0;
		for (auto val : res) {
			if (sum + val > mid) {
				sum = 0;
				cnt++;
			}
			sum += val;
		}
		if (sum != 0) {
			cnt++;
		}

		if (cnt > m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left << endl;
    return 0;

}
// 2335
