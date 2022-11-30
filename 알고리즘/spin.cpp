#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


std::string spinWords(const std::string& str)
{
	string temp = "";
	
	string test;
	stringstream ss(str);


	while (getline(ss, temp, ' '))
	{
		if (temp.length() >= 5)
			reverse(temp.begin(), temp.end());
		
		test += temp;
		test += " ";

	}
	test.erase(test.length() - 1, 1);
	//string�� pop_back()����
	return test;


}// spinWords


//5�� �̻��̸� reverse






int main()
{


	cout << spinWords("Welcome") << endl;
	cout << spinWords("to") << endl;
	cout << spinWords("CodeWars") << endl;
}

