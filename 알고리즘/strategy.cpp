#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

inline bool are_equal(double const d1, double const d2, double const diff = 0.001)
{
	return abs(d1 - d2) <= diff;
}
// 최종 가격 계산 method
struct discount_type
{
	virtual double discount_percent(double const price, double const quantity) const noexcept = 0;
	virtual ~discount_type() {}
};

struct fixed_discount final : public discount_type
{
	explicit fixed_discount(double const discount) noexcept : discount(discount) {}
	virtual double discount_percent(double const, double const) const noexcept { return discount; }

private:
	double discount;
};
struct volume_discount final : public discount_type
{
	explicit volume_discount(double const quantity, double const discount) noexcept
		:discount(discount), m_quantity(quantity)
	{}

	virtual double discount_percent(double const, double const quantity) const noexcept
	{
		return quantity >= m_quantity ? discount : 0;
	}
	// 개수가 최소조건 만족하면 할인

private:
	double discount;
	double m_quantity;
};

struct price_discount : public discount_type
{
	explicit price_discount(double const price, double const discount) noexcept
		:discount(discount), mtot_price(price)
	{}
	virtual double discount_percent(double const price, double const quantity) const noexcept
	{
		return price*quantity >= mtot_price ? discount : 0;
	}

private:
	double discount;
	double mtot_price; //min  total price
};

struct amount_discount : public discount_type
{
	explicit amount_discount(double const price, double const discount) noexcept
		:discount(discount), m_price(price)
	{}

	virtual double discount_percent(double const price, double const) const noexcept
	{
		return price >= m_price ? discount : 0;
	}


private:
	double discount;
	double m_price;  // min price
};

struct customer
{
	string name;
	discount_type* discount;
};

enum class article_unit
{
	piece, kg, meter, sqmeter, cmeter, liter
}; //단위


struct article
{
	int id;
	string name;
	double price;
	article_unit unit;
	discount_type* discount;
};

struct order_line
{
	article product;
	int quantity;
	discount_type* discount;
};

struct order
{
	int id;
	customer* buyer;
	vector<order_line> lines;
	discount_type* discount;
	
};


struct price_calculator
{
	virtual double calculate_price(order const& a) = 0;
};

struct cummulative_price_calculator : public price_calculator
{
	virtual double calculate_price(order const& a) override
	{
		double price = 0;

		for (auto ol : a.lines)
		{
			double line_price = ol.product.price * ol.quantity;

			if (ol.product.discount != nullptr)
			{
				line_price *= (1 - ol.product.discount->discount_percent(ol.product.price, ol.quantity));
			}

			if (ol.discount != nullptr)
			{
				line_price *= (1 - ol.discount->discount_percent(ol.product.price, ol.quantity));

			}
			if (a.buyer != nullptr && a.buyer->discount != nullptr)
			{
				line_price *= (1 - a.buyer->discount->discount_percent(ol.product.price, ol.quantity));
			}


			price += line_price;
		}

		if (a.discount != nullptr)
			price *= (1 - a.discount->discount_percent(price, 0));

		return price;

	}
};


int main()
{
	fixed_discount d1(0.1);


	volume_discount d2(10, 0.15);
	price_discount d3(100, 0.05);
	amount_discount d4(100, 0.05);


	customer c1{ "Default", nullptr };
	customer c2{ "john", &d1 };
	customer c3{"jeremy", &d3};

	article a1{ 1,"pen", 5, article_unit::piece,nullptr }; // 할인 없음
	article a2{ 2, "expensive pen", 15, article_unit::piece, &d1 };
	article a3{ 3, "scissors", 10, article_unit::piece, &d2 };

	cummulative_price_calculator calc;

	order o1{ 101, &c1, {{a1,1,nullptr}}, nullptr };
	assert(are_equal(calc.calculate_price(o1),5));
	order o3{ 103, &c1, {{a2,1,nullptr}}, nullptr };
	assert(are_equal(calc.calculate_price(o3), 13.5));
	order o6{ 106, &c1, {{a3, 15, nullptr}}, nullptr };
	assert(are_equal(calc.calculate_price(o6), 127.5));
	order o9{ 109, &c3, {{a2, 20, &d1}}, &d4 };
	assert(are_equal(calc.calculate_price(o9), 219.3075));
	

}

