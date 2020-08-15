#include <iostream>
#include "Library/MJ/libs/date/include/date/iso_week.h"
#include "Library/MJ/libs/date/include/date/date.h"


using namespace std;

inline int year_of_day(int const y, unsigned int const m, unsigned int const d)
{

	using namespace date;

	return (sys_days{ year{y} / month{m} / day{d} } - sys_days{ year{y} / month{jan} / day{0} }).count();

}

inline int calender_week(int const y, unsigned int const m, unsigned int const d)
{
	using namespace date;

	if (m < 1 || m>12 || d < 1 || d>31) return 0;

	auto dt = date::year_month_day{ year{y} / month{m} / day{d} };
	auto tiso = iso_week::year_weeknum_weekday(dt);
	return (unsigned int)tiso.weeknum();



}


int main()
{
	cout << year_of_day(2020, 1, 1) << " "<<calender_week(2020, 1, 1) << endl;
	cout << year_of_day(2020, 8, 12) << " " << calender_week(2020, 8, 12) << endl;
}