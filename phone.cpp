#include <string>
#include <iostream>


using namespace std;

std::string createPhoneNumber(const int arr[10]) {
	//your code here
	string format = "";


	for (int i = 0; i < 10; i++)
	{
		format += to_string(arr[i]);
	}
	format.replace(0, 0, "(");
	format.replace(4, 0, ") ");
	format.replace(9, 0, "-");
	return format;
	/*
	char buf[15];
	snprintf(buf, sizeof(buf), "(%d%d%d) %d%d%d-%d%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
	return buf;
	*/

	// solution 2
	char buf[15];
	snprintf(buf, sizeof(buf), "(%d%d%d) %d%d%d-%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
	return buf;
}

using arr = int[10];
int main()
{

	cout << createPhoneNumber(arr{ 0,1,2,3,4,5,6,7,8,9 }) << endl;
}