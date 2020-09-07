#include <ppl.h>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <array>
#include <numeric>
#include <random>
#include <algorithm>
#include <functional>

using namespace std;
using namespace concurrency;


template<typename T>
T twice(const T& t)
{
	return t + t;
}

template<typename Function>
int64_t timecall(Function&& f)
{
	int64_t begin = GetTickCount();
	f();

	return GetTickCount() - begin;
}

bool val_prime(long long n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}


template<typename T, typename F>
vector<T> alter(vector<T> data, F&& f)
{
	transform(data.begin(), data.end(), data.begin(), std::forward<F>(f));
	return data;
}

template<typename T, typename F>
vector<T> palter(vector<T> data, F&& f)
{
	auto size = data.size();

	if (size <= 10000)
	{
		transform(data.begin(), data.end(), data.begin(), std::forward<F>(f));
	}
	else
	{
		vector<thread> threads;
		int tcount = std::thread::hardware_concurrency();
		auto first = data.begin();
		auto last = first;
		size /= tcount;


		for (int i = 0; i < tcount; i++)
		{
			first = last;
			if (i == tcount - 1)
				last = data.end();
			else
				last = first + size;

			threads.emplace_back([first, last, &f]() {
				std::transform(first, last, first, std::forward<F>(f));
					});

		}
		for (int i = 0; i < tcount; i++)
			threads[i].join();
		

	}

	return data;
}



template<typename Iterator, typename Function>
void ptransform(Iterator begin, Iterator end, Function&& f)
{

	auto size = distance(begin, end);

	if (size <= 10000)
	{
		transform(begin, end,begin, std::forward<Function>(f));
	}
	else
	{

		vector<thread> threads;

		int tcount = 10;

		auto first = begin;
		auto last = first;
		size /= tcount;
		for (int i = 0; i < tcount; i++)
		{
			first = last;
			if (i == tcount - 1)
				last = end;
			else
				advance(last, size);


			threads.emplace_back([first, last, &f]() {
				transform(first, last, first, std::forward<Function>(f));
				});

		}

		for (auto& t : threads)
			t.join();




	}



}

template<typename T, typename F>
vector<T> palter2(vector<T> data, F&& f)
{
	ptransform(data.begin(), data.end(), std::forward<F>(f));
	return data;
}




int main()
{
	{
		const size_t count = 10000000;
		vector<int> data(count);

		std::random_device rd;
		std::mt19937 mt;
		auto seed_data = array<int, mt19937::state_size>{};
		generate(seed_data.begin(), seed_data.end(), std::ref(rd));
		std::seed_seq seq(seed_data.begin(), seed_data.end());
		mt.seed(seq);
		std::uniform_int_distribution<> ud(1, 100);


		generate_n(begin(data), count, [&mt, &ud]{ return ud(mt); });


		auto start = std::chrono::system_clock::now();
		auto r1 = alter(data, [](int const e) {return val_prime(e); });
		auto end = std::chrono::system_clock::now();
		auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "Time: " << t1.count() << "ms" << endl;


		start = std::chrono::system_clock::now();
		auto r2 = palter(data, [](int const e) {return val_prime(e); });
		end = std::chrono::system_clock::now();
		auto t2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "Time: " << t2.count() << "ms" << endl;

		start = std::chrono::system_clock::now();
		auto r3 = palter2(data, [](int const e) {return val_prime(e); });
		end = std::chrono::system_clock::now();
		auto t3 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "Time: " << t3.count() << "ms" << endl;
	}


	



}



