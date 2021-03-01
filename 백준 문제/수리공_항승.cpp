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

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    int n, L;
    cin >> n >> L;

    int val = 1;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int mval = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - mval > L - 1)
        {
            mval = arr[i];
            val++;
        }
    }
    
    cout << val;

    return 0;
}
