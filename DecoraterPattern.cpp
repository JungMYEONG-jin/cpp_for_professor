#include "DecoraterPattern.h"
#include <iostream>


using namespace std;


int main()
{
	Paragraph p("MJ is genius man");
	cout << p.getHTML() << endl;

	cout << Bold(p).getHTML()<< endl;

	cout << Bold(Italic(p)).getHTML() << endl;


}