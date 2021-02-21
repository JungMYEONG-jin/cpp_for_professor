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
	cout << "������ �־����ϴ�." << endl;
	gum->setState(gum->getHasCoinState());
}

void NoCoinState::eject_coin() const
{
	cout << "������ �Է����� �ʾҽ��ϴ�." << endl;
}

void NoCoinState::turn_crank() const
{
	cout << "�����̸� ���Ƚ��ϴ�. ������ ����� ������ �Է����� �ʾҽ��ϴ�." << endl;
}

void NoCoinState::dispense()
{
	cout << "������ ���� �Է����ּ���." << endl;
}

string NoCoinState::toString() const
{
	return "��ø� ��ٷ��ּ���.";
}