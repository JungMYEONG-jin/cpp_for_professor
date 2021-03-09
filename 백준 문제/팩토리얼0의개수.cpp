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

typedef long long ll;



    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        int m;
        cin >> m;

        long long left = 0;
        long long right = 500000000;

        long long min_num = 999999999;

        while (left <= right)
        {
            long long mid = (left + right) >> 1;
            long long n = 0;
            for (int i = 5; i <= mid; i *= 5)
            {
                n += mid / i;
            }

            if (n < m)
            {
                left = mid + 1;
            }
            else
            {
                if (n == m)
                {
                    min_num = min(min_num, mid);
                }

                right = mid - 1;

            }

        }
        if (min_num == 999999999)
            min_num = -1;
        cout << min_num;
    }

