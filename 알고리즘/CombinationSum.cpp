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
vector<vector<int>> ans;
void backTracking(vector<int>& candidates, int idx, int target, vector<int>& temp) {
	if (target == 0) {
		ans.push_back(temp);
		return;
	}

	for (int i = idx, len = candidates.size(); i < len; i++) {
		if (candidates[i] <= target) {
			temp.push_back(candidates[i]);
			backTracking(candidates, i, target - candidates[i], temp);
			temp.pop_back();
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	for (int i = 0, len = candidates.size(); i < len; i++) {
		vector<int> temp;
		temp.push_back(candidates[i]);
		backTracking(candidates, i, target - candidates[i], temp);
	}
	return ans;
}
