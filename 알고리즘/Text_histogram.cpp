#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <numeric>
#include <iomanip>
using namespace std;

// MyCode
void paint_histogram(string_view data)
{
	map<char, int> res{};
	for (char ch = 'a'; ch <= 'z'; ch++)
		res[ch] = 0;


	int count = 0; //주어진 텍스트중 알파벳 갯수
	for (int i = 0; i < data.size(); i++)
	{
		if(isalpha(data[i]))
		{
			res[tolower(data[i])]++;
			count++;
		}
	}
	// 각 문자별 갯수가 저장됨

	
	std::for_each(begin(res), end(res), [count](auto& k) {
		k.second = double(k.second * 100.0) / count;
		});

	for (auto const& i : res)
	{
		cout << i.first << " " << i.second << endl;
	}
}


// BookCode

map<char, double> analyze_text(string_view text)
{
	map<char, double> res;
	for (char ch = 'a'; ch <= 'z'; ch++)
		res[ch] = 0;


	for (auto ch : text)
	{
		if (isalpha(ch))
			res[tolower(ch)]++;
	}

	auto total = std::accumulate(cbegin(res), cend(res), 0ull, [](auto const sum, auto const& kvp)
		{return sum + static_cast<unsigned long long>(kvp.second); });

	
	std::for_each(begin(res), end(res), [total](auto& k)
		{k.second = (k.second * 100.0) / total; });

	return res;




}







int main()
{
	string a = "aaaAA232!2_bd3";

	paint_histogram(a);

	auto k = analyze_text(a);

	for (auto const& i : k)
	{
		cout << i.first << " : " << fixed << setw(5) << setfill(' ') << setprecision(2) << i.second << endl;
	}



}