#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <regex>
#include <map>
using namespace std;

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll a, b;
    cin >> a >> b;
    ll k = 2;
    ll sum = b - a + 1;
    
    vector<bool> res(b - a + 1, false);

    while (k * k <= b)
    {
        
        ll temp = a / (k * k);

        if (a % (k * k) != 0)
            temp += 1;

        while (temp * (k * k) <= b)
        {
            if (res[temp * (k * k) - a] == false)
            {
                res[temp * (k * k) - a] = true;
                sum--;
            }



            temp++;
        }

        k++;
   }

    cout << sum << endl;


    return 0;
}
