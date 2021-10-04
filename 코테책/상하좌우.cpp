#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{

	int n;
	cin >> n;
	cin.ignore();
	pair<int, int> xy = { 1, 1 };
	string line;
	getline(cin, line);
	stringstream sstr(line);
	string temp = "";
	while (getline(sstr, temp, ' '))
	{
		if (temp=="R")
		{
			if (xy.second == n)
				continue;
			else
				xy.second += 1;
		}
		else if (temp == "U")
		{
			if (xy.first == 1)
				continue;
			else
				xy.first -= 1;
		}
		else if (temp == "L")
		{
			if (xy.second == 1)
				continue;
			else
				xy.second -= 1;
		}
		else if (temp == "D")
		{
			if (xy.first == n)
				continue;
			else
				xy.first += 1;
		}
	}

	cout << xy.first << " " << xy.second << endl;

}
