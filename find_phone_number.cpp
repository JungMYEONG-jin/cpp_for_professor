#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <iomanip>
#include <sstream>

using namespace std;

// MyCode

vector<string> find_nation_phone(vector<string>& data, int code)
{
	vector<string> res;

	regex re{ "(\\+\\d{1,3})-(\\d{1,3})-(\\d{3,4})-(\\d{3,4})" }; //국가코드 찾기

	auto match = std::smatch{};

	for (auto& i : data)
	{
		if (regex_match(i, match, re))
		{
			if (match[1].matched &&match[1].str() == "+"+to_string(code) )
			{
				res.push_back(i);
			}
		}
	}

	return res;
}

// BookCode

bool starts_with_num(std::string_view str, std::string_view prefix)
{
	return str.find(prefix) == 0;
}

template<typename InputIt>
vector<string> filter_numbers(InputIt begin, InputIt end, string const& code)
{

	vector<string> res;

	copy_if(begin, end, back_inserter(res), [code](auto& i) {
		return starts_with_num(i, code) || starts_with_num(i, "+" + code);
		});


	return res;

}

vector<string> filter_numbers(vector<string> data, string const& code)
{
	return filter_numbers(data.cbegin(), data.cend(), code);
}

// MyCode
vector<string> filter_all_numbers(vector<string>& data, string const& code)
{
	
	vector<string> res;

	for (auto& i : data) {
		if (i[0] == '0')
			i[0] = ' ';
		i.erase(remove_if(i.begin(), i.end(), isspace), i.end());
		if (starts_with_num(i, "+" + code))
		{
			res.push_back(i);
		}
		else if (starts_with_num(i, code))
		{
			res.push_back("+" + i);
		}
		else
		{
			res.push_back("+" + code + i);
		}


	}

	return res;
}
// BookCode
void normalize_number(vector<string>& number, string const& code)
{

	transform(cbegin(number), cend(number), begin(number), [code](string const& num) {
		string res;
		if (num.size() > 0)
		{
			if (num[0] == '0')
				res = "+" + code + num.substr(1);
			else if (starts_with_num(num, code))
				res = "+" + num;
			else if (starts_with_num(num, "+" + code))
				res = num;
			else
				res = "+" + code + num;
		}
		res.erase(remove_if(res.begin(), res.end(), [](const char ch) {return isspace(ch); }), res.end());
		return res;
		});
}


int main()
{
	vector<string> data = { "+82-10-4674-0554", "+82-2-374-0554", "+2-10-4674-0554", "-82-10-4674-0554", "82-2-374-0554" };

	auto k = find_nation_phone(data, 82);

	for (auto& i : k)
		cout << i << endl;

	
	cout << endl;

	auto res = filter_numbers(data, "82");
	for (auto& i : res)
		cout << i << endl;

	vector<string> data2 = { "07555 123456", "07555123456", "+44 7555 123456", "44 7555 123456", "7555 123456" };

	auto res2 = filter_all_numbers(data2, "44");

	for (auto& i : res2)
		cout << i << endl;

	cout << endl;


	normalize_number(data2, "44");

	for (auto& i : data2)
		cout << i << endl;
}