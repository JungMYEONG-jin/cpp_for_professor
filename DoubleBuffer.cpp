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
	for (auto& i : buff)
	{
		cout << i << ' ';

	}
	cout << end;
}