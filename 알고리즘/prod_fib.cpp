#include <vector>
#include <iostream>

using namespace std;


typedef unsigned long long ull; 
vector<ull> prod_fib(ull prod)
{
    ull a = 0, b = 1;
    while (a * b < prod) {
        std::swap(a, b);
        b += a;
    }
    bool pred = ((a * b == prod) ? true : false);
    vector<ull> res;
    res.push_back(a);
    res.push_back(b);
    res.push_back(pred);
    return res;
}