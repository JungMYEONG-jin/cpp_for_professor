#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
using namespace std;


int getSum(int i)
{
	if (i == 0)
		return 0;
	int sum = 0;
	while (i > 0)
	{
		int k = i % 10;
		
		sum += k;
		i /= 10;

	}
	if (sum < 10)
		return sum;
	else
		getSum(sum);
}

vector<vector<int>> multiplication_table(int n) {

	vector<vector<int>> res(n, vector<int>(n));
	if (n == 0)
		return {};
	if (n == 1)
	{
		res[0] = { 1 };
		return res;
	}
	if (n == 2)
	{
		res[0] = { 1,2 };
		res[1] = { 2, 4 };
		return res;
	}


	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			res[i][j] = (j + 1) * (i + 1);

		}
	}
	return res;

}

std::string missing_alphabets(const std::string& s) {

	map<char, int> res;

	for (char ch = 'a'; ch <= 'z'; ch++)
		res[ch] = 0; // init map

	for (auto i : s)
		res[i]++;

	string result = "";

	auto max_val = *max_element(res.begin(), res.end(), [](auto e, auto k) {return e.second < k.second; }); //최대 나온 갯수

	for (auto& it : res)
	{
		if (it.second != max_val.second)
		{
			result += string(max_val.second - it.second, it.first);
		}
	}
	return result;
}


std::string get_order(std::string order) {
	vector<string> menu{ "Burger", "Fries", "Chicken", "Pizza", "Sandwich", "Onionrings", "Milkshake", "Coke" };
	
	string res = "";

	for (auto it : menu)
	{
		auto k = it;
		it[0] = tolower(it[0]);
		while (true)
		{
			auto p = order.find(it);
			if (p != string::npos)
			{
				res += k + " ";
				order.erase(p, it.size()-1);
			}
			else
				break;
		}
	}

	
	return res;
}
std::string cleanString(const std::string& s) {
	// your code here
	string ans = "";

	deque<char> res;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '#')
			res.push_back(s[i]);
		else if(!res.empty())
			res.pop_back();
	}

	while (!res.empty())
	{
		ans += res.front();
		res.pop_front();
	}
	return ans;
}

int main()
{
	
	{
		
		cout << get_order("sandwichmilkshakepizza") << endl;
	cout << get_order("pizzachickenfriesburgercokemilkshakefriessandwich") << endl;
	
	}

	{
		cout << cleanString("abc#d##c") << endl;
		cout << cleanString("abc####d##c#") << endl;
	}
	
}