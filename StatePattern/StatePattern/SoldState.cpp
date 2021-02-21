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
	cout << "������ �̹� ���������Դϴ�. ��ٷ��ּ���." << endl;
}

void SoldState::eject_coin() const
{
	cout << "�˼��մϴ�. �̹� �����̸� ���� ��ȯ�� �Ұ����մϴ�." << endl;
}

void SoldState::turn_crank() const
{
	cout << "�̹� ������ ���������Դϴ�. �����̸� ������ �����ּ���." << endl;
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
		cout << "������ ǰ���Դϴ�." << endl;
		gum->setState(gum->getSoldOutState());
	}
}

string SoldState::toString() const
{
	return "������ ���ɴϴ�.";
}