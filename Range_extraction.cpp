#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <array>
#include <functional>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

string range_extraction(vector<int> v)
{
	v.resize(v.size() + 1);
	string res = "";
	bool isRange = false;
	for (int i = 0; i < v.size(); i++)
	{
		int j = v[i];
		if (i<v.size()-1 &&v[i + 1] != j + 1)
		{
			if (isRange) res += (v[i] == v[i - 2] + 2) ? "-" : ",";
			res += to_string(j) + ",";
			isRange = false;
		}
		else if (!isRange)
		{
			res += to_string(j);
			isRange = true;
		}
	}
	res.erase(res.size() - 2, 2);
	return res;
}

string range_extraction2(vector<int> v)
{
	using Range = std::pair<int, int>;
	string res = "";
	vector<Range> result;

	for (auto p : v)
	{
		if (   result.empty() ||    p != result.back().second + 1)
			result.push_back({ p,p });
		else
			++result.back().second;
	}

	for (auto i : result)
	{
		if (i.first == i.second)
		{
			res += to_string(i.first) + ",";
		}
		else
		{
			res += to_string(i.first) + ((i.first + 1 == i.second) ? "," : "-") + to_string(i.second) + ",";
		}
	}

	res.pop_back();
	return res;

}



int main()
{
	cout << range_extraction({ -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20
		}) << endl;



	cout << range_extraction2({ -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20
		}) << endl;

	
}