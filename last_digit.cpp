#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int Mod(int a, string b)
{
	int mod = 0;
	for (int i =0; i < b.size(); i++)
	{
		mod = (mod * 10 + b[i] - '0') % a;

	}
	return mod;
}




int LastDigit(string a, string b)
{
	int asize = a.size();
	int bsize = b.size();

	if (asize == 1 && bsize == 1 && b == "1")
		return stoi(a);
	if (asize == 1 && bsize == 1 && b == "0")
		return 1;
	if (a == "0" && b=="1")
		return 1;
	if (a == "0")
		return 0;


	int base = a[asize - 1] - '0';
	int mod = Mod(4, b) == 0 ? 4 : Mod(4, b);

	int res = pow(base, mod);
	

	return res % 10;
	




}




int main()
{
	cout << LastDigit("4", "1") << endl;
	cout << LastDigit("4", "2") << endl;
	cout << LastDigit("4", "3") << endl;
	cout << LastDigit("9", "7") << endl;
	cout << LastDigit("1606938044258990275541962092341162602522202993782792835301376", "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376") << endl;
	cout << LastDigit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651") << endl;
}