#include <iostream>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	/*
	using r1 = ratio<1, 60>;
	cout << r1::num << "/" << r1::den << endl;


	intmax_t num = r1::num;
	intmax_t den = r1::den;
	cout << num << "/" << den << endl;



	using r2 = ratio<1, 30>;
	cout << r2::num << "/" << r2::den << endl;
	using res = ratio_add<r1, r2>::type;
	cout << res::num << "/" << res::den << endl;



	using result = ratio_greater<r2, r1>;
	cout << boolalpha << result::value << endl;
	*/






	duration<long, ratio<60>> d1(123); // one tick is 60sec
	cout << d1.count() << endl;


	duration<double> d2; //one tick is 1 sec and assign max duration on double type
	d2 = d2.max();
	cout << d2.count() << endl;

	duration<long, ratio<60>> d3(10);  // 10minutes
	duration<long, ratio<1>> d4(14); //14sec

	if (d3 > d4)
		cout << "d3 is bigger" << endl;
	else
		cout << "d4 is bigger" << endl;


	++d4;
	d4 *= 2;

	duration<double, ratio<60>> d5 = d3 + d4; //10.5

	duration<long, ratio<1>> d6 = d3 + d4; // 630

	

	cout << d5.count() << endl;
	cout << d6.count() << endl;

	duration<long> d7(30);

	duration<double, ratio<60>> d8(d7);

	cout << d8.count() << endl;


	auto d8_ = duration_cast<duration<long, ratio<60>>>(d7);
	cout << d8_.count() << endl;

	duration<long, ratio<60>> d9(10);
	duration<long> d10(d9);
	cout << d10.count() << endl;



	auto t = hours(1) + minutes(23) + seconds(45);
	cout << seconds(t).count() << " seconds" << endl;

	auto mydur = 42min;

	auto d11 = duration_cast<duration<double, ratio<1>>>(mydur);
	cout << d11.count() << endl;

	return 0;


}
