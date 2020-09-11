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

template<typename Iterator, typename F>
auto sprocess(Iterator begin, Iterator end, F&& f)
{
	return std::forward<F>(f)(begin, end);
}


template<typename Iterator>
auto smin(Iterator begin, Iterator end)
{
	return sprocess(begin, end, [](auto e, auto k) {return *min_element(e, k); });

}




template<typename Iterator>
auto smax(Iterator begin, Iterator end)
{
	return sprocess(begin, end, [](auto e, auto k) {return *max_element(e, k); });

}


template<typename Iterator, typename F>
auto pprocess(Iterator begin, Iterator end, F&& f)
{
	auto size = distance(begin, end);
	if (size <= 10000)
	{
		return std::forward<F>(f)(begin, end);
	}
	else
	{
		auto first = begin;
		auto last = first;
		int tcount = std::thread::hardware_concurrency();
		size /= tcount;
		vector< future<typename iterator_traits<Iterator>::value_type>> tasks;

		for (int i = 0; i < tcount; i++)
		{
			first = last;
			if (i == tcount - 1)
				last = end;
			else
				std::advance(last, size);

			tasks.emplace_back(async(std::launch::async, [first, last, &f]() {return std::forward<F>(f)(first, last); }));

			
		}

		vector<typename iterator_traits<Iterator>::value_type> smin;

		for (auto& t : tasks)
			smin.push_back(t.get());


		return std::forward<F>(f)(std::begin(smin), std::end(smin));
	}
}


template<typename Iterator>
auto pmin(Iterator begin, Iterator end)
{
	return pprocess(begin, end, [](auto e, auto k) {return *min_element(e, k); });
}

template<typename Iterator>
auto pmax(Iterator begin, Iterator end)
{
	return pprocess(begin, end, [](auto e, auto k) {return *max_element(e, k); });
}


int main()
{
	std::mt19937 mt;
	std::random_device rd;
	const size_t count= 10000000;
	vector<int> data(count);
	auto seed_data = array<int, std::mt19937::state_size>{};
	generate(begin(seed_data), end(seed_data), std::ref(rd));

	std::seed_seq seq(begin(seed_data), end(seed_data));
	mt.seed(seq);
	std::uniform_int_distribution<> ud(1, 1000);

	std::generate_n(begin(data), count, [&mt, &ud]() {return ud(mt); });

	{

		std::cout << "minimum element" << std::endl;

		auto start = std::chrono::system_clock::now();
		auto r1 = smin(begin(data), end(data));
		auto end = std::chrono::system_clock::now();
		auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

		std::cout << "seq time: " << t1.count() << "ms" << std::endl;

		start = std::chrono::system_clock::now();
		auto r2 = pmin(data.begin(), data.end());
		end = std::chrono::system_clock::now();
		t1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

		std::cout << "seq time: " << t1.count() << "ms" << std::endl;


		

	}


	{
		std::cout << "max element" << std::endl;
		auto start = std::chrono::system_clock::now();
		auto r1 = smax(begin(data), end(data));
		auto end = std::chrono::system_clock::now();
		auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

		std::cout << "seq time: " << t1.count() << "ms" << std::endl;

		start = std::chrono::system_clock::now();
		auto r2 = pmax(begin(data), data.end());
		end = std::chrono::system_clock::now();
		t1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

		std::cout << "seq time: " << t1.count() << "ms" << std::endl;
	}


}