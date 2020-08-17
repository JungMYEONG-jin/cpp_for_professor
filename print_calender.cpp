#include <iostream>
#include "Library/MJ/libs/date/include/date/iso_week.h"
#include "Library/MJ/libs/date/include/date/date.h"
#include <iomanip>
using namespace std;

inline int get_week_num(int const y, unsigned int const m, unsigned int const d)
{
	using namespace date;

	if (m < 1 || m>12 || d < 1 || d>31)
		return -1;

	auto dt = year_month_day{ year{y} / month{m} / day{d} };
	auto tiso = iso_week::year_weeknum_weekday(dt);

	return (unsigned int)tiso.weekday();
}




void print_calender(int const y, unsigned int m)
{
	using namespace date;

	cout << "Mon Tue Wed Thu Fri Sat Sun" << endl;
	auto first_day_weekday = get_week_num(y, m, 1);
	auto last_day = (unsigned int)year_month_day_last(year{y} / month_day_last{month{m}}).day();

	unsigned int idx = 1;
	for (unsigned int i = 1; i < first_day_weekday; ++i, ++idx)
	{
		cout << "   ";
	}

	for (unsigned int day = 1; day <= last_day; day++)
	{
		cout << right << setfill(' ') << setw(3) << day << ' ';
		if (idx++ % 7 == 0) // 주마다 라인분리
			cout << endl;
	}

	cout << endl;

}

int main()
{
	print_calender(2020, 8);
	
}