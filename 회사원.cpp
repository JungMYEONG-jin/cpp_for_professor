#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <regex>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <sstream>

using namespace std;

int get_count_first(vector<pair<int, int>>& res)
{
    stack<pair<int, int>> result;
    sort(res.begin(), res.end(), [](auto e, auto k) {
        return e.first < k.first;
        });
    result.push(res[0]);
    for (int i=1;i<res.size();i++)
    {
        if (!result.empty() && result.top().second > res[i].second)
            result.push(res[i]);
        
    }
    return result.size();
}

int get_count_second(vector<pair<int, int>>& res)
{
    stack<pair<int, int>> result;
    sort(res.begin(), res.end(), [](auto e, auto k) {
        return e.second < k.second;
        });
    for (auto i : res)
    {
        if (!result.empty() && (result.top().first < i.first))
            result.pop();
        result.push(i);
    }
    return result.size();
}







int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<pair<int, int>> res(n);
        for (int i = 0; i < n; i++)
        {
            cin >> res[i].first >> res[i].second;
        }

        cout << get_count_first(res) << '\n';
 
    }

}
