#include "CeilingFan.h"
#include <iostream>

CeilingFan::CeilingFan(const std::string& location)
	:location(location)
{

}

CeilingFan::Speed CeilingFan::getSpeed() const
{
	return speed;
}

void CeilingFan::setSpeed(Speed speed)
{
	this->speed = speed;
	std::cout << getDescription() << std::endl;
}

std::string CeilingFan::getDescription() const
{
	std::string state;

	switch (speed)
	{
	case Speed::off:
		state = "off";
		break;
	case Speed::low:
		state = "low";
		break;
	case Speed::medium:
		state = "medium";
		break;
	case Speed::high:
		state = "high";
		break;
	case Speed::invalid:
		state = "INVALID";
		break;
	}
	return location + " Ceiling Fan speed is " + state;
}
