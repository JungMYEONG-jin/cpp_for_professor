#include "GumBallMachine.h"
#include "Sold_out_State.h"
#include "Sold_State.h"
#include "WinnerState.h"
#include "Has_Coin_State.h"
#include "No_Coin_State.h"
#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

GumballMachine::GumballMachine(int num)
	:number(num)
{
	sold = new SoldState(this);
	sold_out = new SoldOutState(this);
	has_coin = new HasCoinState(this);
	no_coin = new NoCoinState(this);
	winner = new WinnerState(this);

	m_state = sold_out;

	if (number > 0)
		m_state = no_coin;
}

int main()
{
	unique_ptr<GumballMachine> gumball(new GumballMachine(5));
	cout << gumball->toString() << endl;

	gumball->insert_coin();
	gumball->turn_crank();
	gumball->insert_coin();
	gumball->turn_crank();
	
	cout << gumball->toString() << endl;

	gumball->insert_coin();
	gumball->insert_coin();
	gumball->eject_coin();

	cout << gumball->toString() << endl;
// check 품절 테스트
	gumball->insert_coin();
	gumball->turn_crank();
	gumball->insert_coin();
	gumball->turn_crank();
	gumball->insert_coin();
	gumball->turn_crank();

	cout << gumball->toString() << endl; // 품절 메시지 확인

	gumball->refill(5); // refill 확인

	cout << gumball->toString() << endl;

	gumball->insert_coin();
	gumball->turn_crank();

	cout << gumball->toString() << endl;
}