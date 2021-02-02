#pragma once
#include "CeilingFan.h"
#include "Command.h"
#include <memory>

class CeilingFanCommand : public Command
{
public:
	CeilingFanCommand(const std::shared_ptr<CeilingFan>& fan, CeilingFan::Speed speed);

	void execute() override;

	void undo() override;



private:
	std::shared_ptr<CeilingFan> fan;
	CeilingFan::Speed newSpeed;

	CeilingFan::Speed prev;
};