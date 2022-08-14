#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>

#define INF (long long)1e15

using namespace std;

int maxVal = -1000000000;
int minVal = 1000000000;
int Plus, Minus, divide, multi;

int ans = 0;
int n;

void dfs(vector<int> arr, int sum) {

	int len = arr.size();

	if (len == 2) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 1; i < len - 1; i++) {
		int num = arr[i];
		vector<int> temp = arr;
		temp.erase(temp.begin() + i);
		dfs(temp, (arr[i - 1] * arr[i + 1]) + sum);
		temp.insert(temp.begin() + i, num);
	}
	
}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> temp(n);
	for (int i = 0; i < n; i++)
		cin >> temp[i];
	
	dfs(temp, 0);
	
	cout << ans << endl;



	return 0;

}
