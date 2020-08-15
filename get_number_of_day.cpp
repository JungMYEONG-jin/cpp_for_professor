#include <chrono>
#include "Library/MJ/libs/date/include/date/iso_week.h"
#include "Library/MJ/libs/date/include/date/date.h"
#include <iostream>
#include <string>
using namespace std;


inline int get_number_of_day(int const y, unsigned int const m, unsigned int const d)
{
	using namespace date;
	auto dt = date::year_month_day{ year{y}, month{m}, day{d} };

	auto tiso = iso_week::year_weeknum_weekday(dt);

	return (unsigned int)tiso.weekday();
}

inline string get_day(int const y, unsigned int const m, unsigned int const d)
{

	auto t = get_number_of_day(y, m, d);

	switch (t)
	{
	case 1:
		return "월요일";
	case 2:
		return "화요일";
	case 3:
		return "수요일";
	case 4:
		return "목요일";
	case 5:
		return "금요일";
	case 6:
		return "토요일";
	case 7:
		return "일요일";
	}



}

int main()
{
	cout << get_number_of_day(2020, 8, 15) << ": " << get_day(2020, 8, 15) << endl;
	cout << get_number_of_day(2020, 8, 29) << endl;
}