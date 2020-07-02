#include "ArticleCitations.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>


using namespace std;


ArticleCitations::ArticleCitations(string_view fileName)
	:mCitations(nullptr), mNums(0)
{
	// only read file
	readFile(fileName);
}

ArticleCitations::ArticleCitations(const ArticleCitations& src)
{
	copy(src);
}

ArticleCitations& ArticleCitations::operator=(const ArticleCitations& rhs)
{
	if (this == &rhs)
		return *this;

	delete[] mCitations;
	copy(rhs);

	return *this;
}






void ArticleCitations::copy(const ArticleCitations& src)
{
	mArticle = src.mArticle;
	mNums = src.mNums;
	mCitations = new string[mNums];

	for (int i = 0; i < mNums; i++)
		mCitations[i] = src.mCitations[i];



}


ArticleCitations::~ArticleCitations()
{
	delete[] mCitations;
}

void ArticleCitations::readFile(string_view fileName)
{


	ifstream inputFile(fileName.data());
	// ���� ���� ���� �ִ��� Ȯ��
	if (inputFile.fail())
	{
		throw invalid_argument("Unable to open File");
	}
	getline(inputFile, mArticle);
	//������ �ǳ� �ڴ�.
	inputFile >> ws;

	int count = 0;

	streampos citationStart = inputFile.tellg();
	
	while (!inputFile.eof())
	{
		inputFile >> ws;

		string temp;
		getline(inputFile, temp);
		if (!temp.empty())
		{
			count++;
		}
	}
	

	delete[] mCitations;
	mCitations = nullptr;
	mNums = 0;


	if (count != 0)
	{
		mCitations = new string[count];
		mNums = count;
		inputFile.clear();
		// stream clear
		inputFile.seekg(citationStart);
		//�ο� ������ ù ȭ������ ���ư�
		for (count = 0; count < mNums; count++)
		{
			string temp;
			getline(inputFile, temp);
			if (!temp.empty())
			{
				mCitations[count] = temp;
			}
		}

	}

	cout << "ReadFile(): finished" << endl;


}






