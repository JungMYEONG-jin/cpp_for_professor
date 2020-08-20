#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

bool isPrime(long long n)
{
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int get_prime_count(long long n)
{
    int count = 0;
    for (int i = 2; i <= n; )
    {
        if (isPrime(i) && n % i == 0)
        {
            count++;
            n /= i;
        }
        else
            i++;
    }
    return count;
}

class KPrimes
{
public:
    static std::vector<long long> countKprimes(int k, long long start, long long end);
    static int puzzle(int s);
};

vector<long long> KPrimes::countKprimes(int k, long long start, long long end)
{
    vector<long long> res{};
    
    for (long long i = start; i <= end; i++)
    {
        int count = 0;
        long cur = i;
        for (int j = 2; j <= cur / j; j++)
        {
            while (cur % j == 0)
            {
                count++;
                cur /= j;
            }
        }
        if (cur > 1)
            count++;

        if(count == k)
            res.push_back(i);
    }
    return res;



}

int KPrimes::puzzle(int s)
{
    vector<long long> a = countKprimes(1, 2, s - 1);
    vector<long long> b = countKprimes(3, 2, s - 1);
    vector<long long> c = countKprimes(7, 2, s - 1);
    int count = 0;

   

    for (auto i : a)
    {
        for (auto k : b)
        {
            for (auto j : c)
                if (i + k + j == s)
                    count++;
        }
    }

    return count;

}







int main()
{
    cout << get_prime_count(500) << endl;
    cout << get_prime_count(520) << endl;
    cout << get_prime_count(552) << endl;
    cout << get_prime_count(567) << endl;
    cout << get_prime_count(588) << endl;
    cout << get_prime_count(592) << endl;
    cout << get_prime_count(594) << endl;

    auto test = KPrimes::countKprimes(5, 500, 600);

    for (auto const& i : test)
        cout << i << ' ';
    cout << endl;
    
    cout << KPrimes::puzzle(143) << endl;
    cout << KPrimes::puzzle(138) << endl;
    cout << KPrimes::puzzle(250) << endl;

    

    
}
