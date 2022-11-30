#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum class State{Sold_out, No_coin, Has_coin, Sold};


class GumballMachine
{
private:
	State m_state = State::Sold_out;
	int number = 0;
public:
	GumballMachine(int num)
	{
		this->number = num;
		this->m_state = State::No_coin;
	}

	void insert_coin()
	{
		if (m_state == State::No_coin)
		{
			m_state = State::Has_coin;
			cout << "동전이 입력되었습니다\n";
		}
		else if (m_state == State::Has_coin)
		{
			cout << "이미 동전이 들어갔습니다\n";
		}
		else if (m_state == State::Sold)
		{
			cout << "잠시 기다려주세요. 물건이 나가는중입니다.\n";
		}
		else if (m_state == State::Sold_out)
		{
			cout << "죄송합니다. 품절되었습니다.\n";
		}

	}

	void eject_coin()
	{
		if (m_state == State::No_coin)
		{
			cout << "입력된 동전이 없습니다.\n";
		}
		else if (m_state == State::Has_coin)
		{
			m_state = State::No_coin;
			cout << "동전을 반환합니다.\n";
		}
		else if (m_state == State::Sold)
		{
			cout << "물건이 나오는중입니다. 반환이 불가능합니다.\n";
		}
		else if (m_state == State::Sold_out)
		{
			cout << "동전을 넣지 않았습니다. 반환할 동전이 없습니다.\n";
		}
	}

	void turn_crank()
	{
		if (m_state == State::No_coin)
		{
			cout << "동전을 넣어주세요.\n";
		}
		else if (m_state == State::Has_coin)
		{
			m_state = State::Sold;
			cout << "손잡이를 돌렸습니다.\n";
			dispense();
		}
		else if (m_state == State::Sold)
		{
			cout << "이미 손잡이를 돌렸습니다. 한번만 돌려주세요.\n";
		}
		else if (m_state == State::Sold_out)
		{
			cout << "품절입니다.\n";
		}
	}

	void dispense() {
		if (m_state == State::Sold)
		{
			cout << "물건이 나오는중입니다.\n";
			number--;
			if (number > 0)
				m_state = State::No_coin;
			else if (number == 0)
			{
				cout << "이제 알맹이가 존재하지 않습니다.\n";
				m_state = State::Sold_out;
			}
		}
		else if (m_state == State::No_coin)
			cout << "동전을 넣어주세요.\n";
		else if (m_state == State::Has_coin)
			cout << "물건이 이미 나가는중입니다.\n";
		else if (m_state == State::Sold_out)
			cout << "물건이 품절입니다.\n";
	}

	string toString() const
	{
		stringstream sstr;
		sstr << endl << "C++enabled Standing Gumball Machine #2021";
		sstr << endl << "Inventory: " << number << " gumball";
		if (number > 1)
			sstr << "s";
		sstr << endl;
		return sstr.str();
	}



};

int main()
{
	unique_ptr<GumballMachine> gum(new GumballMachine(5));

	cout << gum->toString() << endl;

	gum->insert_coin();
	gum->turn_crank();
	gum->insert_coin();
	gum->turn_crank();

	cout << gum->toString() << endl;

	gum->insert_coin();
	gum->insert_coin();
	gum->eject_coin();
	
	cout << gum->toString() << endl;
	
}
