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
#include <queue>

using namespace std;

class CLogger
{

	CLogger() {}
public:

	CLogger& operator=(CLogger const&) = delete;
	CLogger(CLogger const&) = delete;
	static CLogger& instance()
	{
		static CLogger lg;
		return lg;
	}

	

	void log(string_view message)
	{
		lock_guard<mutex> lock(mt);
		cout << "Log: " << message << endl;
	}

private:
	mutex mt;
};

class Ticket_machine
{
public:
	Ticket_machine(int const num)
		:first_ticket(num), last_ticket(num)
	{}
	int next() { return last_ticket++; }
	int last() const { return last_ticket - 1; }

	void reset() { last_ticket = first_ticket; }


private:
	int first_ticket;
	int last_ticket;
};

class Customer
{
public:
	Customer(int const num)
		:customer_number(num)
	{}
	int show_customer() { return customer_number; }


private:
	int customer_number;
	friend bool operator<(Customer const& left, Customer const& right);
};

bool operator<(Customer const& left, Customer const& right)
{
	return left.customer_number > right.customer_number; // short number is first
}


int main()
{
	mutex mt;
	condition_variable cv;
	bool open = true;
	priority_queue<Customer> customers;


	vector<thread> threads;

	for (int i = 1; i <= 3; i++)
	{
		threads.emplace_back([&mt, &cv, &open, &customers, i]() {

			auto seed_data = array<int, std::mt19937::state_size>{};
			auto gen = std::mt19937{};
			random_device rd;
			generate(seed_data.begin(), seed_data.end(), std::ref(rd));
			std::seed_seq seq(seed_data.begin(), seed_data.end());
			gen.seed(seq);
			uniform_int_distribution<> ud(2000, 3000);


			CLogger::instance().log("Desk " + to_string(i) + " is open");

			while (open || !customers.empty())
			{
				unique_lock<mutex> locker(mt);

				cv.wait_for(locker,chrono::seconds(1), [&customers]() {return !customers.empty(); });


				if (!customers.empty())
				{
					auto c = customers.top();
					customers.pop();

					CLogger::instance().log("desk " + to_string(i) + " is handling customer " + to_string(c.show_customer()));
					CLogger::instance().log("queue size is " + to_string(customers.size()));



					locker.unlock();
					cv.notify_one();

					this_thread::sleep_for(std::chrono::milliseconds(ud(gen)));

					CLogger::instance().log("desk " + to_string(i) + " is done with customer " + to_string(c.show_customer()));

				}



			}

			
			CLogger::instance().log("desk " + to_string(i) + " is done");


			});

	}

	thread store([&mt, &cv, &customers, &open]() {

		Ticket_machine tm(100);
		auto seed_data = array<int, std::mt19937::state_size>{};
		auto gen = std::mt19937{};
		random_device rd;
		generate(seed_data.begin(), seed_data.end(), std::ref(rd));
		std::seed_seq seq(seed_data.begin(), seed_data.end());
		gen.seed(seq);
		uniform_int_distribution<> ud(200, 500);


		for (int i = 1; i <= 25; i++)
		{
			
			Customer c(tm.next());
			customers.push(c);


			CLogger::instance().log("New customer " + to_string(c.show_customer()));
			CLogger::instance().log("queue size is " + to_string(customers.size()));


			cv.notify_one();
			this_thread::sleep_for(chrono::milliseconds(ud(gen)));






		}

		open = false;



		});
	store.join();
	for (auto& t : threads)
		t.join();





}