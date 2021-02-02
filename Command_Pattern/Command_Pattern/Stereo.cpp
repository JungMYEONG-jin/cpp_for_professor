#include "Stereo.h"

#include <iostream>

Stereo::Stereo(const std::string& location) :
    location(location) {
}

void Stereo::on() {
    std::cout << location << " Stereo is on" << std::endl;
}

void Stereo::off() {
    std::cout << location << " Stereo is off" << std::endl;
}

void Stereo::setCD() {
    std::cout << location << " Stereo is set to CD" << std::endl;
}

void Stereo::setDVD() {
    std::cout << location << " Stereo is set to DVD" << std::endl;

}

void Stereo::setRadio() {
    std::cout << location << " Stereo is set to Radio" << std::endl;

}

void Stereo::setVolume(int volume) {
    // code to set the volume
    // valid range: 1-11 (after all 11 is better than 10, right?)
    std::cout << location << " Stereo volume set to " << volume << std::endl;
}