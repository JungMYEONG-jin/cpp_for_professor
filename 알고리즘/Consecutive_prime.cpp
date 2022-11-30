#include <vector>
#include <iostream>

using namespace std;

bool chk_primes(long long n)
{
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}


class PrimeConsec
{
private:
    static int countPrimeDiv(long long n)
    {
        int count = 0;
        for (int i = 2; i <= n;)
        {
            if (chk_primes(i) && n % i == 0)
            {
                count++;
                n /= i;
            }
            else
                i++;

        }
        return count;
    }
public:
    static int consecKprimes(int k, std::vector<long long>& arr)
    {
        for (auto& i : arr)
        {
            i = countPrimeDiv(i);
        }
        int count = 0;
        for (int i = 0; i < arr.size()-1; i++)
        {
            if (arr[i] == k && arr[i] == arr[i + 1])
                count++;
        }

        return count;
        
    }
};



int main()
{

    vector<long long> arr = { 10005, 10030, 10026, 10008, 10016, 10028, 10004 };
    cout << PrimeConsec::consecKprimes(4, arr) << endl;

        

}