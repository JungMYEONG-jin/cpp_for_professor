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
    int a, b, c;
    int stage = 1;
    while (true)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;


        int div = c / b;
        int rest = c % b;
        int day = div * a + min(a,rest);


        cout << "Case " << stage << ": " << day<<'\n';


        stage++;
    }

    return 0;
}
