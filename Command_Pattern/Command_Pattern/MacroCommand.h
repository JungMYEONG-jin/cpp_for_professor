#pragma once

#include "Command.h"
#include <vector>
#include <memory>
class MacroCommand : public Command
{
public:
	MacroCommand(const std::vector<std::shared_ptr<Command>>& commands);

	void execute() override;

	void undo() override;

private:
	std::vector<std::shared_ptr<Command>> commands;
};