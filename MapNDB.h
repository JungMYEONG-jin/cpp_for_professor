#pragma once


#include <string_view>
#include <string>
#include <map>



class NameDB
{
public:


	NameDB(std::string_view fileName);


	int getNameRank(std::string_view name) const;

	int getAbsoluteNumber(std::string_view name) const;


private:
	std::map<std::string, int> mNames;

	bool nameExistsAndIncrement(std::string_view name);
	void addNewName(std::string_view name);
};