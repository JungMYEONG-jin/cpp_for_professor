#include <vector>
#include <iostream>
#include <map>

using namespace std;


bool check_primes(long long n)
{
	for (long long i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}


long long sol(long long a, long long b) {
	//..
	int count = 1;
	long long sum = 0;
	map<int, int> res;
	for (long long i = 2; i <= b; i++)
	{
		if (check_primes(i))
		{
			res[i] = count++;
		}

	}

	for (int i = a; i <= b; i++)
	{
		if (check_primes(i))
		{
			if (res[i] >= 2 && check_primes(res[i]))
				sum += i;
		}
	}

	return sum;
}


int main()
{


	cout << sol(0, 10) << endl;
	cout << sol(2, 200) << endl;
	cout << sol(1000, 100000) << endl;
	cout << sol(4000, 500000) << endl;

}