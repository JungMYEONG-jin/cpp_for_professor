#include "Hottub.h"
#include <iostream>

Hottub::Hottub(const std::string& location)
	:location(location)
{

}

void Hottub::on()
{
	std::cout << location << " Hottub is on" << std::endl;
}

void Hottub::off()
{
	std::cout << location << " Hottub is off" << std::endl;
}