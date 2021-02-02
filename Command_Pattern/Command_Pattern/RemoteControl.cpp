#include "RemoteControl.h"
#include "NoCommand.h"

#include <sstream>

RemoteControl::RemoteControl()
{
	auto noCommand = std::make_shared<NoCommand>();
	onCommands = std::vector<std::shared_ptr<Command>>(7);
	offCommands = std::vector<std::shared_ptr<Command>>(7);
	undoCommand = nullptr;
}



void RemoteControl::setCommand(std::size_t slot, std::shared_ptr<Command> onCommand, std::shared_ptr<Command> offCommand)
{
	onCommands[slot] = onCommand;
	offCommands[slot] = offCommand;
}


void RemoteControl::onButton(std::size_t slot)
{
	onCommands[slot]->execute();
	undoCommand = onCommands[slot];
}

void RemoteControl::offButton(std::size_t slot)
{
	offCommands[slot]->execute();
	undoCommand = offCommands[slot];
}

void RemoteControl::undoButton()
{
	undoCommand->undo();
}

std::ostream& operator<<(std::ostream& os, const RemoteControl& remote)
{

	os << "\n-------- Remote Control --------\n";
	for (int idx = 0; idx < remote.onCommands.size(); idx++)
	{
		auto onCommand = remote.onCommands[idx];
		auto offCommand = remote.offCommands[idx];
		os << "[slot " << idx << "] " << onCommand << "   " << offCommand << std::endl;
	}
	os << "[undo] " << remote.undoCommand << std::endl;

	return os;
}