#include "GumBallMachine.h"
#include "Has_Coin_State.h"
#include <iostream>

using namespace std;


HasCoinState::HasCoinState(GumballMachine* gum_)
	:gum(gum_), ran(0)
{

}

void HasCoinState::eject_coin() const
{
	cout << "동전을 반환합니다." << endl;
	gum->setState(gum->getNoCoinState());
}

void HasCoinState::turn_crank() const
{
	cout << "손잡이를 돌립니다. 잠시후 물건이 나옵니다." << endl;

	int winner = rand() % 5;
	if ((winner == 0) && (gum->getCount() > 0))
		gum->setState(gum->getWinnerState());
	else
		gum->setState(gum->getSoldState());
}

void HasCoinState::insert_coin() const
{
	cout << "동전은 1개만 넣을 수 있습니다. 이미 동전이 입력되어 있습니다." << endl;
}

void HasCoinState::dispense()
{
	cout << "물건이 나가지 않습니다." << endl;
}

string HasCoinState::toString() const
{
	return "손잡이가 돌아가는동안 기다려주세요.";
}