#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;






std::string sum_strings(std::string a, std::string b) {


	if (a.size() < b.size())
		swap(a, b);
	//make sure a is more greater;


	int l1 = a.size();
	int l2 = b.size();

	int carry = 0;

	b.insert(0, l1 - l2, '0');

	string res = "";

	for (int i = l1 - 1; i >= 0; i--)
	{


		int sum = a[i] - '0' + b[i] - '0' + carry;
		if (sum >= 10)
		{
			carry = sum / 10;
			sum %= 10;
		}
		else
			carry = 0;
		res += to_string(sum);

	}
	if (carry > 0)
		res += to_string(carry);


	reverse(res.begin(), res.end());

	return res;



}
//BESTCODE
string sum_strings2(const string& a, const string& b)
{
	string result;
	int carry = 0, n = max(a.size(), b.size());
	for (int i = 0; i < n; i++)
	{
		if (i < a.size()) carry += a[a.size() - 1 - i] - '0';
		if (i < b.size()) carry += b[b.size() - 1 - i] - '0';
		result.push_back('0' + carry % 10);
		carry /= 10;
	}
	result.push_back(carry + '0');
	while (result.size() > 1 && result.back() == '0')
		result.pop_back();
	reverse(result.begin(), result.end());
	return result;
}