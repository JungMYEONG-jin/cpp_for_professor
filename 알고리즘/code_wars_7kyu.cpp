#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
std::vector<int> solution(std::vector<int> nums) {
	
	sort(nums.begin(), nums.end());

	return nums;

	
}


int main()
{
	vector<int> test{ 1,5,10,2,20 };

	vector<int> acc = solution(test);

	for (auto const& i : acc)
		cout << i << " ";

}