#pragma once

#include "Command.h"
#include <memory>
// �������� on off ��ü�� ����
// template meta programming���� ó��

template<typename Entity, bool isOn>
class OnOffCommand : public Command
{
	OnOffCommand(const std::shared_ptr<Entity>& _entity)
		:entity(_entity)
	{

	}

	void execute() override
	{
		isOn ? entity->on() : entity->off();
	}

	void undo() override
	{
		isOn ? entity->off() : entity->up();
	}
	
private:
	std::shared_ptr<Entity> entity;
};