#include <iostream>
#include <string>


using namespace std;



class Person
{
public:



	Person() = default;

	Person(const string& first_name, const string& last_name)
		:mfirst(first_name), mlast(last_name)
	{

	}

	const string& get_first_name()
	{
		return mfirst;
	}

	const string& get_last_name()
	{
		return mlast;
	}



private:
	string mfirst, mlast;
};

ostream& operator<<(ostream& out, Person p)
{
	return out << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();
}

int main()
{

	string first_name, last_name, event;


	cin >> first_name >> last_name >> event;

	auto p = Person(first_name, last_name);

	cout << p << " " << event << endl;

	return 0;





}

