#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// MyCode
template<typename T, typename S>
vector<pair<T, S>> pair_wise_with_two_structure(vector<T> const& data, vector<S> const& data2)
{
	auto length = min(data.size(), data2.size());

	vector<pair<T, S>> res;
	int i = 0;

	while (i < length)
	{
		res.push_back(pair(data[i], data2[i]));
		i++;
	}

	return res;
}


template<typename Input, typename Input2, typename OutPut>
void pair_wise_two(Input begin, Input end, Input2 begin2, Input2 end2, OutPut result)
{
	auto it = begin;
	auto it2 = begin2;

	auto length = min((end - begin), (end2 - begin2));
	int i = 0;
	while (i < length)
	{
		auto v1 = *it++;
		auto v2 = *it2++;
		result++ = make_pair(v1, v2);
		i++;
	}


}

template<typename T, typename S>
vector<pair<T, S>> pair_wise_two(vector<T> const& data, vector<S> const& data2)
{
	vector<pair<T, S>> res;
	pair_wise_two(data.begin(), data.end(), data2.begin(), data2.end(), back_inserter(res));

	return res;
}


//------------------------------------------------------------------------------


// Book Code

template<typename Input1, typename Input2, typename Output>
void zip(Input1 begin1, Input1 end1, Input2 begin2, Input2 end2, Output result)
{
	auto it = begin1;
	auto it2 = begin2;

	while (it != end1 && it2 != end2)
	{
		result++ = make_pair(*it++, *it2++);
	}
}

template<typename T, typename U>
vector<pair<T, U>> zip(vector<T> const& range1, vector<U> const& range2)
{
	vector<pair<T, U>> res;
	zip(range1.begin(), range1.end(), range2.begin(), range2.end(), back_inserter(res));
	return res;

}



int main()
{
	vector<int> test{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> data{ 1,1,3,5,8,13,21 };

	auto temp = zip(test, data);

	for (auto const& i : temp)
		cout << i.first << ' ' << i.second << endl;





}