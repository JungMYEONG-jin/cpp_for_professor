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
	cout << "������ ��ȯ�մϴ�." << endl;
	gum->setState(gum->getNoCoinState());
}

void HasCoinState::turn_crank() const
{
	cout << "�����̸� �����ϴ�. ����� ������ ���ɴϴ�." << endl;

	int winner = rand() % 5;
	if ((winner == 0) && (gum->getCount() > 0))
		gum->setState(gum->getWinnerState());
	else
		gum->setState(gum->getSoldState());
}

void HasCoinState::insert_coin() const
{
	cout << "������ 1���� ���� �� �ֽ��ϴ�. �̹� ������ �ԷµǾ� �ֽ��ϴ�." << endl;
}

void HasCoinState::dispense()
{
	cout << "������ ������ �ʽ��ϴ�." << endl;
}

string HasCoinState::toString() const
{
	return "�����̰� ���ư��µ��� ��ٷ��ּ���.";
}