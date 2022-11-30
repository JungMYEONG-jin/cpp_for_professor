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
#include <future>


using namespace std;


template<typename Iterator>
auto partition(Iterator first, Iterator last)
{
	auto pivot = *first;

	auto i = first + 1;
	auto j = last - 1;

	while (i <= j)
	{
		while (i <= j && *i <= pivot) i++;
		while (i<=j  && *j > pivot) j--;
		if (i < j) iter_swap(i, j);
	}
	iter_swap(i - 1, first);

	return i - 1;
}

template<typename Iterator>
void quicksort(Iterator first, Iterator last)
{
	if (first < last)
	{
		auto p = partition(first, last);
		quicksort(first, p);
		quicksort(p + 1, last);
	}
}

template<typename Iterator>
void pquicksort(Iterator first, Iterator last)
{
	auto size = distance(first, last);
	if (first < last)
	{
		auto p = partition(first, last);
		if (size < 100000)
		{
			pquicksort(first, p);
			pquicksort(p + 1, last);
		}
		else
		{
			auto p1 = std::async(std::launch::async, [first, p]() {pquicksort(first, p); });

			auto p2 = std::async(std::launch::async, [p, last]() {pquicksort(p + 1, last); });
			p1.wait();
			p2.wait();
		}
	}
}

int main()
{
	const size_t count = 100000;
	std::mt19937 mt;
	std::random_device rd;
	vector<int> data(count);
	auto seed_data = array<int, std::mt19937::state_size>{};

	generate(seed_data.begin(), seed_data.end(), std::ref(rd));

	std::seed_seq seq(seed_data.begin(), seed_data.end());
	std::uniform_int_distribution<> ud(1, 1000);
	mt.seed(seq);

	generate_n(begin(data), count, [&mt, &ud]() {return ud(mt); });

	
	{
		cout << "quick sort parallel" << endl;

		auto start = std::chrono::system_clock::now();
		pquicksort(data.begin(), data.end());
		auto end = std::chrono::system_clock::now();
		auto r1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "Time: " << r1.count() << "ms" << endl;
	}

}