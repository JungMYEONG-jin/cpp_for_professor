#include "CeilingFanCommand.h"


CeilingFanCommand::CeilingFanCommand(const std::shared_ptr<CeilingFan>& fan, CeilingFan::Speed speed)
	:fan(fan), newSpeed(speed), prev(CeilingFan::Speed::invalid)
{

}

void CeilingFanCommand::execute()
{
	prev = fan->getSpeed();
	fan->setSpeed(newSpeed);

}


void CeilingFanCommand::undo()
{
	if (prev == CeilingFan::Speed::invalid)
		return;
	fan->setSpeed(prev);
}