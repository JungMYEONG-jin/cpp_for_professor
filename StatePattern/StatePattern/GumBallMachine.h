#pragma once

#include "State.h"

class GumballMachine
{
private:
	State* sold;
	State* sold_out;
	State* has_coin;
	State* no_coin;
	State* winner;
	State* m_state;
	int number;

public:
	explicit GumballMachine(int number_);
	~GumballMachine();

	void insert_coin() const;
	void eject_coin() const;
	void turn_crank() const;
	void setState(State* state);
	void releaseBall();
	int getCount() const;
	void refill(int number_);


	State* getState() const;
	State* getSoldOutState() const;
	State* getSoldState() const;
	State* getHasCoinState() const;
	State* getNoCoinState() const;
	State* getWinnerState() const;









	string toString() const;


};