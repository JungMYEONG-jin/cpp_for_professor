#pragma once

#include "LightDimCommand.h"

class LightOffCommand : public LightDimCommand
{
public:

	LightOffCommand(const std::shared_ptr<Light>& light)
		:LightDimCommand(light, 0)
	{

	}
};