#include "MacroCommand.h"

#include <algorithm>


MacroCommand::MacroCommand(const std::vector<std::shared_ptr<Command>>& commands)
	:commands(commands)
{

}

void MacroCommand::execute()
{
	for (auto& it : commands)
		it->execute();
}

void MacroCommand::undo()
{
	std::for_each(commands.rbegin(), commands.rend(), [](auto& command) {command->undo(); });
}