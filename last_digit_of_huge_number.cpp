#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <list>


using namespace std;


int last_digit(list<int>& arr)
{

	if (arr.size() == 0)
		return 1;
	

	int res = 1;
	for (auto it = arr.rbegin(); it != arr.rend(); it++)
	{
		int base = *it < 20 ? *it : *it % 20 + 20;
		int exp = res < 4 ? res : res % 4 + 4;

		res = pow(base, exp);
	}

	return res % 10;

}

int main()
{
	list<int> arr;
	arr.push_back(7);
	arr.push_back(6);
	arr.push_back(21);

	cout << last_digit(arr) << endl;
}