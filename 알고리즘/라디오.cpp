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


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, cnt;
    cin >> n >> m;
    cin >> cnt;
    vector<int> arr(cnt);
    for (int i = 0; i < cnt; i++)
        cin >> arr[i];
    
    int minValue = abs(n - m);
    for (auto i : arr) {
        minValue = min(minValue, 1 + abs(i - m));
    }
    cout << minValue;


   
}
// 2335
