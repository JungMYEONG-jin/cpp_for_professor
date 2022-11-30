#include <iostream>
#include <ratio>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cmath>


using namespace std;
using namespace std::chrono;

int main()
{
	//현재 시각 time_point 로 가져옴

	system_clock::time_point tpoint = system_clock::now();

	time_t tt = system_clock::to_time_t(tpoint);
	tm t;
	localtime_s(&t,&tt);
	char buf[80] = { 0 };
	strftime(buf, sizeof(buf), "%H: %M: %S", &t);
	cout << buf << endl;






	//get start time
	auto start = high_resolution_clock::now();


	double d = 0;

	for (int i = 0; i < 1000000; ++i)
	{
		d += sqrt(sin(i) * cos(i));
	}

	auto end = high_resolution_clock::now();

	auto diff = start - end;

	cout << duration< double, milli>(diff).count() << "ms" << endl;

	cout << d << endl;




	return 0;


}
