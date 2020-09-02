#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
 


bool is_prime_check(long long n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

class SumOfDivided
{
public:
	static std::string sumOfDivided(std::vector<int>& lst)
	{
		map<int, int> res;

		for (auto it : lst)
		{
			int tmp = it;
			if (it < 0)
				it = -it;
			for (int i = 2; i <= it;)
			{
				if (is_prime_check(i) && it % i == 0)
				{
					res[i] += tmp;
					it /= i;
					i++;
				}
				else
					i++;
			}
		}

		string test;

		for (auto& it : res)
		{
			test = test + "(" + to_string(it.first) + " " + to_string(it.second) + ")";
		}
		return test;
	}
};
