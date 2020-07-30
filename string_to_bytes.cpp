#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <array>
#include <assert.h>
#include <iostream>

using namespace std;

unsigned char hexchar_to_int(char const ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	if (ch >= 'A' && ch <= 'F')
		return ch - 'A' + 10;
	if (ch >= 'a' && ch <= 'f')
		return ch - 'a' + 10;
	throw invalid_argument("지정된 형식에 맞춰서 작성해주세요!");
}

vector<unsigned char> hexstr_to_bytes(string_view test)
{
	vector<unsigned char> temp;
	for (int i = 0; i < test.size(); i+=2)
	{
		temp.push_back((hexchar_to_int(test[i])<<4) | hexchar_to_int(test[i + 1]));
	}

	return temp;
}


int main()
{
	std::vector<unsigned char> expected{ 0xBA, 0xAD, 0xF0, 0x0D, 0x42 };
	assert(hexstr_to_bytes("BAADF00D42") == expected);
	assert(hexstr_to_bytes("BaaDf00d42") == expected);
}
