#include <random>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <numeric>
#include <map>
using namespace std;





using msv = std::map<std::string, std::vector<char>>;





msv remove_duplicate_ids(const msv& obj) {


	map<char, int> temp;
	msv res;
	vector<char> res2;

	map<int, vector<char>, std::greater<int>> result;


	for (auto& it : obj)
		result[stoi(it.first)] = it.second;

	for (auto& i : result)
		cout << i.first << endl;


	for (auto it = result.begin(); it != result.end(); it++)
	{
		auto k = it->second;
		k.erase(unique(k.begin(), k.end()), k.end());
		for (auto i : k)
		{
			if (temp.find(i) == temp.end())
			{
				temp[i]++;
				res2.push_back(i);
			}
		}
		res[to_string(it->first)] = res2;
		res2.clear();

	}



	return res;
}

std::vector<int> each_num(std::string s) {
	//..
	vector<int> res;
	int upper = 0;
	int lower = 0;
	int number = 0;
	int special = 0;
	for (auto& i : s)
	{
		if (isupper(i))
			upper++;
		else if (islower(i))
			lower++;
		else if (isdigit(i))
			number++;
		else
			special++;
	}
	res.push_back(upper);
	res.push_back(lower);
	res.push_back(number);
	res.push_back(special);

	return res;
}

int casino(std::vector<int> v) {
	//..
	vector<int> res;
	res.push_back(v[0] + v[1]);
	res.push_back(v[0] + v[2]);
	res.push_back(v[1] + v[2]);
	res.push_back(floor((v[1] + v[2] + v[0]) / 2));

	return *min_element(v.begin(), v.end());
}

std::vector<long long> decompose(long long n)
{
	vector<long long> result;
	long long tot = 0;

	result.push_back(n);
	while (!result.empty())
	{
		tot += result[result.size() - 1] * result[result.size() - 1];
		auto cur = result[result.size() - 1];
		result.pop_back();

		for (long long i = cur - 1; i >= 1; i--)
		{
			if (tot - i * i >= 0)
			{
				result.push_back(i);

				tot -= i * i;
				if (tot == 0)
				{
					reverse(result.begin(), result.end());
					return result;
				}
			}
		}

	}



	return {};
}



std::string longestConsec(std::vector<std::string>& strarr, int k)
{
	int size = strarr.size();
	if (size == 0 || k > size || k <= 0)
		return "";


	string res = "";
	string temp;
	for (int i = 0; i < size; i++)
	{
		temp = "";
		for (int j = i; j < i + k && j < size; j++)
		{
			temp += strarr[j];
		}
		if (res.size() < temp.size())
			res = temp;
	}
	return res;
}

//BEST
std::string longestConsec2(std::vector<std::string>& strarr, int k)
{
	int size = strarr.size();
	k = max(0, k);
	string res;

	for (size_t i = k; i <= size; i++)
	{
		auto first = std::next(strarr.begin(), i - k);
		auto end = std::next(first, k);
		string s = accumulate(first, end, string());
		if (s.size() > res.size())
			res = s;
	}


	return res;
}