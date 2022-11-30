#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

// MyCode
template<template<class...> class Container, typename T>
map<T, int> find_freq_variable(Container<T> cont)
{
	int count = 0;
	map<T, int> res{};
	

	for (auto& i : cont)
	{
		res[i]++;
	}

	auto max = max_element(res.begin(), res.end(), [](auto const& e1, auto const& e2) {return e1.second < e2.second; });
	map<T, int> data{};
	for (auto& i : res)
	{
		if (i.second == max->second)
			data[i.first] = i.second;
	}

	return data;

}



// BookCode
template<typename T>
vector<std::pair<T, size_t>> find_most_freq(vector<T> const& range)
{
	map<T, size_t> counts{};

	for (auto const& e : range)
		counts[e]++;
	
	auto max = std::max_element(cbegin(counts), cend(counts), [](auto const& e1, auto const& e2) {return e1.second < e2.second; });

	vector<std::pair<T, size_t>> res;

	std::copy_if(begin(counts), end(counts), back_inserter(res), [max](auto const& k) {return k.second == max->second; });

	return res;
}



int main()
{
	vector<int> data{ 1,1,3,5,8,13,3,5,8,8,5 };
	auto res = find_freq_variable(data);
	
	int data2[10] = { 1,2,1,1,1,1,8,9,7,3 };

	

	for (auto& i : res)
		cout<<i.first << ' ' << i.second << endl;

	auto res1 = find_most_freq(data);

	for (auto& i : res1)
	{
		cout << i.first << ' ' << i.second << endl;
	}



}