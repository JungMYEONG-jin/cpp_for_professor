#include "Light.h"
#include <iostream>

Light::Light(const std::string& location)
{
	this->location = location;
	level = 0;
}

void Light::on()
{
	dimmedLevel(100);
}

void Light::off()
{
	dimmedLevel(0);
}

const int Light::invalidDimmedLevel = -1;

void Light::dimmedLevel(int level)
{
	if (level < 0 || level>100)
		return;

	this->level = level;

	switch (level)
	{
	case 0:
		std::cout << location << " Light is off."  << std::endl;
		break;
	case 100:
		std::cout << location << " Light is on." <<  std::endl;
		break;
	default:
		std::cout << location << " Light is dimmed to " << level << "%" << std::endl;
		break;
	}
}


int Light::getLevel()
{
	return level;
}