## 소수 구하기 에라토스테네스체로 구함

```c++
class Solution {
public:

    int primes[5000001];
    int countPrimes(int n) {
        int ans = 0;
        for (int i = 2; i < n; i++) {
            primes[i] = i;
        }

        for (int i = 2; i <= sqrt(n); i++) {
            if (primes[i] == 0)
                continue;
            for (int j = i * i; j < n; j += i)
                primes[j] = 0;
         }
    
        for (int i = 2; i < n; i++)
            if (primes[i] != 0)
                ans++;

        return ans;
    }
       
};

```
