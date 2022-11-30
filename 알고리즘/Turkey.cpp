#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::string getTurkishNumber(unsigned int n) {
	if (n == 0)
		return "sıfır";

	int r1[18] = { 90,80,70,60,50,40,30,20,10,9,8,7,6,5,4,3,2,1 };
	string r2[18] = { "doksan", "seksen", "yetmiş", "altmış","elli", "kırk","otuz","yirmi","on","dokuz", "sekiz", "yedi","altı","beş","dört", "üç", "iki","bir"};
	string res = "";
	for (int i = 0; i < 18; i++)
	{
		while (n >= r1[i])
		{
			n -= r1[i];
			res += r2[i] + " ";
		}
	}
	res.pop_back();
	return res;



}


std::vector<std::string> wave(std::string y) {

	if (y.empty())
		return {};
	vector<string> res;
	string test = "";
	for (int i = 0; i < y.size(); i++)
	{
		if (!isalpha(y[i]))
			continue;
		if (isalpha(y[i]))
		{
			test = toupper(y[i]);
			res.push_back(y.substr(0, i) + test + y.substr(i + 1));
		}
	}

	return res;

}


//BESTCODE

std::vector<std::string> wave2(std::string y) {

	if (y.empty())
		return {};
	vector<string> res;
	string test = y;
	for (int i = 0; i < y.size(); i++)
	{
		if (!isalpha(y[i]))
			continue;
		if (isalpha(y[i]))
		{
			y[i] = toupper(y[i]);
			res.push_back(y);
		}
		y = test;
	}

	return res;

}


int main()
{

	cout << getTurkishNumber(0) << endl;
	cout << getTurkishNumber(16) << endl;
	cout << getTurkishNumber(70) << endl;
	cout << getTurkishNumber(26) << endl;

	{	
		auto k = wave("hello");

	for (auto i : k)
		cout << i << " ";
	cout << endl;
	}

	{
		auto k = wave2("hello");

		for (auto i : k)
			cout << i << " ";
		cout << endl;
	}
	{
		auto k = wave(" gap ");

		for (auto i : k)
			cout << i << " ";
		cout << endl;
	}
	{
		auto k = wave2(" gap ");

		for (auto i : k)
			cout << i << " ";
		cout << endl;
	}
}