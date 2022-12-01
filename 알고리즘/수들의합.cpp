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
	
    int n, m;
    cin >> n >> m;

    vector<int> res(n);
    for (int i = 0; i < n; i++)
        cin >> res[i];
    int cnt = 0;
    int sum = 0;
    int left = -1;
    int right = -1;
    while (true) {
        if (right < n - 1) {
            if (sum < m) {
                sum += res[++right];
            }
            else {
                sum -= res[++left];
            }
        }
        else { // 끝가지 갔을때 앞에서 한칸 이동
            sum -= res[++left];
        }
        if (sum == m)
            cnt++;
        if (right >= n - 1 && left >= n - 1)
            break;
    }
    cout << cnt << endl;

}
// 2335
