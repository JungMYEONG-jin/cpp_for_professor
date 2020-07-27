#include <vector>
#include <iostream>
#include <list>

using namespace std;


template <typename T, typename... args>
void push_back(T& t, args&&... arg)
{
	(t.push_back(arg), ...);
	
}


int main()
{
	vector<int> my;

	push_back(my, 12, 3, 4, 5, 6, 7, 8);

	for (const auto& p : my)
		cout << p << endl;

	copy(begin(my), end(my), ostream_iterator<int>(cout, " "));
	cout << endl;
	list<int> l;

	push_back(l, 1, 2, 3, 4, 5);
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));

}


