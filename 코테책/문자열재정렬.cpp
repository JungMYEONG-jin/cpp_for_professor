#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

#define INF 999999999

using namespace std;


int main()
{
	string str;
	cin >> str;
	string temp;
	int s = 0;
	for (auto i : str)
	{
		if (isalpha(i))
			temp += i;
		else
			s += (i - '0');
	}
	sort(temp.begin(), temp.end());
	if (s != 0)
		temp += to_string(s);
	cout << temp << endl;

}
