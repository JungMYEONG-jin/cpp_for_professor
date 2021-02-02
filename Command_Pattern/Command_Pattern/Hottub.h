#pragma once
#include <string>

class Hottub
{
public:
	Hottub(const std::string& location);

	void on();

	void off();

private:
	std::string location;
};