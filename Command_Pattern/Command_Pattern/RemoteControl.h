#pragma once

#include "Command.h"
#include <vector>
#include <string>
#include <memory>
class RemoteControl
{
public:

	RemoteControl();

	void setCommand(std::size_t slot, std::shared_ptr<Command> onCommand, std::shared_ptr<Command> offCommand);

	void onButton(std::size_t slot);

	void offButton(std::size_t slot);

	void undoButton();

	std::string toString() const;

private:
	std::vector<std::shared_ptr<Command>> onCommands;
	std::vector<std::shared_ptr<Command>> offCommands;
	std::shared_ptr<Command> undoCommand;

	friend std::ostream& operator<<(std::ostream& os, const RemoteControl& remote);

};

std::ostream& operator<<(std::ostream& os, const RemoteControl& remote);