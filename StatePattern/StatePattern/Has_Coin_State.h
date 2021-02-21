#pragma once

#include "State.h"
#include "GumBallMachine.h"

class HasCoinState : public State
{
private:

	GumballMachine* gum;
	int ran;
public:
	explicit HasCoinState(GumballMachine* _gum);

	
	void insert_coin() const;
	void eject_coin() const;
	void dispense();
	void turn_crank() const;
	string toString() const;

};