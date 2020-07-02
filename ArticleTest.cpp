#include "ArticleCitations.h"
#include <iostream>

using namespace std;

void processCitations(ArticleCitations cit)
{
	cout << cit.getArticle() << endl;
	int num = cit.getNum();
	for (int i = 0; i < num; i++) {
		cout << cit.getCitations(i) << endl;
	}
}

int main()
{
	while (true) {
		cout << "Enter a file name (\"STOP\" to stop): ";
		string fileName;
		cin >> fileName;
		if (fileName == "STOP") {
			break;
		}

		ArticleCitations cit(fileName);
		processCitations(cit);
	}

	return 0;
}
