#include "GarageDoorOpenCommand.h"


GarageDoorOpenCommand::GarageDoorOpenCommand(const std::shared_ptr<GarageDoor>& gar)
	:gar(gar)
{

}

void GarageDoorOpenCommand::execute()
{
	gar->up();
}

void GarageDoorOpenCommand::undo()
{
	gar->down();
}