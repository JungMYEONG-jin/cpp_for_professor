#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

string caesar_encrypt(string_view text, int const shift)
{
	string str;
	str.reserve(text.length());

	for (auto i : text)
	{
		if (isalpha(i) && isupper(i))
			str += 'A' + (i - 'A' + shift) % 26;
		else
			str += i;
	}
	return str;
}

string caesar_decrypt(string_view text, int const shift)
{
	string str;
	str.reserve(text.length());
	for (auto i : text)
	{
		if (isupper(i) && isalpha(i))
			str += 'A' + (i - 'A' + 26 - shift) % 26;
		else
			str += i;
	}
	return str;
}


int main()
{
	cout << caesar_encrypt("COME TO ROME", 3) << endl;
	cout << caesar_decrypt("FRPH WR URPH", 3) << endl;
}
