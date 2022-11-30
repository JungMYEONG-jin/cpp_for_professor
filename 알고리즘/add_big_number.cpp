#include <string>
#include <algorithm>
#include <regex>
#include <iostream>
#include <regex>
using namespace std;

bool isSmallers(string a, string b)
{
	int l1 = a.size();
	int l2 = b.size();

	if (l1 < l2 || l1 == l2 && a < b)
		return true;
	if (l1 > l2 || l1 == l2 && a > b)
		return false;

	if (a == b)
		return true;
	if (a > b)
		return false;
	return false;



}


std::string add(const std::string& a, const std::string& b) {

		if (a.size() == 0 && b.size() == 0)
			return "0";

		if (a == "0" && b == "0")
			return "0";

		string t = a;
		string k = b;
		if (isSmallers(t, k))
			swap(t, k);

		int l1 = t.size();
		int l2 = k.size();

		k.insert(0, l1 - l2, '0');

		string res;
		int carry = 0;
		for (int i = l1 - 1; i >= 0; i--)
		{
			int sum = t[i] - '0' + k[i] - '0' + carry;
			if (sum >= 10)
			{
				carry = sum / 10;
				sum = sum % 10;

			}
			else
				carry = 0;
			res.push_back(sum + '0');
		}

		res.push_back(carry + '0');



		reverse(res.begin(), res.end());

		res = regex_replace(res, regex("^0+"), "");

		return res;
	}


int main()
{
	cout << add("21", "99") << endl;

	cout << add("123", "456") << endl;
}