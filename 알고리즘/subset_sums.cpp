#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

using namespace std;


bool promisings(vector<int>& w, int i, int weight, int total, int target)
{
	if (total + weight >= target && (target == weight || weight + w[i + 1] <= target))
		return true;
	return false;
}

void prints(vector<int>& arr)
{
	for (auto i : arr)
		if (i != 0)
			cout << i << " ";
	cout << '\n';
}

void subset_sums(vector<int>& w,vector<int>& aux, int i, int weight, int total, int target)
{
	if (promisings(w, i, weight, total, target))
	{
		if (weight == target)
			prints(aux);
		else
		{
			aux[i + 1] = w[i+1];
			subset_sums(w,aux, i + 1, weight + w[i+1], total - w[i+1], target);
			aux[i + 1] = 0;
			subset_sums(w,aux, i + 1, weight, total - w[i+1], target);
		}
	}
}

int main()
{
	vector<int> w{ 5,6,10,11,16 };
	int W = 21;
	int total = accumulate(w.begin(), w.end(), 0);
	vector<int> res(w.size(), 0);

	subset_sums(w, res, -1, 0, total, W);
}
