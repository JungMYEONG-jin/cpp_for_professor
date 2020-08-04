#include <string>
#include <string_view>
#include <iostream>
#include <regex>
#include <assert.h>
#include <optional>
#include <fstream>


using namespace std;


string change_day_format(string_view str)
{
	regex re{ R"((\d{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}))" };

	return regex_replace(str.data(), re, "$5-$3-$1");

}

int main()
{
	ifstream readFile("date.txt");
	ofstream writeFile("test.txt");
	vector<string> text;
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			string a;
			getline(readFile, a);
			text.push_back(change_day_format(a));
		}
	}

	for (size_t i = 0; i < text.size(); i++)
		text[i] += "\n";

	for (auto const& p : text)
		writeFile.write(p.c_str(), p.size());

	readFile.close();
	writeFile.close();
	cout << change_day_format("today is 01.12.2017!"s) << endl;
}