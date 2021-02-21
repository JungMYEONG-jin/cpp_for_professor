#include "Sold_out_State.h"
#include "GumBallMachine.h"
#include <iostream>

using namespace std;

SoldOutState::SoldOutState(GumballMachine* gum_)
	:gum(gum_)
{

}

void SoldOutState::insert_coin() const
{
	cout << "물건이 매진이라 동전을 넣을 수 없습니다." << endl;
}

void SoldOutState::eject_coin() const
{
	cout << "반환이 불가능합니다. 동전을 넣지 않으셨습니다." << endl;
}

void SoldOutState::turn_crank() const
{
	cout << "물건이 매진입니다. 손잡이를 돌려도 소용없습니다." << endl;
}

void SoldOutState::dispense()
{
	cout << "물건이 매진입니다." << endl;
}

string SoldOutState::toString() const
{
	return "매진입니다.";
}