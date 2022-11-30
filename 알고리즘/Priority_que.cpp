#include <iostream>
#include <vector>
#include <algorithm>




using namespace std;


template<typename T, typename Compare = less<typename vector<T>::value_type>>
class Priority_queue
{
	typedef typename vector<T>::value_type value_type;
	typedef typename vector<T>::size_type size_type;
	typedef typename vector<T>::reference reference;
	typedef typename vector<T>::const_reference const_reference;


public:
	bool empty() const noexcept { return data.empty(); }

	size_type size() const noexcept { return data.size(); }

	void push(value_type const& a)
	{
		data.push_back(a);
		push_heap(data.begin(), data.end(), comparer);
	}

	void pop()
	{
		pop_heap(begin(data), end(data), comparer);
		data.pop_back();
	}

	const_reference top() const { return data.front(); }

	void swap(Priority_queue& other)
	{
		swap(data, other.data);
		swap(comparer, other.comparer);
	}




private:
	vector<T> data;
	Compare comparer;
};


template<typename T, typename Compare>
void swap(Priority_queue<T, Compare>& lhs, Priority_queue<T, Compare>& rhs)
noexcept(noexcept(lhs.swap(rhs)))
{
	lhs.swap(rhs);
}



int main()
{

	Priority_queue<int> q;

	for (int i : {1, 5, 3, 1, 13, 21, 8})
		q.push(i);
	cout << q.size() << endl;
	while (!q.empty())
	{
		cout << q.top() << ' ';
		q.pop();
	}



}