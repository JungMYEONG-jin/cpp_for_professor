#include <string>
#include <iostream>



using namespace std;


bool XO(const std::string& str)
{
	// your code here

	


	int count_x = count(str.begin(), str.end(), 'x');
	count_x += count(str.begin(), str.end(), 'X');
	int count_o = count(str.begin(), str.end(), 'o');
	count_o += count(str.begin(), str.end(), 'O');

	if (count_x == count_o || (count_x == 0 && count_o == 0))
		return true;
	return false;

	



	return true;
}

int main()
{

	cout << XO("ab") << endl;
	cout << XO("xxoo") << endl;
	cout << XO("xooxx") << endl;
	cout << XO("xXxoOO") << endl;

}