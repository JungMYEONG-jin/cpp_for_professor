#pragma once

#include <string>

class GarageDoor
{
public:

	GarageDoor(const std::string& location);

	void up();

	void down();

private:
	std::string location;
};