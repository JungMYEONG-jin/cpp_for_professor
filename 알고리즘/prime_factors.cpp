#include <iostream>
#include <string>

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




class PrimeDecomp
{
public:
	static std::string factors(int lst)
	{

		string final = "";
		for (int i = 2; i <= lst; ++i)
		{
			int count = 0;
			if (lst % i == 0)
			{
				while (lst % i == 0)
				{
					count++;
					lst /= i;

				}

				if (count > 1 && isPrimes(i))
					final += "(" + to_string(i) + "**" + to_string(count) + ")";
				else if (count == 1 && isPrimes(i))
					final += "(" + to_string(i) + ")";


			}
		}
		return final;


	}
};


int main()
{


	cout << PrimeDecomp::factors(7775460) << endl;
}