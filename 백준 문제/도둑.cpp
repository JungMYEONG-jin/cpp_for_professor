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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.tie(NULL);
    int t;
    cin >> t;
    int n, m;
    long long k;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m >> k;
        //vector<long long> arr(n);
        long long sum=0;
        vector<long long> res(n);
        int num = 0;
        for (int i = 0; i < n; i++)
            cin >> res[i];
        for (int i = 0; i < m; i++)
            sum += res[i];
        if (sum < k)
            num++;
        
        for (int i = 1; i < n; i++)
        {
            if(i-1==(i-1+m+n)%n) continue;
            sum -= res[i - 1];
            sum+= res[( m+i-1 + n) % n];
            if (sum < k)
                num++;
        }
        
        cout << num << '\n';

    }
}
