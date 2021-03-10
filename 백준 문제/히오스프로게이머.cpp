#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int primeNum[200001];
vector<int> real_prime;
void primeNumber()
{
    for (int i = 2; i <= 200000; i++)
        primeNum[i] = i;

    for (int i = 2; i <= sqrt(200000); i++)
    {
        if (primeNum[i] == 0)
            continue;

        for (int j = i * i; j <= 200000; j += i)
            primeNum[j] = 0;
    }

  
    for (int i = 2; i <= 200000; i++)
        if (primeNum[i] != 0)
            real_prime.push_back(primeNum[i]);



}



int main()
{



    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    long long right = 1000000001;
    long long left = 0;
    long long minval = 0;
    while (left <= right)
    {
        long long mid = (left + right) >> 1;
        long long tot = 0;
        for (auto i : res)
        {
            tot += mid - i >= 0 ? mid - i : 0;
        }

        if (tot <= m)
        {
            left = mid + 1;
            minval = max(minval, mid);
        }
        else
        {
            
            right = mid - 1;
            
        }


    }

    cout << minval;

}
