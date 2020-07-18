#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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



void prntFriendlyNumber(unsigned long limit)
{

	set<int> once;
	
	for (unsigned long i = 4; i < limit; i++)
	{
		if (once.find(i) != once.end()) continue;
		auto sum1 = sum_proper_divisor(i);
		
		if (sum1 < limit)
		{
			auto sum2 = sum_proper_divisor(sum1);
			if (sum2 == i && sum1 != i)
			{
				once.insert(i);
				once.insert(sum1);
				cout << i << ", " << sum1 << endl;
			}
		}
	}
}


unsigned int third(unsigned int i)
{
	return i * i * i;
}


void armstrongNumber()
{
	for (unsigned int i = 100; i < 1000; i++)
	{
		auto k = i / 100;
		auto l = (i % 100) / 10;
		auto m = (i % 10);

		if(i==(third(k)+third(l)+third(m)))
			cout<<i<<endl;
	}
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




void armstrong()
{
	

	for (auto a = 1; a <= 9; a++)
	{
		for (auto b = 0; b <= 9; b++)
		{
			for (auto c = 0; c <= 9; c++)
			{
				auto abc = a * 100 + b * 10 + c;
				auto sum = third(a) + third(b) + third(c);
				if (sum == abc)
					cout << abc << endl;
			}
		}
	}





}




/*


int main()
{
	armstrongNumber();
	armstrong();
}

*/