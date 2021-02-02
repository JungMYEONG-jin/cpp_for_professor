#pragma once

#include "Command.h"

class NoCommand : public Command
{
public:

	void execute() override {}

	void undo() override {}
};