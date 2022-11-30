#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


std::string solve(const std::string& str) {
	//your code here

	unsigned int num_low = 0;
	unsigned int num_upper = 0;
	string res;

	num_upper = count_if(begin(str), end(str), [](char i) {return (i >= 65 && i <= 90); });
	num_low = count_if(begin(str), end(str), [](char i) {return (i >= 97 && i <= 122); });

	if (num_low < num_upper)
	{
		for (auto const& p : str)
			res += toupper(p);
		return res;
	}
	else
	{
		for (auto const& p : str)
			res+=tolower(p);
		return res;
	}

}

int main()
{


	cout << solve("code") << endl; //Equals("code"));
	cout << solve("CODe") << endl;// Equals("CODE"));
	cout << solve("COde") << endl; // Equals("code"));
	cout << solve("Code") << endl;



}

