#include "LightDimCommand.h"


LightDimCommand::LightDimCommand(const std::shared_ptr<Light>& light, int level)
	:light(light), level(level), prev(Light::invalidDimmedLevel)
{

}

void LightDimCommand::execute()
{
	prev = light->getLevel();
	light->dimmedLevel(level);
}

void LightDimCommand::undo()
{
	if (prev == Light::invalidDimmedLevel)
		return;
	light->dimmedLevel(prev);
	// invalid level �� �ƴ϶�� ���� ���� ����
}