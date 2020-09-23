#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


template<typename Container, typename value_type = typename Container::value_type >
vector<vector<value_type>> Combination(Container cont, unsigned int r)
{
	int n = cont.size();
	if (r == 0) return{};
	if (n < r) return{};


	vector<vector<value_type>> tot;
	vector<value_type> temp(r);

	vector<bool> bitmask(n);

	fill(bitmask.end() - r, bitmask.end(), true);
	int idx;

	do
	{
		idx = 0;
		for (int i = 0; i < n; ++i)
		{
			if (bitmask[i])
				temp[idx++] = *(cont.begin() + i);
		}
		tot.push_back(temp);
	} while (next_permutation(bitmask.begin(), bitmask.end()));
	return tot;
}

int chooseBestSum(int t, int k, vector<int>& ls)
{
	int bestsum = 0;
	int size = ls.size();
	if (size < k)
		return -1;

	auto kk = Combination(ls, k);

	for (auto& vec : kk)
	{
		int sum = accumulate(vec.begin(), vec.end(), 0);
		if (bestsum <= sum && sum <= t)
			bestsum = sum;
	}

	if (bestsum == 0)
		return -1;
	return bestsum;

}



/*


template<typename Container_, typename value_type = int>
std::vector<std::vector<value_type> > Combination(Container_ container, int r) {
	int n = container.size();
	if (n < r) return {};
	if (r < 0) return {};

	std::vector<std::vector<value_type> >totVec;//return 2d-vector
	std::vector<value_type> tempVec(r);//saves temporary combination

	std::vector<bool> v(n);
	std::fill(v.end() - r, v.end(), true);
	int idx;
	do {
		idx = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i]) {
				tempVec[idx++] = *(container.begin() + i);
			}
		}
		totVec.push_back(tempVec);
	} while (std::next_permutation(v.begin(), v.end()));

	return totVec;
}

int chooseBestSum(int t, int k, std::vector<int>& ls)
{

	//int total = accumulate(ls.begin(), ls.end(),0);
	if (ls.size() < k)
		return -1;


	int bestsum = 0;
	sort(ls.begin(), ls.end());
	for (auto& vec : Combination(ls, k)) {

		int sum = accumulate(vec.begin(), vec.end(), 0);
		if (bestsum <= sum && sum <= t)
		{
			bestsum = sum;

		}

	}

	if (bestsum == 0)
		return -1;


	return bestsum;

}
*/

int main()
{
	std::vector<int> ts = { 50, 55, 56, 57, 58 };
	int n = chooseBestSum(163, 3, ts);
	cout << n << endl;



	ts = { 50 };
	n = chooseBestSum(163, 3, ts);
	cout << n << endl;
	ts = { 91, 74, 73, 85, 73, 81, 87 };
	n =chooseBestSum(230, 3, ts);
	cout << n << endl;
	n =chooseBestSum(331, 2, ts);
	cout << n << endl;
	n = chooseBestSum(331, 4, ts);
	cout << n << endl;
	n = chooseBestSum(331, 5, ts);
	cout << n << endl;
	n =chooseBestSum(331, 1, ts);
	cout << n << endl;
	n = chooseBestSum(700, 8, ts);
	cout << n << endl;
}