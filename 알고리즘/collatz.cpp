#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

pair<unsigned long long, long> get_max_length_collatz()
{
	unsigned long length = 0;
	vector<unsigned long long> collatz;
	unsigned long long first_value = 0;

	for (int i = 2; i <= 6; i++)
	{
		while (true)
		{
			if (i % 2 == 0)
			{
				i /= 2;
				collatz.push_back(i);
			}
			else {
				i = 3 * i + 1;
				collatz.push_back(i);
			}
			if (i == 1)
			{
				collatz.push_back(i);
				break;

			}
		}
		if (collatz.size() > length)
		{
			length = collatz.size();
			first_value = collatz[0];
		}
		collatz.clear();
	}
	return make_pair(first_value, length);
}





pair<unsigned long long, long> longest_collatz(unsigned long long limit)
{
	long length = 0;

	unsigned long long first_value = 0;

	vector<int> collatz(limit + 1, 0);

	for (int i = 2; i <= limit; i++)
	{
		auto n = i;
		long steps = 0;
		while (n != 1 && n >= i)
		{
			if (n % 2 == 0)
				n /= 2;
			else
				n = 3 * n + 1;
			steps++;
		}
		collatz[i] = steps + collatz[n];

		if (collatz[i] > length)
		{
			length = collatz[i];
			first_value = i;
		}
	}

	return make_pair(first_value, length);
}
















unsigned int get_max_collatz(unsigned int number)
{
	vector<unsigned int> collatz;
	collatz.push_back(number);
	while (true)
	{
		if (number % 2 == 0)
		{
			number /= 2;
			collatz.push_back(number);
		}
		else {
			number = 3 * number + 1;
			collatz.push_back(number);
		}
		if (number == 1)
		{
			collatz.push_back(number);
			break;

		}
	}

	auto it = max_element(begin(collatz), end(collatz));
	return *it;
}

int main()
{
	cout << longest_collatz(100).first << " " << longest_collatz(100).second << endl;
	cout << get_max_collatz(100) << endl;
}