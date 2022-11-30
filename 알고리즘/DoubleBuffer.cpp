#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <iterator>

using namespace std;


template<typename T>
class DoubleBuffer
{
	typedef T value_type;
	typedef T& reference;
	typedef T const& const_reference;
	typedef T* pointer;


public:
	explicit DoubleBuffer(size_t num)
		:wrbuf(num), rdbuf(num)
	{}

	void write(T const* const ptr, size_t pos)
	{
		std::unique_lock<mutex> lock(mt);
		auto length = min(wrbuf.size(), pos);
		copy(ptr, ptr + length, begin(wrbuf));
		wrbuf.swap(rdbuf);
	}




	template<typename OutPut>
	void read(OutPut it) const
	{
		std::unique_lock<mutex> lock(mt);
		copy(cbegin(rdbuf), cend(rdbuf), it);
	}


	reference operator[](size_t const pos)
	{
		std::unique_lock<mutex> lock(mt);
		return rdbuf[pos];
	}

	const_reference operator[](size_t const pos) const
	{
		std::unique_lock<mutex> lock(mt);
		return rdbuf[pos];
	}

	pointer data() const
	{
		std::unique_lock<mutex> lock(mt);
		return rdbuf.data();
	}



	void swap(DoubleBuffer other)
	{
		swap(wrbuf, other.wrbuf);
		swap(rdbuf, other.rdbuf);
	}

private:
	vector<T> wrbuf;
	vector<T> rdbuf;
	mutable mutex mt;



};

template<typename T>
void print_buffer(DoubleBuffer<T>& buff)
{
	buff.read(ostream_iterator<T>(cout, " "));
	cout << endl;
}

int main()
{
	DoubleBuffer<int> buf(10);

	std::thread t([&buf]() {
		for (int i = 1; i < 1000; i += 10)
		{
			int data[] = { i, i + 1, i + 2, i + 3, i + 4, i + 5, i + 6, i + 7, i + 8, i + 9 };
			buf.write(data, 10);

			using namespace std::chrono_literals;
			this_thread::sleep_for(100ms);
		}
		});

	auto start = std::chrono::system_clock::now();

	do {
		print_buffer(buf);

		using namespace std::chrono_literals;
		this_thread::sleep_for(150ms);
	} while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start).count() < 12);

	t.join();




}