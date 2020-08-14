#include <chrono>
#include <iostream>
#include <ctime>
#include <string>
#include "Library/MJ/libs/date/include/date/date.h"

using namespace std;

int GetTimeT(int year, int month, int day, int hour, int min, int sec);



inline int number_of_days(int const y1, unsigned int const m1, unsigned int const d1, int const y2, unsigned int const m2, unsigned int const d2)
{
	using namespace date;
	return (sys_days{ year{y1} / month{m1} / day{d1} } - sys_days{ year{y2} / month{m2} / day{d2} }).count();
}


inline int number_of_days(date::sys_days const& s1, date::sys_days const& s2) {

	return (s2 - s1).count();
}



int main()
{
	/*
	int year = 0, month = 0, day = 0;

	cout << "First Date" << endl;
	cout << "Year: "; (cin >> year);
	cout << "Month: "; cin >> month;
	cout << "Day: "; cin >> day;


	int year2 = 0, month2 = 0, day2 = 0;
	cout << "Second Date" << endl;
	cout << "Year: "; (cin >> year2);
	cout << "Month: "; cin >> month2;
	cout << "Day: "; cin >> day2;
	

	cout << number_of_days(year, month, day, year2, month2, day2) << endl;
	*/
	using namespace date::literals;
	std::cout << "Days between:" << number_of_days(2018_y / jun / 1, 15_d / sep / 2018) << std::endl;
	cout << "Days between:" << number_of_days(2020_y / aug / 1, 14_d / aug / 2020) << endl;

}



