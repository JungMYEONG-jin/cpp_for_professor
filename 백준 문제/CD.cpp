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
	while (true) {
		int ans = 0;
		cin >> n;
		cin >> m;
		if (n == 0 && m == 0)
			break;
		vector<int> left(n);
		vector<int> right(n);
		int num;
		for (int i = 0; i < n; i++)
		{
			cin >> left[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> right[i];
		}
		int idxL = 0;
		int idxR = 0;
		while (true) {
			if (idxL == n || idxR == m)
				break;
			if (left[idxL] > right[idxR]) {
				idxR++;
			}
			else if (left[idxL] < right[idxR]) {
				idxL++;
			}
			else {
				idxR++;
				idxL++;
				ans++;
			}
		}


		cout << ans << endl;
	}

    return 0;

}
// 2335
