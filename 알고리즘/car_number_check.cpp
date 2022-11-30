#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <assert.h>

using namespace std;


bool check_number(string_view str)
{
	regex re{ "[A-Z]{3}-[A-Z]{2} \\d{3,4}" };
	if (regex_match(str.data(), re))
		return true;
	return false;
	
}

vector<string> get_car_number(string const& str)
{
	smatch match;
	regex re{ "([A-Z]{3}-[A-Z]{2} \\d{3,4})*" };
	vector<string> result;
	
	for (auto i = sregex_iterator(cbegin(str), cend(str), re); i != sregex_iterator(); ++i)
	{
		if ((*i)[1].matched)
			result.push_back(i->str());
	}

	return result;


}

int main()
{
	// number format ex \\d
	regex re{ "[A-Z]{3}-[A-Z]{2} \\d{3,4}" };

	string a = "LLL-LL 1244";

	cout << check_number(a);
	std::vector<std::string> expected{ "AAA-AA 123", "ABC-DE 1234", "XYZ-WW 0001" };
	std::string text("AAA-AA 123qwe-ty 1234  ABC-DE 1234.. XYZ-WW 0001");
	assert(expected == get_car_number(text));

}