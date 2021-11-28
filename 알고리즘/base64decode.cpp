#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>

#define INF 999999999

using namespace std;

string base = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static int dtable[256] = {
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	/* 00-0F */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	/* 10-1F */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,	/* 20-2F */
	52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1,	/* 30-3F */ //0~9
	-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,	/* 40-4F */ //A-Z
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,	/* 50-5F */
	-1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,	/* 60-6F */// a~z
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1,	/* 70-7F */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	/* 80-8F */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	/* 90-9F */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	/* A0-AF */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	/* B0-BF */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	/* C0-CF */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	/* D0-DF */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	/* E0-EF */
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1		/* F0-FF */
};

/*
string base64encode(string input)
{
	unsigned char const* buffer = (unsigned char const*)(input.c_str());
	size_t size = input.size();
	unsigned char const* s = buffer;
	size_t idx = 0;
	size_t len = ceil(size * 4 / 3);
	string result = string(len, ' ');

	for (int i = 0; i < size / 3; i++)
	{
		result[idx++] = base[s[0] >> 2];
		result[idx++] = base[((s[0]<<4) | (s[1]>>4)) & 0x3f];
		result[idx++] = base[((s[1]<<2) | (s[2]>>6)) & 0x3f];
		result[idx++] = base[s[2] & 0x3f];
		s += 3;
	}

	size_t rem = size % 3;
	if (rem) // 존재시
	{
		if (rem == 1)
		{
			result[idx++] = base[s[0] >> 2];
			result[idx++] = base[(s[0] << 4) & 0x3f];
		}
		else if (rem == 2)
		{
			result[idx++] = base[s[0] >> 2];
			result[idx++] = base[((s[0] << 4) | (s[1] >> 4)) & 0x3f];
			result[idx++] = base[(s[1] << 2) & 0x3f];
		}

		result += "=";
	}

	return result;
}
*/




string base64decode(string input)
{
	//unsigned char dtable[256];
	//memset(dtable, 0x80, 256);
	//for (size_t i = 0, len = base.size(); i < len; i++)
	//	dtable[base[i]] = (unsigned char)i;
	//dtable['='] = 0;

	size_t real_len = 0;
	size_t blen = input.size();
	if (input.empty())
		return "";
	while (real_len < blen && dtable[input[real_len]] != -1)
		real_len++;
	

	size_t b64size = ceil(real_len / 4.0 * 3);
	size_t idx = 0;
	string out = string(b64size, ' ');
	size_t i = 0;



	for (i = 0; i + 4 < real_len; i+=4)
	{
		out[idx++] = static_cast<unsigned char>((dtable[input[i]] << 2 | dtable[input[i + 1]] >> 4));
		out[idx++] = static_cast<unsigned char>((dtable[input[i + 1]] << 4 | dtable[input[i + 2]]>>2));
		out[idx++] = static_cast<unsigned char>((dtable[input[i + 2]]<<6 | dtable[input[i + 3]]));
	}
	
	
	if (real_len - i > 1)
	{
		
		out[idx++] = static_cast<unsigned char>((dtable[input[i]] << 2 | dtable[input[i + 1]] >> 4));
		
	}
	if (real_len - i > 2)
	{
		out[idx++] = static_cast<unsigned char>((dtable[input[i + 1]]<<4 | dtable[input[i + 2]]>>2));
		
	}

	if (real_len - i > 3)
	{
		out[idx++] = static_cast<unsigned char>((dtable[input[i + 2]]<<6 | dtable[input[i + 3]]));
		
	}
	
	return out;

}



int main()
{
	cout << base64encode("E1L") << endl;
	cout << base64encode("Man") << endl;
	cout << base64encode("Many") << endl;
	cout << base64encode("Baekjoon") << endl;
	cout << base64encode("hello base64 !") << endl;

	cout << base64decode("RTFM") << endl;
	cout << base64decode("TWFu") << endl;
	cout << base64decode("TWFueQo=") << endl;
	cout << base64decode("QmFla2pvb24=") << endl;
	cout << base64decode("aGVsbG8gYmFzZTY0ICE=") << endl;
	

}
