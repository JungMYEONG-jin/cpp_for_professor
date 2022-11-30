#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <array>
#include <assert.h>
#include <iostream>


template<typename Iter>
std::string bytes_to_string(Iter begin, Iter end, bool const uppercase = false)
{
	std::ostringstream oss;

	if (uppercase)
		oss.setf(std::ios_base::uppercase);
	for (; begin != end; ++begin)
		oss << std::hex<<std::setw(2) << std::setfill('0') <<static_cast<int>(*begin);

	return oss.str();

}

template<typename C>
std::string bytes_to_string(C const& c, bool const uppercase = false)
{
	return bytes_to_string(std::cbegin(c), std::cend(c), uppercase);
}

using namespace std;
int main()
{
	vector<unsigned char> v{ 0xBA, 0xAD };
	cout << bytes_to_string(v,true) << endl;
	array<unsigned char, 6> a{ {1,2,3,4,5,6} };
	unsigned char buf[5] = { 0x11, 0x22, 0x33, 0x44, 0x55 };
	cout << bytes_to_string(a) << endl;
	cout << bytes_to_string(buf) << endl;
}

