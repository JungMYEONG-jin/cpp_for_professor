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
    int n;
    cin >> n;
    vector<ll> range(n - 1);
    vector<ll> city(n);

    for (int i = 0; i < n - 1; i++)
        cin >> range[i];
    for (int i = 0; i < n; i++)
        cin >> city[i];

    ll cost = city[0] * range[0];
    if(n==1)
    {
        cout<<cost;
        return 0;
    }
    ll mval = city[0];
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            break;
        mval = min(mval, city[i]);
        cost += mval * range[i];
        
    }

    cout << cost;


    return 0;
}
