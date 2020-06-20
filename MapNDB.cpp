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
// DB�� �̸��� �ִٸ� true return �׷��� �ʴٸ� false return
// �̸� �߽߰� ���� ����
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

	//�ϴ��� 1����� ����
	// �׸��� ���� �������� �� ���� ������ �̸� �߽߰� rank�� �ٿ� ������
	// ex 1 >2 > 3 4......~n����
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
	// �̸��� �������� ������ -1 return
}