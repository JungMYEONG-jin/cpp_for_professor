#include <iostream>
#include <deque>
#include <string>
#include <vector>



using namespace std;


std::string who_is_next(const std::vector<std::string>& names, long long r) {
	
	deque<string> test;
	int i = 0;
	string a;
	while (i<names.size())
	{
		test.push_back(names[i]);
		i++;

	}


	r--;
	while (r>=names.size())
	{
	

		r = r - names.size();
		r = r / 2;
	
	}


	return test[r];



}




int main()
{

	std::vector<std::string> names = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };


	cout << who_is_next(names, 1) << endl;
	cout << who_is_next(names, 52) << endl;
	cout << who_is_next(names, 7230702951) << endl;
}