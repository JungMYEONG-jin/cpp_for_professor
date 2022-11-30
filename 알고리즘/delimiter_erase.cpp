#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <assert.h>

using namespace std;


template<typename Element>
using tstring = basic_string<Element, char_traits<Element>, allocator<Element>>;

template<typename Element>
using tstring_stream = basic_stringstream<Element, char_traits<Element>, allocator<Element>>;


// 구분자가 1개일때
template<typename Element>
vector<tstring<Element>> split_delimiter(tstring<Element> test, Element const delimiter)
{
	auto res = vector<tstring<Element>>{};
	auto s_stream = tstring_stream<Element>{ test };

	auto token = tstring<Element>{};

	while (getline(s_stream, token, delimiter))
	{
		if (!token.empty())
			res.push_back(token);
	}
	

	return res;
}


// 구분자가 string일때 구현
template<typename Element>
inline std::vector<tstring<Element>> split_delimiter(tstring<Element> text, tstring<Element> const& delimiters)
{
	auto tokens = std::vector<tstring<Element>>{};

	size_t pos, prev_pos = 0;
	while ((pos = text.find_first_of(delimiters, prev_pos)) != std::string::npos)
	{
		if (pos > prev_pos)
			tokens.push_back(text.substr(prev_pos, pos - prev_pos));
		prev_pos = pos + 1;
	}

	if (prev_pos < text.length())
		tokens.push_back(text.substr(prev_pos, std::string::npos));

	return tokens;
}


int main()
{
	using namespace string_literals;
	
	std::vector<std::string> expected{ "this", "is", "a", "sample" };

	auto k = split_delimiter("this is! a_ sample"s, " !_"s);
	for (const auto& i : k)
		cout << i << endl;

	assert(expected == split_delimiter("this is! a_ sample"s, " !_"s));



}