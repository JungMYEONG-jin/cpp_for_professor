#pragma once
#include "Command.h"
#include "Light.h"
#include <memory>

class LightDimCommand : public Command
{
public:
	LightDimCommand(const std::shared_ptr<Light>& light, int level);
	void execute() override;

	void undo() override;


private:
	std::shared_ptr<Light> light;
	int level;
	int prev;
};