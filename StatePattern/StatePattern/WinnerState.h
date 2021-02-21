#pragma once

#include "State.h"
#include "GumBallMachine.h"

class WinnerState : public State
{
private:
	GumballMachine* gum;

public:
	explicit WinnerState(GumballMachine* gum_);

	void insert_coin() const;
	void eject_coin() const;
	void dispense();
	void turn_crank() const;
	string toString() const;

};