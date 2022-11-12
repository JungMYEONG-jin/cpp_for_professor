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

	int n;
	cin >> n;
	int arr[200001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int maxVal = -1;
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		maxVal = max(maxVal, arr[i]);
		ans = max(maxVal - arr[i], ans);
	}
	cout << ans << endl;


    return 0;

}
