#pragma once

#include <string>

using namespace std;

class State
{
public:
	//virtual ~State();
	virtual void insert_coin() const = 0;
	virtual void eject_coin() const = 0;
	virtual void turn_crank() const = 0;
	virtual void dispense() = 0;
	virtual string toString() const = 0;
};