#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;



// 나의풀이
class WhichAreIn
{

public:
	static std::vector<std::string> inArray(std::vector<std::string>& array1, std::vector<std::string>& array2)
	{
		std::vector<std::string> temp;
		int len = 0;





		for (const auto& i : array1)
		{
			len = i.length();
			for (const auto& j : array2)
			{
				if (j.find(i) != std::string::npos)
					temp.push_back(i);
			}
		}




		sort(temp.begin(), temp.end());

		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		return temp;



	}
	// lambda 이용
	static vector<string> lambdaArray(vector<string>& array1, vector<string>& array2)
	{
		vector<string> temp;

		copy_if(array1.begin(), array2.begin(), back_inserter(temp), [&](const string& item) {return any_of(array2.begin(), array2.end(),
			[&](const string& item2) {return item2.find(item) != string::npos; });
			}
		);
	}

};

