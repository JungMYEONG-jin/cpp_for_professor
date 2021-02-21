#pragma once

#include "GumBallMachine.h"
#include "State.h"

class SoldState : public State
{
private:

	GumballMachine* gum;

public:
	explicit SoldState(GumballMachine* _gum);

	
	void insert_coin() const;
	void eject_coin() const;
	void dispense();
	void turn_crank() const;
	string toString() const;
};