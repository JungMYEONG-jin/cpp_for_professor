#include "GumBallMachine.h"
#include "State.h"
#include <sstream>
#include <iostream>

GumballMachine::~GumballMachine()
{
	delete sold;
	delete sold_out;
	delete has_coin;
	delete no_coin;
	delete winner;
}

void GumballMachine::insert_coin() const
{
	m_state->insert_coin();
}

void GumballMachine::eject_coin() const
{
	m_state->eject_coin();
}

void GumballMachine::turn_crank() const
{
	m_state->turn_crank();
	m_state->dispense();
}

void GumballMachine::setState(State* state)
{
	this->m_state = state;
}

int GumballMachine::getCount() const
{
	return number;
}

void GumballMachine::refill(int num)
{
	number = num;
	m_state = no_coin;
}

void GumballMachine::releaseBall()
{
	cout << "���� �ϳ��� ���ɴϴ�." << endl;
	if (number != 0)
		number--;

}

State* GumballMachine::getNoCoinState() const
{
	return no_coin;
}

State* GumballMachine::getSoldOutState() const
{
	return sold_out;
}

State* GumballMachine::getSoldState() const
{
	return sold;
}

State* GumballMachine::getHasCoinState() const
{
	return has_coin;
}

State* GumballMachine::getWinnerState() const
{
	return winner;
}

string GumballMachine::toString() const
{
	stringstream sstr;
	sstr << endl << "C++ Standing ���� �̱� ��� #2021";
	sstr << endl << "���: " << number << "��";
	
	sstr << endl;
	sstr << "Current Machine State is " << m_state->toString() << endl;
	return sstr.str();
}