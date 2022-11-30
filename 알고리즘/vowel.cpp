#include <string>
#include <map>

using namespace std;

map<char, int> res = { {'a',1},{'e',2},{'i',3},{'o',4},{'u',5} };
map<int, char> res2 = { {1,'a'}, {2,'e'}, {3,'i'},{4,'o'},{5,'u'} };


std::string encode(const std::string& str) {

	if (str.empty())
		return "";
	string result;
	for (auto& i : str)
	{

		if (res.find(i) != res.end())
		{
			result += res[i] + '0';
		}
		else
			result += i;


	}
	return result;
}

std::string decode(const std::string& str) {
	
	if (str.empty())
		return "";
	
	
	string result;
	for (auto& i : str)
	{
		if (res2.find(i-'0') != res2.end())
			result += res2[i -'0'];
		else
			result += i;
	}
	return result;
}