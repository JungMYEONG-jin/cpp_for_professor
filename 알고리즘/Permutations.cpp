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
bool visited[7];

void dfs(vector<int>& nums, vector<int>& temp, int cnt) {
    if (cnt == nums.size()) {
        res.push_back(temp);
        return;
    }
    for (int i = 0, len = nums.size(); i < len; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        temp.push_back(nums[i]);
        dfs(nums, temp, cnt + 1);
        temp.pop_back();
        visited[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> temp;
    dfs(nums, temp, 0);
    return res;
}




int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    vector<int> num = { 1,2,3 };
    permute(num);
    for (auto it : res) {
        for (auto num : it)
            cout << num << " ";
        cout << endl;
    }

}
// 2335
