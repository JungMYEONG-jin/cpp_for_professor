#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;





vector<int> solve(vector<int>& vec) {
	//..

	map<int, int> res;
	for (int i : vec)
		res[i]++;

	sort(vec.begin(), vec.end(), [&res](int i, int j) { return res[i] > res[j] || (res[i] == res[j] && i < j); });
	return vec;
}

int main()
{
	vector<int> a{ 2,3,5,3,7,9,5,3,7 };
	solve(a);
	for (auto const& i : a)
		cout << i << " ";




}