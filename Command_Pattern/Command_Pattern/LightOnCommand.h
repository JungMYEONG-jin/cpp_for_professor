#pragma once

#include "LightDimCommand.h"

class LightOnCommand : public LightDimCommand
{
public:
	LightOnCommand(const std::shared_ptr<Light>& light)
		:LightDimCommand(light, 100)
	{

	}
};