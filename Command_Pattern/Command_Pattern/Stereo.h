#pragma once

#include <string>

class Stereo {
public:
    Stereo(const std::string& location);

    void on();

    void off();

    void setCD();

    void setDVD();

    void setRadio();

    void setVolume(int volume);

private:
    std::string location;

};