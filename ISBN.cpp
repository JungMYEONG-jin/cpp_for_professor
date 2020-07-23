#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <string>
#include <string_view>

using namespace std;


static int rec(int n)
{
	int i = 1;
	if (n < 1)
		return 2;
	else
	{
		i = (2 * rec(n - 1)) + 1;
		cout << i << endl;
		return i;
	}
}




bool isISBN(string_view code)
{
	auto valid = false;

	if (code.size() == 10 && count_if(code.begin(), code.end(), isdigit) == 10)
	{

		auto w = 10;
		
		auto sum=accumulate(code.begin(), code.end(), 0, [&w](int total, char const ch) {return total+ w-- * (ch - '0'); });
		valid = !(sum % 11);
	}
	return valid;
}




bool isISBN_if_hypen(string_view code)
{
	string temp = "";
	for (auto& c : code)
	{
		if (c == '-')
		{
			continue;
		}
		temp += c;
	}
	return isISBN(temp);
}

bool isISBN_13(string_view code)
{
	auto valid = false;

	if (code.size() == 13 && count_if(code.begin(), code.end(), isdigit) == 13)
	{
		auto w = 13;
		auto sum = accumulate(code.begin(), code.end(), 0, [&w](int const total, char const ch) {if (w-- % 2 == 0) total + 3 * (ch - '0'); else total + (ch - '0');
		return total; });

		valid = !(sum % 10);
	}
	return valid;
}

bool isISBN_13_hypen(string_view code)
{
	string temp = "";

	for (const auto& c : code)
	{
		if (c == '-')
			continue;
		temp += c;
	}

	return isISBN_13(temp);
}

/*

int main()
{
	cout << isISBN("8970443509") << endl;
	cout << isISBN_if_hypen("89-7044-350-9") << endl;
	cout << isISBN_13("9788966261642") << endl;
	cout << isISBN_13_hypen("978-89-6626-164-2") << endl;

	rec(5);

}
*/