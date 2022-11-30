#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <assert.h>


using namespace std;


template<typename Iter>
string with_delimiter(Iter begin, Iter end, char const* const delimiter)
{
	ostringstream oss;


	copy(begin, end - 1, ostream_iterator<string>(oss, delimiter));
	oss << *(end - 1);

	return oss.str();

}

template<typename C>
string with_delimiter(C const& c, char const* const delimiter)
{
	if (c.size() == 0)
		return "";
	return with_delimiter(begin(c), end(c), delimiter);
}







int main()
{

	vector<string> a{ "tHis", "karao", "jason", "hones" };

	string b = with_delimiter(a, ", ");
	cout << b << endl;



}


