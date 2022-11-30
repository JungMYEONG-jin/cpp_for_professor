#include <iostream>
#include <list>
#include <array>
#include <vector>
#include <cassert>

using namespace std;
// 책
template<typename Container, typename T>
bool contains(Container& c, T const& value)
{
	return find(c.begin(), c.end(), value) != c.end();
}

template<typename Container, typename... T>
bool contains_any(Container const& c, T&&... value)
{
	return (... || contains(c, value));
}

template<typename Container, typename... T>
bool contains_all(Container const& c, T&&... value)
{
	return(... && contains(c, value));
}

template<typename Container, typename... T>
bool contains_none(Container const& c, T &&... value)
{
	return !contains_any(c, forward<T>(value)...);
}



//내코드
template<typename Container, typename... Tn>
bool contain_any(Container& c, Tn&&... value)
{
	return (any_of(c.begin(), c.end(), [&](Tn i) {return i == value; }) || ...);
}

template<typename Container, typename... Tn>
bool contain_all(Container& c, Tn&&... value)
{
	return (any_of(c.begin(), c.end(), [&](Tn i) {return i == value; }) &&...);
}

template<typename Container, typename... Tn>
bool contain_none(Container& c, Tn&&... value)
{
	return !(any_of(c.begin(), c.end(), [&](Tn i) {return i == value; }) || ...);
}

// contain_none contains_none 가변인수가 하나라도 속하면 true but all 가변인수 속하지 않다면 false return

int main()
{
	vector<int> v{ 1,2,3,4,5,6 };
	assert(contain_any(v, 1, 2, 3,8));
	assert(contain_all(v, 1, 2, 3));
	//assert(!contain_none(v, 8,9 ));
	assert(!contains_none(v, 8,9));
}