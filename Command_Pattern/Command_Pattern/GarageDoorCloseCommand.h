#pragma once

#include "Command.h"
#include "Garage.h"

#include <memory>
class GarageDoorCloseCommand : public Command
{

public:
	GarageDoorCloseCommand(const std::shared_ptr<GarageDoor>& gar);

	void execute() override;

	void undo() override;


private:
	std::shared_ptr<GarageDoor> gar;


};