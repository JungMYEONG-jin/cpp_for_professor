#include <string>
#include <iostream>


using namespace std;


long long get_divisor_sum(long long num)
{
	long long sum = 0;
	long long i = 0;
	for (long long i = 2; i*i<num; i++)
	{
		if (num % i == 0)
		{
			sum += i;
			sum += num / i;
		}
	}

	if (i * i == num)
		sum += i;

	return sum;
}


string buddy(long long start, long long limit)
{

	for (long long i = start; i <= limit; i++)
	{
		long long k = get_divisor_sum(i);
		if (get_divisor_sum(k) == i && k>i)
		{
			return "(" + to_string(i) + " " + to_string(k) + ")";
		}
	}
	return "Nothing";
}

int main()
{
	cout << buddy(10, 50) << endl;
	cout << buddy(1071625, 1103735) << endl;
}