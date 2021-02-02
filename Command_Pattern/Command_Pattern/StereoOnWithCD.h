#pragma once

#include "Stereo.h"
#include "Command.h"
#include <memory>

class StereoOnWithCD : public Command
{
public:
	StereoOnWithCD(const std::shared_ptr<Stereo>& stereo);

	void execute() override;

	void undo() override;

private:
	std::shared_ptr<Stereo> stereo;
};