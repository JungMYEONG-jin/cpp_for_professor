#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>


using namespace std;

string multiply2(string a, string b) {



	if (a == "0" || b == "0")
		return "0";

	a = regex_replace(a, regex("^0+"), "");
	b = regex_replace(b, regex("^0+"), "");


	string res;


	int idx1 = 0;
	int idx2;

	int n1 = 0;
	int n2 = 0;






	int l1 = a.size();
	int l2 = b.size();
	int carry;
	vector<int> temp(l1 + l2, 0);
	for (int i = l1 - 1; i >= 0; i--)
	{
		idx2 = 0;
		n1 = a[i] - '0';
		carry = 0;
		for (int j = l2 - 1; j >= 0; j--)
		{
			n2 = b[j] - '0';
			int sum = n1 * n2 + temp[idx1 + idx2] + carry;
			if (sum >= 10)
			{
				carry = sum / 10;
				sum %= 10;
			}
			else
				carry = 0;
			temp[idx1 + idx2] = sum;
			idx2++;
		}
		if (carry > 0)
			temp[idx1 + idx2] += carry;
		idx1++;
	}


	reverse(temp.begin(), temp.end());

	for (auto it : temp)
		res += to_string(it);

	res = regex_replace(res, regex("^0+"), "");
	return res;




}

// MYCODE
string factorial(int fact) {

	if (fact == 1)
		return "1";

	if (fact == 2)
		return "2";

	string res = "";
	res = multiply2(to_string(fact), to_string(fact - 1));
	vector<string> temp;
	fact -= 2;
	while (fact > 1)
	{
		res = multiply2(res, to_string(fact));
		fact--;
	}



	return res;


}


//BEST CODE
string factoria2(int factorial) {
	std::vector<int> r = { 1 };
	int c = 0;
	for (int i = 1; i <= factorial; i++) {
		for (auto& d : r) {
			int v = d * i + c;
			d = v % 10;
			c = v / 10;
		}
		for (; c > 0; c /= 10)
			r.push_back(c % 10);
	}
	std::stringstream s;
	std::copy(std::rbegin(r), std::rend(r), std::ostream_iterator<int>(s));
	return s.str();
}

