#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct book
{
	int id;
	string title;
	string author;
};


template<typename T, typename A, typename F, typename R= typename decay<typename result_of<typename decay<F>::type &(typename vector<T,A>::const_reference)>::type>::type>
vector<R> select(vector<T,A> const &c, F &&f)
{
	vector<R> res;

	std::transform(cbegin(c), cend(c), back_inserter(res), forward<F>(f));

	return res;

}



int main()
{
	vector<book> books{
		{101, "The C++ Language", "JMJ"},
		{203, "OPtimize C++", "Scott"},
		{404, "The Modern C++ Challenge", "Marius Bansilla"}
	};

	auto titles = select(books, [](book const& e) {return e.title; });

	for (auto const& i : titles)
		cout << i << endl;

	auto authors = select(books, [](book const& e) {return e.author; });

	for (auto const& i : authors)
		cout << i << endl;


}