#include <iostream>
#include <vector>
#include <string>

using namespace std;



void printRomanNumber(unsigned int number)
{
	vector<pair<int, string>> roman{ {1,"I"}, {4, "IV"}, {5, "V"},{9, "IX"}, {10,"X"}, {40, "XL"}, {50,"L"},{90,"XC"}, {100, "C"},{400, "CD"}, {500,"D"}, {900, "CM"}, {1000, "M"} };
	reverse(roman.begin(), roman.end());
	string str = "";
	
	for (auto const& k : roman)
	{
		while (number>=k.first)
		{
			str += k.second;
			number -= k.first;

		}
	}

	cout << str << endl;

}

int main()
{
	printRomanNumber(999);
}