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

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


int solution(int storey) {
    int ans = 0;
    while (storey != 0) {
        int a = storey % 10;
        int b = 10 - a;

        if (a >= 6)
        {
            ans += b;
            storey += b;
        }
        else if (a == 5 && (storey / 10) % 10 >= 5) {
            ans += b;
            storey += b;
        }
        else
            ans += a;
        storey /= 10;
     }
    return ans;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution(678) << endl;
    cout << solution(5) << endl;
    cout << solution(15) << endl;
    cout << solution(95) << endl;
    cout << solution(999) << endl;
    cout << solution(2554) << endl;

    
   
}
// 2335
