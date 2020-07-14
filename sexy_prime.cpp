#include <iostream>


using namespace std;



bool isPrime(unsigned long a)
{
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}

void sexy_prime(unsigned long a)
{
	for (int i = 2; i <= a; i++)
	{
		if (isPrime(i) && isPrime(i + 6))
			cout << i << ", " << i + 6 << endl;
	}
}

static unsigned long overSum = 0;

bool isOver(unsigned long num)
{
	unsigned long sum = 0;
	for (int i = 1; i < num; i++)
	{
		if (num % i == 0)
			sum += i;
	}
	overSum = sum;
	if (sum > num)
		return true;
	return false;

}

int sum_proper_divisor(int num)
{
	int res = 1;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			res += ((i == num / i) ? i : (i + num / i));
		}
	}
	return res;
}

void prntOverNumber(int num)
{
	for (int i = 10; i <= num; i++)
	{
		auto sum = sum_proper_divisor(i);
		if (sum > i)
			cout << i << " abundance " << sum - i << endl;
	}
}


void printOverNumber(unsigned long num)
{
	for (int i = 2; i <= num; i++)
	{
		if (isOver(i))
			cout << i << " The Abundance is " << overSum-i << endl;
	}
}






int main()
{
	sexy_prime(100);
	printOverNumber(100);
	prntOverNumber(100);
}