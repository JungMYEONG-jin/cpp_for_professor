#include <string>
#include <iostream>
#include <vector>

using namespace std;


// 도우 클래스

class Dough
{
public:
	string getDoughStyle()
	{
		return doughStyle;
	}
protected:
	string doughStyle;
};

class ThinCrustDough : public Dough
{
public:
	ThinCrustDough()
	{
		doughStyle = "얇은 도우";
	}
};

class ThickCrustDough : public Dough
{
public:
	ThickCrustDough()
	{
		doughStyle = "두꺼운 도우";
	}
};


//소스 클래스

class Sauce
{
public:
	string getSauce()
	{
		return sauce;
	}
protected:
	string sauce;
};

class TomatoSacue : public Sauce
{
public:
	TomatoSacue()
	{
		sauce = "토마토 소스";
	}
};

class MarinareSauce : public Sauce
{
public:
	MarinareSauce()
	{
		sauce = "마리내어 소스";
	}
};

// 치즈
class Cheese
{
public:
	string getCheese()
	{
		return cheese;
	}
protected:
	string cheese;
};

class MozzaCheese : public Cheese
{
public:
	MozzaCheese()
	{
		cheese = "모짜렐라 치즈";
	}
};

class ReggianoCheese : public Cheese
{
public:
	ReggianoCheese()
	{
		cheese = "레기아노 치즈";
	}
};

//조개

class Clam
{
public:
	string getClam()
	{
		return clam;
	}
protected:
	string clam;
};


class FreshClam : public Clam
{
public:
	FreshClam()
	{
		clam = "신선한 조개";
	}
};


class FrozenClam : public Clam
{
public:
	FrozenClam()
	{
		clam = "냉동 조개";
	}
};

// 야채

class Veggies
{
public:
	string getVeggie()
	{
		return veggie;
	}
protected:
	string veggie;
};

class Garlic : public Veggies
{
public:
	Garlic()
	{
		veggie = "마늘";
	}
};

class Onion : public Veggies
{
public:
	Onion()
	{
		veggie = "양파";
	}
};

class Mushroom : public Veggies
{
public:
	Mushroom()
	{
		veggie = "버섯";
	}
};

class Pepperoni
{
public:
	string getPepperoni()
	{
		return peppe;
	}
protected:
	string peppe;
};


class SlicedPepperoni : public Pepperoni
{
public:
	SlicedPepperoni()
	{
		peppe = "슬라이스 페페로니";
	}
};







class PizzaIngredient
{
public:
	virtual Dough* createDough() = 0;
	virtual Sauce* createSauce() = 0;
	virtual Cheese* createCheese() = 0;
	virtual vector<Veggies*> createVeggies() = 0;
	virtual Clam* createClam() = 0;
	virtual Pepperoni* createPepperoni() = 0;
};


class NYPizzaIngredient : public PizzaIngredient
{
public:
	Dough* createDough()
	{
		return new ThinCrustDough();
	}

	Sauce* createSauce()
	{
		return new TomatoSacue();
	}

	Cheese* createCheese()
	{
		return new ReggianoCheese();
	}

	vector<Veggies*> createVeggies()
	{
		vector<Veggies*> veg{ new Garlic(), new Onion(), new Mushroom() };
		return veg;
	}

	Pepperoni* createPepperoni()
	{
		return new SlicedPepperoni();
	}

	Clam* createClam()
	{
		return new FreshClam();
	}
};


class ChicagoPizzaIngredient : public PizzaIngredient
{
public:
	Dough* createDough()
	{
		return new ThickCrustDough();
	}

	Sauce* createSauce()
	{
		return new MarinareSauce();
	}

	Cheese* createCheese()
	{
		return new MozzaCheese();
	}

	vector<Veggies*> createVeggies()
	{
		vector<Veggies*> veg{ new Garlic(), new Onion(), new Mushroom() };
		return veg;
	}

	Pepperoni* createPepperoni()
	{
		return new SlicedPepperoni();
	}

	Clam* createClam()
	{
		return new FrozenClam();
	}
};













class Pizza
{
public:
	
	virtual void prepare() = 0;

	void bake()
	{
		cout << "350도에서 약 25분간 굽는중입니다." << endl;
	}

	virtual void cut()
	{
		cout << "피자를 8조각으로 자릅니다." << endl;
	}

	void box()
	{
		cout << "피자를 박스에 포장합니다." << endl;
	}

	void setName(string name)
	{
		this->name = name;
	}


	string getName()
	{
		return name;
	}

protected:
	string name;
	Dough* dough;
	Sauce* sauce;
	vector<Veggies*> veg;
	Cheese* cheese;
	Pepperoni* peppe;
	Clam* clam;

};



class CheesePizza : public Pizza
{

public:
	CheesePizza(PizzaIngredient* ingredient)
	{
		this->ingredient = ingredient;
	}
	void prepare()
	{
		cout << "Preparing " << name << endl;
		dough = ingredient->createDough();
		sauce = ingredient->createSauce();
		cheese = ingredient->createCheese();
	}
private:
	PizzaIngredient* ingredient;


};



class ClamPizza : public Pizza
{

public:
	ClamPizza(PizzaIngredient* ingredient)
	{
		this->ingredient = ingredient;
	}
	void prepare()
	{
		cout << "Preparing " << name << endl;
		dough = ingredient->createDough();
		sauce = ingredient->createSauce();
		cheese = ingredient->createCheese();
		clam = ingredient->createClam();
	}
private:
	PizzaIngredient* ingredient;

};






/*
class SimplePizzaFactory
{
public :

	Pizza* createPizza(string type)
	{
		Pizza *pizza = nullptr;

		if (type == "cheese")
			pizza = new CheesePizza();
		else if (type == "pepperoni")
			pizza = new PepperoniPizza();
		else if (type == "clam")
			pizza = new ClamPizza();
		else if (type == "veggie")
			pizza = new VeggiePizza();

		return pizza;
	}



};

*/










class PizzaStore {

public:
	
	Pizza* orderPizza(string type)
	{
		Pizza* pizza;

		pizza = createPizza(type);
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}
protected:

	virtual Pizza* createPizza(string type) = 0;

};


class NYPizzaStore : public PizzaStore
{
protected:
	Pizza* createPizza(string type)
	{
		Pizza* pizza = nullptr;
		PizzaIngredient* ingredient = new NYPizzaIngredient();

		if (type == "cheese")
		{
			pizza = new CheesePizza(ingredient);
			pizza->setName("뉴욕 스타일 치즈 피자");
		}
		else if (type == "clam")
		{
			pizza = new ClamPizza(ingredient);
			pizza->setName("뉴욕 스타일 조개 피자");
		}
		return pizza;
	}
};


class ChicagoPizzaStore : public PizzaStore
{
protected:
	Pizza* createPizza(string type)
	{
		Pizza* pizza = nullptr;
		PizzaIngredient* ingredient = new ChicagoPizzaIngredient();

		if (type == "cheese")
		{
			pizza = new CheesePizza(ingredient);
			pizza->setName("시카고 스타일 모짜렐라 치즈 피자");
		}
		else if (type == "clam")
		{
			pizza = new ClamPizza(ingredient);
			pizza->setName("시카고 스타일 냉동 조개 피자");
		}
		return pizza;
	}
};



int main()
{
	PizzaStore* nyStore = new NYPizzaStore();
	PizzaStore* chiStore = new ChicagoPizzaStore();

	Pizza* pizza = nyStore->orderPizza("cheese");
	cout << "명진이는 피자를 주문했다. " << pizza->getName() << endl;

	Pizza* pizza2 = nyStore->orderPizza("clam");
	cout << "명진이는 피자를 주문했다. " << pizza2->getName() << endl;


	pizza = chiStore->orderPizza("cheese");
	cout << "엠제이는 피자를 주문했다. " << pizza->getName() << endl;

	pizza = chiStore->orderPizza("clam");
	cout << "엠제이는 피자를 주문했다. " << pizza->getName() << endl;
}
