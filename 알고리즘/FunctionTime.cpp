#include <chrono>
#include <iostream>
#include <thread>
using namespace std;


template<typename Time = std::chrono::milliseconds, typename Clock = std::chrono::high_resolution_clock>
struct time_perf
{

	template<typename F, typename... Args>
	static Time duration(F&& f, Args... arg)
	{
		auto start = Clock::now();
		std::invoke(std::forward<F>(f), std::forward<Args>(arg)...); // 함수 유발
		auto end = Clock::now();


		return std::chrono::duration_cast<Time>(end-start);



	}




};






void f()
{
	std::this_thread::sleep_for(2s);
}

void g(int const a, int const b)
{
	std::this_thread::sleep_for(1s);
}


int main()
{

	auto t1 = time_perf<std::chrono::microseconds>::duration(f);
	auto t2 = time_perf<std::chrono::microseconds>::duration(g, 1, 2);

	auto total = std::chrono::duration<double, std::nano>(t1 + t2).count();

	cout << total << endl;


}