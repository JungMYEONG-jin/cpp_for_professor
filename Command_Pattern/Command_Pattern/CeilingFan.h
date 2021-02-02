#pragma once


#include <string>

class CeilingFan
{
public:
	CeilingFan(const std::string& location);

	enum class Speed{off, low, medium, high, invalid};

	Speed getSpeed() const;

	void setSpeed(Speed speed);

	std::string getDescription() const;


private:
	std::string location;
	Speed speed;
};