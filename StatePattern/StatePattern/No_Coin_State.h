#pragma once
#include "State.h"
#include "GumBallMachine.h"

class NoCoinState : public State
{
private:

	GumballMachine* gum;

public:
	explicit NoCoinState(GumballMachine* _gum);

	
	void insert_coin() const;
	void eject_coin() const;
	void dispense();
	void turn_crank() const;
	string toString() const;
};