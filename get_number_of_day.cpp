#include <chrono>
#include "Library/MJ/libs/date/include/date/iso_week.h"
#include "Library/MJ/libs/date/include/date/date.h"
#include <iostream>

using namespace std;


inline int get_number_of_day(int const y, unsigned int const m, unsigned int const d)
{
	using namespace date;
	auto dt = date::year_month_day{ year{y}, month{m}, day{d} };

	auto tiso = iso_week::year_weeknum_weekday(dt);

	return (unsigned int)tiso.weekday();
}


int main()
{
	cout << get_number_of_day(2020, 8, 15) << endl;
	cout << get_number_of_day(2020, 8, 29) << endl;
}