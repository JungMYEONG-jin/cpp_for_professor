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
	cout << "������ �����̶� ������ ���� �� �����ϴ�." << endl;
}

void SoldOutState::eject_coin() const
{
	cout << "��ȯ�� �Ұ����մϴ�. ������ ���� �����̽��ϴ�." << endl;
}

void SoldOutState::turn_crank() const
{
	cout << "������ �����Դϴ�. �����̸� ������ �ҿ�����ϴ�." << endl;
}

void SoldOutState::dispense()
{
	cout << "������ �����Դϴ�." << endl;
}

string SoldOutState::toString() const
{
	return "�����Դϴ�.";
}