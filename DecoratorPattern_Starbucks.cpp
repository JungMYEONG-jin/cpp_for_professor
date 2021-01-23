#include <iostream>
#include <string>
#include <assert.h>

using namespace std;


class Beverage
{
public:
	
	virtual string getDescription() = 0;
	
	virtual double cost() = 0;
	virtual void setSize(string sz) = 0;
	virtual string getSize() = 0;
protected:
	string bev_size;

}; //Component 클래스

// 데코레이터 클래스
class CondimentDecorator : public Beverage
{
	virtual string getDescription() = 0; // 모든 첨가물 데코레이터에서 각자 다른 설명을 나타내야해서 virtual로 선언
};

class Espresso : public Beverage
{

public:

	Espresso() { bev_size = "TALL"; }

	void setSize(string sz) override { bev_size = sz; }
	string getSize() override { return bev_size; }
	string getDescription() override
	{
		return "에스프레소";
	}

	double cost() override
	{
		return 1.99;
	}

};

class HouseBlend : public Beverage
{
	

public:

	HouseBlend() { bev_size = "TALL"; }

	void setSize(string sz) override { bev_size = sz; }
	string getSize() override { return bev_size; }


	string getDescription() override
	{
		return "하우스블렌디드 커피";
	}
	double cost() override
	{
		return 0.89;
	}

};

class DarkRoast : public Beverage
{
	

public:

	DarkRoast() { bev_size = "TALL"; }

	void setSize(string sz) override { bev_size = sz; }
	string getSize() override { return bev_size; }
	string getDescription() override
	{
		return "다크로스트 커피";
	}

	double cost() override
	{
		return 0.99;
	}

};

class Decaf : public Beverage
{
	
public:

	Decaf() { bev_size = "TALL"; }

	void setSize(string sz) override { bev_size = sz; }
	string getSize() override { return bev_size; }

	string getDescription() override
	{
		return "디카페인 커피";
	}

	double cost() override
	{
		return 1.05;
	}

};


// 데코레이터 클래스 서브 클래스를 만들자

class Mocha : public CondimentDecorator
{
public:
	Mocha(Beverage* beverage) { this->beverage = beverage; }

	string getSize() { return beverage->getSize(); }


	string getDescription()
	{
		return beverage->getDescription() + ", 모카";
	}
	void setSize(string k) { return beverage->setSize(k); }
	double cost() override
	{
		double cost = beverage->cost();
		if (getSize() == "TALL")
			cost += 0.10;
		else if (getSize() == "GRANDE")
			cost += 0.15;
		else if (getSize() == "VENTI")
			cost += 0.20;
		return cost;
	}


private:
	Beverage* beverage;
};

class Soy : public CondimentDecorator
{
public:
	Soy(Beverage* beverage) { this->beverage = beverage; }

	string getDescription()
	{
		return beverage->getDescription() + ", 두유";
	}

	string getSize() { return beverage->getSize(); }
	void setSize(string k) { return beverage->setSize(k); }
	double cost() override
	{
		double cost = beverage->cost();
		if (getSize() == "TALL")
			cost += 0.10;
		else if (getSize() == "GRANDE")
			cost += 0.15;
		else if (getSize() == "VENTI")
			cost += 0.20;
		return cost;
	}


private:
	Beverage* beverage;
};

class Whip : public CondimentDecorator
{
public:
	Whip(Beverage* beverage) { this->beverage = beverage; }

	string getDescription()
	{
		return beverage->getDescription() + ", 휘핑크림";
	}
	string getSize() { return beverage->getSize(); }
	void setSize(string k) { return beverage->setSize(k); }
	double cost() override
	{
		double cost = beverage->cost();
		if (getSize() == "TALL")
			cost += 0.10;
		else if (getSize() == "GRANDE")
			cost += 0.15;
		else if (getSize() == "VENTI")
			cost += 0.20;
		return cost;
	}


private:
	Beverage* beverage;
};

class SteamMilk : public CondimentDecorator
{
public:
	SteamMilk(Beverage* beverage) { this->beverage = beverage; }

	string getDescription()
	{
		return beverage->getDescription() + ", 스팀밀크";
	}
	void setSize(string k) { return beverage->setSize(k); }
	string getSize() { return beverage->getSize(); }

	double cost() override
	{
		double cost = beverage->cost();
		if (getSize() == "TALL")
			cost += 0.10;
		else if (getSize() == "GRANDE")
			cost += 0.15;
		else if (getSize() == "VENTI")
			cost += 0.20;
		return cost;
	}


private:
	Beverage* beverage;
};

int main()
{
	Beverage* beverage = new Espresso();
	assert(beverage->cost() == 1.99);
	
	cout << beverage->getDescription()<< " $" << beverage->cost() << endl;

	Beverage* bev2 = new Whip(new Mocha(new Mocha(new DarkRoast)));
	cout << bev2->getDescription() << " $" << bev2->cost() << endl;
	
	Beverage* bev3 = new Whip(new Mocha(new Soy(new HouseBlend)));
	bev3->setSize("VENTI"); // 각 첨가물당 0.2 센트가 추가됨 총 0.6센트 추가에 bouse blend 0.89센트
	assert(bev3->cost() == 1.49);
	cout << bev3->getDescription() << " $" << bev3->cost() << endl;
	

}
