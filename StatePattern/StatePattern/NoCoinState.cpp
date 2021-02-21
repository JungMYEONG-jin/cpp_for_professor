#include <iostream>
#include "GumBallMachine.h"
#include "No_Coin_State.h"

using namespace std;

NoCoinState::NoCoinState(GumballMachine* gum_)
	:gum(gum_)
{

}

void NoCoinState::insert_coin() const
{
	cout << "동전을 넣었습니다." << endl;
	gum->setState(gum->getHasCoinState());
}

void NoCoinState::eject_coin() const
{
	cout << "동전을 입력하지 않았습니다." << endl;
}

void NoCoinState::turn_crank() const
{
	cout << "손잡이를 돌렸습니다. 하지만 당신은 동전을 입력하지 않았습니다." << endl;
}

void NoCoinState::dispense()
{
	cout << "동전을 먼저 입력해주세요." << endl;
}

string NoCoinState::toString() const
{
	return "잠시만 기다려주세요.";
}