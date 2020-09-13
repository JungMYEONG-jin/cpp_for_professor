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

class Log
{
	Log() {}
public:
	

	Log& operator=(Log const&) = delete;
	Log(Log const&) = delete;
	static Log& instance()
	{
		static Log lg;
		return lg;
	}
	

	
	void log_print(string_view message)
	{
		lock_guard<mutex> lock(mu);
		cout << message << endl;

	}

private:
	mutex mu;
};


int main()
{
	vector<thread> threads;

	for (int id = 1; id <= 5; id++)
	{
		threads.emplace_back([id]() {
			std::random_device rd;
			std::mt19937 mt(rd());
			std::uniform_int_distribution<> ud(100, 1000);


			Log::instance().log_print(to_string(id) + " Start");
			this_thread::sleep_for(std::chrono::milliseconds(ud(mt)));
			Log::instance().log_print(to_string(id) + " Finished");


			});

		

	}

	for (auto& t : threads)
		t.join();

}