#include <iostream>
#include <memory>

#include "RemoteControl.h"
#include "Light.h"
#include "LightOnCommand.h"
#include "LightOffCommand.h"
#include "CeilingFan.h"
#include "CeilingFanCommand.h"
/*
#include "TV.hpp"
#include "TVOnCommand.hpp"
#include "TVOffCommand.hpp"
#include "Stereo.hpp"
#include "StereoOnWithCDCommand.hpp"
#include "StereoOffCommand.hpp"
*/
#include "HotTub.h"
#include "HotTubOnCommand.h"
#include "HotTubOffCommand.h"
#include "MacroCommand.h"

int main(int argc, const char* argv[]) {
    RemoteControl remoteControl;
    auto livingRoomLight = std::make_shared<Light>("Living Room");
    auto livingRoomLightOn = std::make_shared<LightOnCommand>(livingRoomLight);
    auto livingRoomLightOff = std::make_shared<LightOffCommand>(livingRoomLight);

    remoteControl.setCommand(0, livingRoomLightOn, livingRoomLightOff);

    remoteControl.onButton(0);
    remoteControl.offButton(0);
    std::cout << remoteControl;
    remoteControl.undoButton();
    remoteControl.offButton(0);
    remoteControl.onButton(0);
    std::cout << remoteControl;
    remoteControl.undoButton();

    auto ceilingFan = std::make_shared<CeilingFan>("Living Room");

    auto ceilingFanMedium = std::make_shared<CeilingFanCommand>(ceilingFan, CeilingFan::Speed::medium);
    auto ceilingFanHigh = std::make_shared<CeilingFanCommand>(ceilingFan, CeilingFan::Speed::high);
    auto ceilingFanOff = std::make_shared<CeilingFanCommand>(ceilingFan, CeilingFan::Speed::off);

    remoteControl.setCommand(0, ceilingFanMedium, ceilingFanOff);
    remoteControl.setCommand(1, ceilingFanHigh, ceilingFanOff);

    remoteControl.onButton(0);
    remoteControl.offButton(0);
    std::cout << remoteControl;
    remoteControl.undoButton();

    remoteControl.onButton(1);
    std::cout << remoteControl;
    remoteControl.undoButton();

    //: The following demonstrates the use of the macro command with undo.

  

    return 0;
}