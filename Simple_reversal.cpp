#include <iostream>
#include <string>

using namespace std;
std::string solve(std::string eq) {
	//..
	
	for (int i = 0; i < eq.size(); i++)
	{
		if (isdigit(eq[i]) && isdigit(eq[i + 1]))
			swap(eq[i], eq[i + 1]);
	}

	reverse(eq.begin(), eq.end());

	return eq;

}
