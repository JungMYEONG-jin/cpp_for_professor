#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


string Decode(int d)
{
	if (d < 0)
		return "00";
	if (d > 255)
		return "FF";

	stringstream ss;
	ss << uppercase << setw(2) << setfill('0') << hex << d;
	return ss.str();


}


string RGB_to_HEX(int r, int g, int b)
{
	return Decode(r) + Decode(g) + Decode(b);
}

int main()
{
	cout << RGB_to_HEX(255, 255, 255) << endl;
	cout <<RGB_to_HEX(255, 255, 300) << endl;
	cout << RGB_to_HEX(0, 0, 0) << endl;
	cout << RGB_to_HEX(148, 0, 211) << endl;

}