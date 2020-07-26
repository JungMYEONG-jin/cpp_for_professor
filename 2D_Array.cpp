#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

using namespace std;



template<typename T, size_t R, size_t C>
class arr2D
{
	vector<T> arr;
	typedef T value_type;
	typedef value_type* iterator;
	typedef value_type const* const_iterator;

public:
	arr2D() :
		arr(R* C) {}


	arr2D(initializer_list<T> l) :
		arr(l) {}


	constexpr T& operator()(size_t const a, size_t const b) { return arr[a * C + b]; }
	constexpr T const& operator()(size_t const a, size_t const b) const { return arr[a * C + b]; }

	constexpr T* data() noexcept { return arr.data(); }
	constexpr T const* data() const noexcept { return arr.data(); }

	constexpr T& at(size_t a, size_t b) { return arr.at(a * C + b); }
	constexpr T const& at(size_t a, size_t b) const { return arr.at(a * C + b); }

	constexpr size_t size(size_t const a) noexcept { if (a == 2) return C; else if (a == 1) return R;	else throw out_of_range("유효하지않은 값입니다"); }


	constexpr bool empty() const noexcept
	{
		return (R == 0 || C == 0);
	}

	iterator begin() noexcept { return arr.data(); }
	iterator end() noexcept { return arr.data() + R * C; }

	const_iterator begin() const { return arr.data(); }
	const_iterator end() const { return arr.data() + R * C; }


	
	void fill(T const& a) { std::fill(arr.begin(), arr.end(), a); }

	void swap(arr2D& other) noexcept { arr.swap(other.arr); }

};
//data() iterator 반환으로 이해하면됨

/*
int main()
{

	arr2D<int, 2, 3> a{ 1,2,3,4,5,6 };
	for (size_t i = 0; i < a.size(1); i++)
		for (size_t j = 0; j < a.size(2); j++)
		a(i, j) *= 2;
	

	for (auto& p : a)
		cout << p << endl;


	copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));


	arr2D<int, 2, 3> b;
	b.fill(1);

	a.swap(b);

	arr2D<int, 2, 3> c(move(b));


}*/