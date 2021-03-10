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
    cin >> n;
    primeNumber();
    
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int left = 0;
        int right = real_prime.size() - 1;
        int minv = 100000000;
        while (left < right)
        {
            int mid = real_prime[left] * real_prime[right];

            if (mid < x)
            {
                left++;
            }
            else
            {
                right--;
                minv = min(mid, minv);
            }
        }
        cout << minv << endl;

    }

    

}
