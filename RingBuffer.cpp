#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

template<typename T>
class RingBuffer;

template<typename T>
class RingBuffer_iterator
{
	typedef RingBuffer_iterator self_type;
	typedef T value_type;
	typedef T& reference;
	typedef T const& const_reference;
	typedef T* pointer;
	typedef std::random_access_iterator_tag iterator_category;
	typedef ptrdiff_t difference_type;


public:
	RingBuffer_iterator(RingBuffer<T> const& buffs, size_t const pos, bool const last_)
		:buf(buffs), idx(pos), last(last_)
	{}


	self_type& operator++()
	{
		if (last)
			throw out_of_range("Exceed the Range!");
		idx = (idx + 1) % buf.data.size();
		last = idx == buf.nextpos();
		return *this;
	}

	self_type operator++(int)
	{
		self_type tmp = *this;
		++(*this);
		return tmp;
	}

	bool operator==(self_type const& other) const
	{
		assert(compatible(other));
		return idx == other.idx && last == other.last;
	}

	bool operator!=(self_type const& other) const
	{
		return !(*this == other);
	}

	const_reference operator*() const
	{

		return buf.data[idx];
	}

	const_reference operator->() const
	{
		return buf.data[idx];
	}

private:
	bool compatible(self_type const& other) const
	{
		return &buf == &other.buf;
	}
	size_t idx;
	bool last;
	RingBuffer<T> const& buf;

};




template<typename T>
class RingBuffer
{
	typedef RingBuffer_iterator<T> const_iterator;
	RingBuffer() = delete;
public:
	
	
	explicit RingBuffer(size_t const val) :data(val) {};


	bool clear() noexcept { head = -1, count = 0; }

	size_t size() const noexcept { return count; }
	bool empty() const noexcept { return count == 0; }
	size_t capacity() const noexcept { return data.size(); }
	bool full() const noexcept { return data.size() == count; }

	void push(T const value)
	{
		head = nextpos();
		data[head] = value;

		if (count < data.size())
			count++;
	}

	T pop()
	{
		if (empty())
			throw runtime_error("Buffer is empty!");
		auto pos = first_pos();
		count--;
		return data[pos];
	}

	const_iterator begin() const
	{
		return const_iterator(*this, first_pos(), empty());
	}
	const_iterator end() const
	{
		return const_iterator(*this, nextpos(), true);
	}


private:
	vector<T> data;
	size_t count = 0; //원소갯수
	size_t head = -1; //head위치

	size_t nextpos() const noexcept { return count == 0 ? 0 : (head + 1) % data.size(); }
	size_t first_pos() const noexcept { return count == 0 ? 0 : (head + data.size() - count + 1) % data.size(); }

	friend class RingBuffer_iterator<T>;
};

template<typename T>
void print(RingBuffer<T>& buf)
{
	for (auto const& i : buf)
		cout << i << " ";
	cout << endl;
}

int main()
{
	RingBuffer<int> cbuf(5);
	assert(cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 0);
	print(cbuf);

	cbuf.push(1);
	cbuf.push(2);
	cbuf.push(3);
	assert(!cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 3);
	print(cbuf);

	auto item = cbuf.pop();
	assert(item == 1);
	assert(!cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 2);

	cbuf.push(4);
	cbuf.push(5);
	cbuf.push(6);
	assert(!cbuf.empty());
	assert(cbuf.full());
	assert(cbuf.size() == 5);
	print(cbuf);

	cbuf.push(7);
	cbuf.push(8);
	assert(!cbuf.empty());
	assert(cbuf.full());
	assert(cbuf.size() == 5);
	print(cbuf);

	item = cbuf.pop();
	assert(item == 4);
	item = cbuf.pop();
	assert(item == 5);
	item = cbuf.pop();
	assert(item == 6);

	assert(!cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 2);
	print(cbuf);

	item = cbuf.pop();
	assert(item == 7);
	item = cbuf.pop();
	assert(item == 8);

	assert(cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 0);
	print(cbuf);

	cbuf.push(9);
	assert(!cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 1);
	print(cbuf);
}