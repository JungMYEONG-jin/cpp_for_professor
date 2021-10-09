#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#define INF 999999999

using namespace std;



int main()
{
	string res;
	cin >> res;
	char ch;
	int sum = 0;
	for (auto i : res)
	{
		if (i == '1' || sum<=1 || i=='0')
		{
			sum += (i - '0');
		}
		else
		{
			sum *= (i - '0');
		}
	}
	cout << sum << endl;
}
