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









void createMap(unordered_map<string, char>* m)
{
    (*m)["000"] = '0';
    (*m)["001"] = '1';
    (*m)["010"] = '2';
    (*m)["011"] = '3';
    (*m)["100"] = '4';
    (*m)["101"] = '5';
    (*m)["110"] = '6';
    (*m)["111"] = '7';
}


void createMap2(unordered_map<char, string>* m)
{
    (*m)['0'] = "000";
    (*m)['1'] = "001";
    (*m)['2'] = "010";
    (*m)['3'] = "011";
    (*m)['4'] = "100";
    (*m)['5'] = "101";
    (*m)['6'] = "110";
    (*m)['7'] = "111";
}

string Octal_to_Bin(string oct)
{
    unordered_map<char, string> oct_bin;
    createMap2(&oct_bin);

    string bin;
    int i = 0;
    while (true)
    {
        bin += oct_bin[oct[i]];
        i++;
        if (i == oct.size())
            break;
    }

    bin = regex_replace(bin, regex("^0+"), "");

    return bin;
}





string Bin_to_Octal(string bin)
{
    int i = bin.size();


    for (int j = 1; j <= (3 - i % 3) % 3; j++)
    {
        bin = '0' + bin;
    }


    unordered_map<string, char> bin_oct;
    createMap(&bin_oct);

    int k = 0;
    string octal = "";

    while (true)
    {
        octal += bin_oct[bin.substr(k, 3)];
        k += 3;

        if (k == bin.size())
            break;


    }
    return octal;

}


void fraction_add(int num1, int dnum1, int num2, int dnum2)
{

    int num3 = num1 * dnum2 + num2 * dnum1;
    int dnum3 = dnum1 * dnum2;

    auto gcd = [&](int x, int y) {
        while (y != 0)
        {
            int c = x % y;
            x = y;
            y = c;
        }
        return x;
    };

    auto gcd_num = gcd(num3, dnum3);

    cout << num3 / gcd_num << " " << dnum3 / gcd_num << endl;

}

ll fact[4000001], mod = 1e9 + 7;

ll mpow(ll x, ll m) {
    if (!m) return 1;
    ll tmp = mpow(x, m / 2);
    tmp = tmp * tmp % mod;
    if (m % 2) return tmp * x % mod;
    return tmp;
}








int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i <= 4000000; i++) fact[i] = fact[i - 1] * i % mod;
    int n, k;
    cin >> n >> k;
    long long inv = mpow((fact[n - k] * fact[k]) % mod, mod - 2);

    cout << fact[n] * inv % mod << endl;
}


