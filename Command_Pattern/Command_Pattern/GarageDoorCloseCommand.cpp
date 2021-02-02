#include "GarageDoorCloseCommand.h"


GarageDoorCloseCommand::GarageDoorCloseCommand(const std::shared_ptr<GarageDoor>& gar)
	:gar(gar)
{

}


void GarageDoorCloseCommand::execute()
{
	gar->down();
}

void GarageDoorCloseCommand::undo()
{
	gar->up();
}