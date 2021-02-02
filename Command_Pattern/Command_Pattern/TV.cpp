#include "TV.h"


#include <iostream>

TV::TV(const std::string& location) :
    location(location) {
}

void TV::on() {
    std::cout << location << " TV is on." << std::endl;
}

void TV::off() {
    std::cout << location << " TV is off." << std::endl;
}