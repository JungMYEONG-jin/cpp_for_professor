#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <tuple>
#include <map>
using namespace std;




bool check_prime_var(unsigned int number)
{
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}



long long near(long long n) {
    //..
    if (check_prime_var(n))
        return n;
    int low = 0;
    int high = 0;
    for (int i = n-1; i >=2 ; i--)
    {
        if (check_prime_var(i))
        {
            low = i;
            break;
        }
    }
 

    for (int i = n + 1; i < 2 * n; i++)
    {
        if (check_prime_var(i))
        {
            high = i;
            break;
        }
    }

    if (n - low <= high - n)
        return low;
    else
        return high;



}


int main()
{
    cout << check_prime_var(2) << endl;
    cout << check_prime_var(3) << endl;
    cout << check_prime_var(4) << endl;
    cout << check_prime_var(11) << endl;


    cout << near(3) << endl;
    cout << near(10) << endl;


}
