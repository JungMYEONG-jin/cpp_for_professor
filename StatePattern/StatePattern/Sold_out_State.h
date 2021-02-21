#pragma once

#include "State.h"
#include "GumBallMachine.h"

class SoldOutState : public State
{
private:

	GumballMachine* gum;

public:
	explicit SoldOutState(GumballMachine* _gum);

	
	void insert_coin() const;
	void eject_coin() const;
	void dispense();
	void turn_crank() const;
	string toString() const;
};