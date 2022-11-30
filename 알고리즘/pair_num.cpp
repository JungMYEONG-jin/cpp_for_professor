#include <vector>
#include <string>
#include <iostream>



using namespace std;

//MyCode
template<typename T>
vector<pair<T, T>> get_pair_vector(vector<T>& data)
{
	vector<pair<T, T>> res;

	if (data.size() % 2 != 0)
		data.pop_back();


	for (int i = 0; i < data.size(); i += 2)
	{
		res.push_back(make_pair(data[i], data[i + 1]));
	}

	return res;


}


template<typename Input, typename OutPut>
void pair_wise(Input begin, Input end, OutPut result)
{
	auto it = begin;
	while (it != end)
	{
		auto v1 = *it++; if (it == end) break;
		auto v2 = *it++;
		result++ = make_pair(v1, v2);
	}


}

template<typename T>
vector<pair<T, T>> pair_wise(vector<T> const& data)
{
	vector<pair<T, T>> res;
	pair_wise(data.begin(), data.end(), back_inserter(res));

	return res;
}


int main()
{
	vector<int> data{ 1,1,3,5,8,13,21 };

	auto res = get_pair_vector(data);

	for (auto& i : res)
	{
		cout << i.first << ' ' << i.second << endl;
	}

	vector<int> data2{ 1,1,3,5,8,13,21,88 };

	auto res2 = get_pair_vector(data2);

	for (auto& i : res2)
	{
		cout << i.first << ' ' << i.second << endl;
	}

	auto res3 = pair_wise(data2);

	for (auto& i : res3)
	{
		cout << i.first << ' ' << i.second << endl;
	}
}