#include <iostream>
#include <string>
#include <string_view>


using namespace std;


class Person
{
public:
	Person();
	Person(string_view first, string_view last, int age);
	Person(const Person& rhs);
	virtual ~Person();



	string_view getFirstName() const { return mfirst; }
	string_view getLastName() const { return mlast; }
	int getAge() const { return mage; }





private:
	string_view mfirst;
	string_view mlast;
	int mage = 0;
};


Person::Person()
{
	cout << "Default Constructor" << endl;
}


Person::Person(string_view first, string_view last, int age)
	:mfirst(first), mlast(last), mage(age)
{
	cout << "Constructor" << endl;

}


Person::~Person()
{
	cout << "Deconstructor" << endl;
}


Person::Person(const Person& rhs)
	:mfirst(rhs.mfirst), mlast(rhs.mlast), mage(rhs.mage)
{
	cout << "Copy Constructor" << endl;
}



ostream& operator<<(ostream& os, const Person& p)
{
	os << p.getFirstName() << ", " << p.getLastName() << ", " << p.getAge() << endl;

	return os;
}

void processPerson(const Person&)
{

}


Person createPerson()
{
	Person newP("marg", "karena", 34);
	return newP;
}

/*int main()
{
	Person me("lae", "cena", 22);
	processPerson(me);

	cout << "-----------" << endl;
	cout << createPerson();
	cout << "----------" << endl;

	createPerson();

	return 0;


	*/