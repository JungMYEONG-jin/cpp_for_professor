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
	int n, m;
	cin >> n >> m;
	vector<int> res(n);
	for (int i = 0; i < n; i++)
		cin >> res[i];
	int ori_len = res.size();
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	int len = res.size();


	cout << (n * (n - 1)) / 2 - (ori_len - len) << endl;

}
