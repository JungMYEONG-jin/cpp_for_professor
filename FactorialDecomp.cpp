#include <iostream>
#include <string>
#include <numeric>
#include <map>


using namespace std;


bool isPrimes(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}





std::string decomp(int lst)
{

	string final = "";
	map<int, int> res;
	while (lst > 1)
	{
		for (int i = 2; i <= lst; i++)
		{
			int count = 0;
			int tmp = lst;
			if (tmp % i == 0 && isPrimes(i))
			{
				while (tmp % i == 0)
				{
					count++;
					tmp /= i;

				}
				res[i] = res[i] + count;



			}
		}
		lst--;

	}

	for (auto const& it : res)
	{
		if (it.second > 1)
			final += to_string(it.first) + "^" + to_string(it.second) + " * ";
		else if (it.second == 1)
			final += to_string(it.first) + " * ";
	}


	return final.erase(final.size() - 3, final.size());
}

int main()
{

	cout << decomp(12) << endl;
	cout << decomp(22) << endl;
	cout << decomp(25) << endl;

}