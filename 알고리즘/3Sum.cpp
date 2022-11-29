#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <set>
#include <numeric>
#include <cmath>
#include <stack>

#define INF 1000000000

using namespace std;

vector<vector<int>> res;

void twoSum(vector<int>& nums, int pivot, int idx) {
	int start = idx + 1;
	int end = nums.size() - 1;
	int target = -pivot;

	int sum;
	while (start < end) {
		sum = nums[start] + nums[end];
		if (sum == target) {
			res.push_back({ pivot, nums[start++], nums[end--] });
			while (start < end && nums[start] == nums[start - 1])start++; // 중복 제거
		}
		else if (sum < target)
			start++;
		else
			end--;
	}
}

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int len = nums.size();
	int left, right;
	for (int i = 0; i < len-1; i++) {
		if (i > 0 && nums[i] == nums[i - 1]) // 첫 원소를 기준으로 잡고 two sum을 하는데 현재가 이전 원소랑 같으면 더이상 진행할 이유가 없음
			continue;
		int pivot = nums[i];
		twoSum(nums, pivot, i);
	}
	return res;
}




int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> num = { -1,0,1,2,-1,-4 };
	vector<vector<int>> res = threeSum(num);
	cout << res.size() << endl;

}
// 2335
