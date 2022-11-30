
#include <iostream>
#include "temp_test.h"

using namespace std;



int main()
{
    using namespace test_temp;
    using namespace literal;

    auto t1{ 36.5_deg };
    auto t2{ 79.0_F };
    auto t3{ 100.0_K };

    {
        auto tf = temper_cast<scale::fahren>(t1);
        auto tc = temper_cast<scale::celsius>(tf);
        assert(t1 == tc);
    }

    {
        auto tk = temper_cast<scale::kelvin>(t1);
        auto tc = temper_cast<scale::celsius>(tk);
        assert(t1 == tc);
    }

    {
        auto tc = temper_cast<scale::celsius>(t2);
        auto tf = temper_cast<scale::fahren>(tc);
        assert(t2 == tf);
    }

    {
        auto tk = temper_cast<scale::kelvin>(t2);
        auto tf = temper_cast<scale::fahren>(tk);
        assert(t2 == tf);
    }

    {
        auto tc = temper_cast<scale::celsius>(t3);
        auto tk = temper_cast<scale::kelvin>(tc);
        assert(t3 == tk);
    }

    {
        auto tf = temper_cast<scale::fahren>(t3);
        auto tk = temper_cast<scale::kelvin>(tf);
        assert(t3 == tk);
    }
}