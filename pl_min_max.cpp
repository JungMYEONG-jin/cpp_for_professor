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


template<typename Iterator, typename F>
auto sprocess(Iterator begin, Iterator end, F&& f)
{
	return std::forward<F>(f)(begin, end);
}

template<typename Iterator>
auto smin(Iterator begin, Iterator end)
{
	return sprocess(begin, end,[](auto e, auto p) {return *min_element(e, p); });
}


template<typename Iterator>
auto smax(Iterator begin, Iterator end)
{
	return sprocess(begin, end,[](auto e, auto p) {return *max_element(e, p); });
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

		int tcount = thread::hardware_concurrency();

		auto first = begin;
		auto last = first;
		vector<thread> threads;
		size /= tcount;
		vector<typename std::iterator_traits<Iterator>::value_type> mins(tcount);
		for (int i = 0; i < tcount; i++)
		{
			first = last;
			if (i == tcount - 1)
				last = end;
			else
				std::advance(last, size);


			threads.emplace_back([first, last, &f, &r = mins[i]](){r = std::forward<F>(f)(first, last); });
			
		}

		for (auto& t : threads)
			t.join();
		return std::forward<F>(f)(std::begin(mins), std::end(mins));
	}

}

template<typename Iterator>
auto pmin(Iterator begin, Iterator end)
{
	return pprocess(begin, end, [](auto e, auto p) {return *min_element(e, p); });
}

template<typename Iterator>
auto pmax(Iterator begin, Iterator end)
{
	return pprocess(begin, end, [](auto e, auto p) {return *max_element(e, p); });
}




int main()
{

	std::random_device rd;
	std::mt19937 mt;
	auto seed_data = array<int, std::mt19937::state_size>{};
	size_t const size = 100000;
	std::vector<int> data(size);
	generate(seed_data.begin(), seed_data.end(), std::ref(rd));

	std::seed_seq seq(begin(seed_data), end(seed_data));
	mt.seed(seq);
	std::uniform_int_distribution<> ud(1, 1000);


	std:generate_n(begin(data), size, [&mt, &ud] {return ud(mt); });


	{
		cout << "minimum element" << endl;
		auto start = std::chrono::system_clock::now();
		auto r1 = smin(data.begin(), data.end());
		auto end = std::chrono::system_clock::now();
		auto res = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "Time: " << res.count() << "ms " << "value: " << r1 << endl;


		cout << "minimum element parallel" << endl;
		start = std::chrono::system_clock::now();
		auto r2 = pmin(data.begin(), data.end());
		end = std::chrono::system_clock::now();
		res = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "Time: " << res.count() << "ms " << "value: " << r2 << endl;


	}

	{
		cout << "maximum element" << endl;
		auto start = std::chrono::system_clock::now();
		auto r1 = smax(data.begin(), data.end());
		auto end = std::chrono::system_clock::now();
		auto res = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "Time: " << res.count() << "ms " << "value: " << r1 << endl;



		cout << "maximum element parallel" << endl;
		start = std::chrono::system_clock::now();
		auto r2 = pmax(data.begin(), data.end());
		 end = std::chrono::system_clock::now();
		 res = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "Time: " << res.count() << "ms " << "value: " << r2 << endl;






	}





}