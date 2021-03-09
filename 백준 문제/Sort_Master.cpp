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
#include <functional>

using namespace std;




int bin_search(vector<long long>& res, long long num) {

    int left = 0;
    int right = res.size() - 1;
    int min_val = 123456789;
    set<int> st;
    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (res[mid] == num)
        {
            min_val = min(mid, min_val);
            st.insert(min_val);
        }

        if (res[mid] < num)
            left = mid + 1;
        else
        {
            right = mid - 1;

        }
    }

    return !st.empty() ? *st.begin() : -1;

}






int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long x;


    


    for (int i = 0; i < m; i++)
    {
        cin >> x;
        cout << bin_search(arr, x) << '\n';
    }







}
