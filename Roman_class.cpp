#include <unordered_map>
#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;


class Roman
{
public:
	string to_roman(int n);
	int from_roman(string n);
};

string Roman::to_roman(int n)
{
	int r1[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
	string r2[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
	string res;
	for (int i =0 ; i < 13; i++)
	{
		while (n >= r1[i])
		{
			n -= r1[i];
			res += r2[i];
		}
	}
	return res;
}

int Roman::from_roman(string n)
{
	unordered_map<char, int> roman{ {'M',1000}, {'D', 500},{'C', 100},{'L', 50}, {'X', 10}, {'V', 5}, {'I', 1} };
	int sum = 0;
	int prev = 0;
	for (auto i : n)
	{
		int val = roman[i];
		sum += (val < prev) ? -val : val;
		prev = val;
	}
	return sum;

}


int main()
{
	Roman RomanHelp;
	cout << RomanHelp.to_roman(1000) << endl;
	cout << RomanHelp.to_roman(1990) << endl;
	cout << RomanHelp.from_roman("MCMXC") << endl;
	cout << RomanHelp.from_roman("M") << endl;
}