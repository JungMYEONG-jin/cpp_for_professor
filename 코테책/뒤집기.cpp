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
	string res;
	cin >> res;
	res.erase(unique(res.begin(), res.end()),res.end());

	int cnt1 = count(res.begin(), res.end(), '1');
	int cnt0 = count(res.begin(), res.end(), '0');

	cout << (cnt1 < cnt0 ? cnt1 : cnt0) << endl;

}
