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


vector<int> solution(vector<int> price) {
	vector<int> ans(price.size());
	stack<int> res;
	for (int i = 0; i < price.size(); i++) {
		while (!res.empty() && price[res.top()] < price[i]) {
			ans[res.top()] = i - res.top();
			res.pop();
		}

		res.push(i);
	}

	while (!res.empty()) {
		ans[res.top()] = -1;
		res.pop();
	}
	return ans;
}

vector<int> arr;
bool visited[21];
void dfs(int idx, int cnt) {
	if (cnt == 6) {
		int idx = 0;
		for (auto i : arr) {
			if(visited[idx++])
				cout << i << " ";
		}
		return;
	}

	for (int i = idx; i < arr.size(); i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		dfs(i, cnt + 1);
		visited[i] = false;
	}
}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n;
	cin >> m;
	vector<int> res(m);
	for (int i = 0; i < m; i++) { cin >> res[i]; }
	int start = 1;
	int end = 1000000;
	int ans = 1000000;
	while (start <= end) {
		int mid = (start + end) >> 1;
		bool isFlag = true;
		if (res[0] > mid)
			isFlag = false;
		for (int i = 0; i < m - 1; i++) {
			if (res[i + 1] - res[i] > 2 * mid) {
				isFlag = false;
				break;
			}
		}

		if (n - res[m - 1] > mid)
			isFlag = false;


		if (!isFlag) {
			start = mid + 1;
		}
		else {
			ans = min(ans, mid);
			end = mid - 1;
		}

		
	}
	cout << ans << endl;

    return 0;

}
// 2335
