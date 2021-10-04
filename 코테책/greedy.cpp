#include <iostream>

using namespace std;

int main()
{

	int n, k;
	cin >> n >> k;
	bool flag = true;
	int cnt = 0;
	while (flag)
	{
		if (n == 1)
		{
			flag = false;
			break;
		}
		if (n % k == 0 && k!=1)
		{
			n /= k;
			cnt++;
		}
		else
		{
			n--;
			cnt++;
		}

		


	}
	cout <<n<<" "<< cnt;




}
