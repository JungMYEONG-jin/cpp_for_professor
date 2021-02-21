#include "WinnerState.h"
#include "GumBallMachine.h"
#include <iostream>

WinnerState::WinnerState(GumballMachine* gum_)
	:gum(gum_)
{

}

void WinnerState::insert_coin() const
{
	cout << "��ٷ��ּ���. �̹� ������ �������ֽ��ϴ�." << endl;
}

void WinnerState::eject_coin() const
{
	cout << "��ٷ��ּ���. �̹� ������ �������ֽ��ϴ�." << endl;
}

void WinnerState::turn_crank() const
{
	cout << "������ ���������Դϴ�. �����̸� ������ �ҿ�����ϴ�." << endl;
}

void WinnerState::dispense()
{
	cout << "����� ��÷ �̺�Ʈ�� ��÷�Ǿ����ϴ�. �߰� ��ǰ�� �ϳ� �� ���޵˴ϴ�." << endl;

	gum->releaseBall();
	if (gum->getCount() == 0)
	{
		gum->setState(gum->getSoldOutState());
	}
	else
	{
		gum->releaseBall();
		if (gum->getCount() > 0)
			gum->setState(gum->getNoCoinState());
		else
		{
			cout << "������ �����Դϴ�." << endl;
			gum->setState(gum->getSoldOutState());
		}
	}
}

string WinnerState::toString() const
{
	return "���� 2���� ���޵˴ϴ�. ��÷�� ���ϵ����.^^";
}