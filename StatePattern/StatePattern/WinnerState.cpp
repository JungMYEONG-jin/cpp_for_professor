#include "WinnerState.h"
#include "GumBallMachine.h"
#include <iostream>

WinnerState::WinnerState(GumballMachine* gum_)
	:gum(gum_)
{

}

void WinnerState::insert_coin() const
{
	cout << "기다려주세요. 이미 물건이 나오고있습니다." << endl;
}

void WinnerState::eject_coin() const
{
	cout << "기다려주세요. 이미 물건이 나오고있습니다." << endl;
}

void WinnerState::turn_crank() const
{
	cout << "물건이 나오는중입니다. 손잡이를 돌려도 소용없습니다." << endl;
}

void WinnerState::dispense()
{
	cout << "당신은 추첨 이벤트에 당첨되었습니다. 추가 상품이 하나 더 지급됩니다." << endl;

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
			cout << "물건이 매진입니다." << endl;
			gum->setState(gum->getSoldOutState());
		}
	}
}

string WinnerState::toString() const
{
	return "물건 2개가 지급됩니다. 당첨을 축하드려요.^^";
}