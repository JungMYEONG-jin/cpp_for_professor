#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;




class Mix
{
public:
	static std::string mix(const std::string& s1, const std::string& s2);
};


string Mix::mix(const std::string& s1, const std::string& s2)
{
	map<char, int> res;
	for (auto& i : s1)
	{
		
		if (islower(i))
		{
			res[i]++;
		}
	}
	map<char, int> res2;
	for (auto& i : s2)
	{

		if (islower(i))
		{
			res2[i]++;
		}
	}

	vector<string> temp; // string 임시보관
	string range = "abcdefghikjlmnopqrstuvwxyz";
	for (auto& i : range)
	{
		size_t s1_count = res[i];
		size_t s2_count = res2[i];

		if (s1_count > s2_count)
		{
			if (s1_count > 1)
			{
				temp.push_back("1:" + string(s1_count, i));
			}
		}
		else if (s1_count < s2_count)
		{
			if (s2_count > 1)
			{
				temp.push_back("2:" + string(s2_count, i));
			}
		}
		else
		{
			if (s1_count > 1)
			{
				temp.push_back("=:" + string(s1_count, i));
			}
		}

	}

	sort(temp.begin(), temp.end(), [](auto e, auto k) {return e.size() == k.size() ? e<k : e.size()>k.size(); });
	stringstream sstr;
	string div = "";
	for (auto& it : temp)
	{
		sstr << div << it;
		div = "/";
	}

	


	
	return sstr.str();
}

int main()
{
	string a = "A aaaa bb c";

	string s2 = "& aaa bbb c d";


	cout << Mix::mix(a, s2) << endl;
	cout << Mix::mix("my&friend&Paul has heavy hats! &", "my friend John has many many friends &") << endl;
	cout << Mix::mix("mmmmm m nnnnn y&friend&Paul has heavy hats! &", "my frie n d Joh n has ma n y ma n y frie n ds n&") << endl;



}