#include <iostream>



using namespace std;


unsigned int gcd2(unsigned int a, unsigned int b)
{
	while (b != 0)
	{
		unsigned int r = a % b;
		a = b;
		b = r;
	}
	return a;
}






int main()
{


	unsigned int n;
	cin >> n;
	cout << "limit 3 or 5 sum" << endl;
	unsigned long long sum = 0;
	for (int i = 3; i < n; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
			sum += i;

	}

	cout << sum << endl;




	











	return 0;
	






}