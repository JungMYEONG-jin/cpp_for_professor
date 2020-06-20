#include "MapNDB.h"
#include <stdexcept>
#include <fstream>


using namespace std;


NameDB::NameDB(std::string_view fileName)
{
	ifstream inputFile(fileName.data());
	if (!inputFile)
	{
		throw invalid_argument("Unable to open File!");

	}
	string name;
	while (inputFile >> name)
	{
		if (!nameExistsAndIncrement(name))
		{
			addNewName(name);
		}
	}
}
// DB에 이름이 있다면 true return 그렇지 않다면 false return
// 이름 발견시 갯수 증가
bool NameDB::nameExistsAndIncrement(string_view name)
{
	auto res = mNames.find(name.data());
	if (res != end(mNames)) {
		res->second++;
		return true;
	}
	return false;
}


void NameDB::addNewName(string_view name)
{
	mNames[name.data()] = 1;
}



int NameDB::getNameRank(string_view name) const
{
	int num = getAbsoluteNumber(name);

	if (num == -1)
		return false;

	int rank = 1;

	//일단은 1위라고 지정
	// 그리고 현재 갯수보다 더 많은 갯수의 이름 발견시 rank를 줄여 나간다
	// ex 1 >2 > 3 4......~n까지
	for (auto& i : mNames)
	{
		if (i.second > num)
			rank++;
	}

	return rank;


}


int NameDB::getAbsoluteNumber(string_view name) const
{
	auto res = mNames.find(name.data());
	if (res != end(mNames))
	{
		return res->second;
	}
	return -1;
	// 이름이 존재하지 않을시 -1 return
}