#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{

	int n;
	cin >> n;

	int total = 59 + 59 * 60 + 3600 * n;
	int cnt = 0;
	int i = 1;
	string res = "";
	while (i <= total)
	{
		if (i/60 == 0)
		{
			res = to_string(i);
			if (res.find('3') != res.npos)
				cnt++;
		}
		else
		{
			if (i / 3600 == 0)
			{
				int k = i / 60;
				int j = i % 60;

				res = to_string(k) + " " + to_string(j);
				if (res.find('3') != res.npos)
					cnt++;
				
			}
			else
			{
				int k = i / 3600;
				int j = (i - 3600 * k) / 60;
				int m = (i - 3600 * k) % 60;
				res = to_string(k) + " " + to_string(j) + " " + to_string(m);
				if (res.find('3') != res.npos)
					cnt++;
			}
		}

		i++;
	}
	cout << cnt << endl;

}
