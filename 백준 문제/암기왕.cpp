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
	
	int t, n, m, num;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> res(n);
		for (int i = 0; i < n; i++)
		{
			cin >> res[i];
		}
		sort(res.begin(), res.end());
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> num;
			if (binary_search(res.begin(), res.end(), num))
				cout << "1\n";
			else
				cout << "0\n";
		}
	}

    return 0;

}
// 2335
