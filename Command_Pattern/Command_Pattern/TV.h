#pragma once

#include <string>

class TV {
public:
    TV(const std::string& location);

    void on();

    void off();

private:
    std::string location;
};