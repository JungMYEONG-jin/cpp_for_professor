#include <iostream>
#include <string>
#include <regex>
#include <map>

using namespace std;

#include <map>
#include <regex>

std::string wordPattern(const std::string& word) {
	std::string pattern = "";
	auto match = std::smatch{};
	std::map<char, int> res;
	std::string temp = "";

	std::regex re{ "([a-zA-Z]+)" };

	if (word.empty())
		return "";

	if (std::regex_match(word, match, re))
	{
		int i = 0;
		std::string test = match[1].str();

		for (auto const& i : test)
			temp += tolower(i);
		//sort(temp.begin(), temp.end());
		for (auto const& p : temp)
		{
			if (res.count(p) == 0)
			{
				res[p] = i++;
			}
			else
				continue;

		}

	}
	for (auto const& k : temp)
	{
		for (auto const& it : res)
		{
			if (k == it.first)
				pattern += std::to_string(it.second) + ".";
		}
	}

	return pattern.erase(pattern.size() - 1, pattern.size());
}


int main()
{


	cout << wordPattern("hello") << endl;
	cout << wordPattern("heLlo") << endl;
	cout << wordPattern("helLo") << endl;
	cout << wordPattern("Hippopotomonstrosesquippedaliophobia") << endl;
}