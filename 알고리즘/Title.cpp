#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include <assert.h>
using namespace std;


//MyCode
string convert_to_title_style(string temp)
{

	istringstream ss(temp);
	string test;
	string res;
	while (getline(ss, test, ' '))
	{
		test[0] = toupper(test[0]);
		for (int i = 1; i < test.size(); i++)
		{
			test[i] = tolower(test[i]);
		}
		res = res + test + ' ';
	}

	res.erase(res.size() - 1, 1); // 마지막 더해진 space erase

	return res;
}


// Book Code

template <class Element>
using tstring = basic_string<Element, char_traits<Element>, allocator<Element>>;
//basic_string의 구성 원소임 cppreference



template <class Element>
using tstring_stream = basic_stringstream<Element, char_traits<Element>, allocator<Element>>;

template<class Element>
tstring<Element> capitalize(tstring<Element> const& text)
{
	tstring_stream<Element> res;
	bool newWord = true;

	for (auto const ch : text)
	{
		newWord = newWord || isspace(ch) || ispunct(ch);

		if (isalpha(ch))
		{
			if (newWord)
			{
				res << static_cast<Element>(toupper(ch));
				newWord = false;
			}
			else
			{
				res << static_cast<Element>(tolower(ch));
			}
		}
		else
			res << ch;
	}
	return res.str();
}












int main()
{
	using namespace string_literals;
	string ak = "The C++ Challenger";
	string test = convert_to_title_style("the c++ challenger");
	cout << ak << endl;
	cout << test << endl;
	assert(ak == test);
	cout << convert_to_title_style("THIS IS AN ExamplE, Should wORk!") << endl;

	assert("The C++ Cha"s == capitalize("the C++ cha"s));
	assert("This Is An Example, Should Work!"s == capitalize("THIS IS AN ExamplE, Should wORk!"s));



}