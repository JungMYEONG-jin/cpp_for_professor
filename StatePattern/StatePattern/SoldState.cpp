#include <iostream>
#include "Sold_State.h"
#include "GumBallMachine.h"


using namespace std;

SoldState::SoldState(GumballMachine* gum_)
	:gum(gum_)
{

}

void SoldState::insert_coin() const
{
	cout << "물건이 이미 나오는중입니다. 기다려주세요." << endl;
}

void SoldState::eject_coin() const
{
	cout << "죄송합니다. 이미 손잡이를 돌려 반환이 불가능합니다." << endl;
}

void SoldState::turn_crank() const
{
	cout << "이미 물건이 나오는중입니다. 손잡이를 돌리지 말아주세요." << endl;
}

void SoldState::dispense()
{
	gum->releaseBall();
	if (gum->getCount() > 0)
	{
		gum->setState(gum->getNoCoinState());
	}
	else
	{
		cout << "물건이 품절입니다." << endl;
		gum->setState(gum->getSoldOutState());
	}
}

string SoldState::toString() const
{
	return "물건이 나옵니다.";
}