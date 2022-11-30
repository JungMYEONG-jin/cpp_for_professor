#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


class Arge
{
public:
    static int nbYear(int p0, double percent, int aug, int p)
    {
        int year = 0;

        while (true)
        {
            p0 = p0 + p0 * percent/100 + aug;
            year++;
            if (p0 >= p)
                return year;
        }

    }
};







