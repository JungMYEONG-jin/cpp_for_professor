#pragma once
#include <string>

class Light
{
public:
	Light(const std::string& location);

	void on();
	
	void off();

	static const int invalidDimmedLevel;


	void dimmedLevel(int level);

	int getLevel();

private:
	std::string location;
	int level;
};