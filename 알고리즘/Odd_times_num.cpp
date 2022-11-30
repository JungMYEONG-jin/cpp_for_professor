#include <vector>
#include <map>
#include <iostream>
using namespace std;

int findOdd(const std::vector<int>& numbers) {
	//your code here

	int count = 1;

	map<int, int> res;

	for (auto const& i : numbers)
	{
		res[i]++;
	}

	for (auto const& i : res)
		if (i.second % 2 == 1)
			return i.first;




	return 0;


}

int main()
{

	cout << findOdd(vector<int>{20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5}) << endl;
	cout << findOdd(vector<int>{1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5}) << endl;

	cout << findOdd(vector<int>{1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5}) << endl;
	cout << findOdd(vector<int>{10}) << endl;
	cout << findOdd(vector<int>{1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1}) << endl;


}