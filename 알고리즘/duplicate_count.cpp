#include <map>
using namespace std;

size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
	//....
	map<char, int> res;
	string test = in;
	int size = sizeof(in) / sizeof(char);


	for (auto& i : test)
		res[tolower(i)]++;
	int count = 0;
	for (auto it : res)
	{
		if (it.second > 1)
			count++;
	}
	return count;

}
