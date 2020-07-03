#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main()
{

	auto ivec = vector<int>{ 0,	2,	-3,	5,	-1,	6,	8,	-4,	9, 10 };
	auto texts = vector<string>{ "hello"s, " "s, "World!"s };

	auto lsum = [](auto const n, auto const r) { return n + r; };

	auto sum = accumulate(begin(ivec), end(ivec), 0, lsum);
	cout << sum << endl;

	auto text = accumulate(begin(texts), end(texts), ""s, lsum);
	cout << text << endl;


}