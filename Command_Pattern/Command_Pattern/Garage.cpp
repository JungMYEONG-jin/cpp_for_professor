#include <iostream>
#include "Garage.h"


GarageDoor::GarageDoor(const std::string& location)
	:location(location)
{

}

void GarageDoor::up()
{
	std::cout << location << " Garage Door is opened" << std::endl;
}


void GarageDoor::down()
{
	std::cout << location << " Garage Door is closed" << std::endl;
}