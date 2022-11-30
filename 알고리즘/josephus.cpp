#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

std::vector < int> josephus(std::vector < int > items, int k) {
	//your code here
	int count = items.size();
	int i = 0;
	vector<int> res;
	while (count > 0)
	{
		i = (i + k - 1) % count;
		res.push_back(items[i]);
		items.erase(items.begin() + i);
		count--;
	}

	return res;

}


int main()
{
	vector<int> res{ 1,2,3,4,5,6,7 };

	auto k = josephus(res, 3);

	for (auto it : k)
		cout << it << ' ';
	cout << endl;
}