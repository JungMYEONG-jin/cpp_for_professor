#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

template<typename Randomit>
Randomit partition(Randomit first, Randomit last)
{
	auto pivot = *first;
	auto i = first + 1;
	auto j = last - 1;

	while (i<=j)
	{
		while (i<=j && *i <= pivot) i++;
		while (i<=j && *j > pivot) j--;

		if (i < j) std::iter_swap(i, j);
		
	}

	std::iter_swap(i - 1, first);
	return i - 1;

}

template<typename Randomit>
void quicksort(Randomit first, Randomit last)
{
	if(first < last)
	{
		auto p = partition(first, last);
		quicksort(first, p);
		quicksort(p + 1, last);
	}
}


template<typename Randomit, typename Compare>
Randomit partition_comp(Randomit first, Randomit last, Compare comp)
{

	auto pivot = *first; //첫 원소를 피봇으로
	auto low = first + 1;
	auto high = last - 1;


	while (low <= high)
	{
		while (low <= high && comp(*low, pivot))low++;
		while (low <= high && !comp(*last, pivot)) high--;

		if (low < high)
			std::iter_swap(low, high);
	}

	std::iter_swap(low - 1, first);

	return low - 1;

}

template<typename Randomit, typename Compare>
void quicksort_comp(Randomit first, Randomit last, Compare comp)
{
	if (first < last)
	{
		auto p = partition_comp(first, last, comp);
		quicksort_comp(first, p, comp);
		quicksort_comp(p + 1, last, comp);
	}
}



//stack버전

template<typename Randomit>
void quicksort_using_stack(Randomit first, Randomit last)
{
	stack<pair<Randomit, Randomit>> res;
	res.push(make_pair(first, last));


	while (!res.empty())
	{
		auto iters = res.top();
		res.pop();

		if (iters.second - iters.first < 2) continue;

		auto p = partition(iters.first, iters.second);

		quicksort(first, p);
		quicksort(p + 1, last);

	}
}




int main()
{

	vector<int> v{ 1,5,3,8,6,2,9,7,4 };
	quicksort(v.begin(), v.end());

	for (auto it : v)
		cout << it << ' ';
	cout << endl;

	quicksort_comp(v.begin(), v.end(), greater<int>());
	for (auto it : v)
		cout << it << ' ';
	cout << endl;


	quicksort_using_stack(v.begin(), v.end());

	for (auto it : v)
		cout << it << ' ';
	cout << endl;





}