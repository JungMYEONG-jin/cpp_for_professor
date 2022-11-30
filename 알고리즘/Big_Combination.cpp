#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

ll fact[3000005], factInv[3000005], mod = 1e9 + 7;

ll mpow(ll x, ll m) {
    if (!m) return 1;
    ll tmp = mpow(x, m / 2);
    tmp = tmp * tmp % mod;
    if (m % 2) return tmp * x % mod;
    return tmp;
}

ll Com(ll x, ll r) {
    return fact[x] * factInv[r] % mod * factInv[x - r] % mod;
}








int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i <= 3000000; i++) fact[i] = fact[i - 1] * i % mod;
    factInv[3000000] = mpow(fact[3000000], mod - 2);
    for (int i = 2999999; i >= 0; i--) factInv[i] = factInv[i + 1] * (i + 1) % mod;

    int dp[31][31] = { 0 };

    for (int i = 0; i <= 30; i++)
        dp[1][i] = i;

    for (int i = 2; i <= 30; i++)
    {
        for (int j = i; j <= 30; j++)
        {
            for (int k = j; k >= i; k--)
                dp[i][j] += dp[i - 1][k - 1];
        }
    }


    int n, r;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> r >> n;
        cout << Com(n, r) << endl;
        cout << dp[r][n] << endl;
    }
}
