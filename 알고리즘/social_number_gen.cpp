#include <string>
#include <string_view>
#include <iostream>
#include <regex>
#include <assert.h>
#include <optional>
#include <vector>
#include <random>
#include <array>
#include <algorithm>
#include <map>
#include <sstream>
#include <numeric>
enum class sex{female, male};

using namespace std;
using uint = unsigned int;

class social_number_generator
{
public:

	virtual int sex_digit(sex const se) const noexcept = 0;

	virtual int next_random(unsigned int const year, unsigned int const month, unsigned int const random) = 0;
	virtual int modulo_value() const noexcept = 0;

	social_number_generator(int const min, int const max)
		:ud(min, max)
	{
		random_device rd;
		auto seed_data = array<int, mt19937::state_size>{};
		std::generate(seed_data.begin(), seed_data.end(), std::ref(rd));
		std::seed_seq seq(seed_data.begin(), seed_data.end());

		mt.seed(seq);


	}
	string generate(sex const se, unsigned int const year, unsigned int const month, unsigned int const day)
	{
		stringstream snumber;

		
		snumber << year << month << day;
		snumber << "-";
		snumber << sex_digit(se);
		snumber << next_random(year, month, day);

		auto number = snumber.str();

		auto idx = number.length();

		auto sum = accumulate(begin(number), end(number), 0, [&idx](unsigned int const s, char const c) {return s + static_cast<unsigned int>(idx-- * (c - '0')); });


		auto rest = sum & modulo_value();

		snumber << modulo_value() - rest;
		
		return snumber.str();



	}


	virtual ~social_number_generator() { }

protected:
	map<unsigned, int> cache;
	uniform_int_distribution<> ud;
	mt19937 mt;
};


class south_social_number_generator final : public social_number_generator
{
public:

	south_social_number_generator()
		:social_number_generator(1000, 9999)
	{

	}



	virtual int sex_digit(sex const se) const noexcept override { if (se == sex::female) return 1; else return 2; }
	virtual int next_random(unsigned int const year, unsigned int const month, unsigned int const day) override
	{
		auto key = year * 10000 + month * 100 + day;

		while (true)
		{
			auto number = ud(mt);
			auto pos = cache.find(number);
			if (pos == cache.end())
			{
				cache[key] = number;
				return number;
			}
		}
	}

	virtual int modulo_value() const noexcept override
	{
		return 11;
	}

};


class korea_social_number_generator : public social_number_generator
{
public:
	korea_social_number_generator()
		:social_number_generator(1000, 9999)
	{

	}
	virtual int sex_digit(sex const se) const noexcept override { if (se == sex::female) return 2; else return 1; }

	virtual int next_random(unsigned int const year, unsigned int const month, unsigned int const day) override
	{
		auto key = year * 10000 + month * 100 + day;

		while (true)
		{
			auto number = ud(mt);
			auto pos = cache.find(number);
			if (pos == cache.end())
			{
				cache[key] = number;
				return number;
			}
		}
	}


	virtual int modulo_value() const noexcept override
	{
		return 11;
	}
};












class north_social_number_generator final : public social_number_generator
{
public:
	north_social_number_generator()
		:social_number_generator(10000, 99999)
	{

	}
	virtual int sex_digit(sex const se) const noexcept override
	{
		if (se == sex::female)
			return 9;
		else
			return 7;
	}

	virtual int next_random(unsigned int const year, unsigned int const month, unsigned int const day) override
	{
		auto key = year * 10000 + month * 100 + day;

		while (true)
		{
			auto number = ud(mt);
			auto pos = cache.find(number);
			if (pos == cache.end())
			{
				cache[key] = number;
				return number;
			}
		}
	}

	virtual int modulo_value() const noexcept override { return 11; }

};


class social_number_generator_factory 
{
public:
	social_number_generator_factory()
	{
		generators["north"] = make_unique<north_social_number_generator>();
		generators["south"] = make_unique<south_social_number_generator>();
		generators["korea"] = make_unique<korea_social_number_generator>();
	}

	social_number_generator* get_generator(string_view region) const
	{
		auto val = generators.find(region.data());
		if (val != generators.end())
			return val->second.get();

		throw runtime_error("Invalid Country");


	}

private:
	map<string, unique_ptr<social_number_generator>> generators;
};

int main()
{
	social_number_generator_factory fact;

	auto sn1 = fact.get_generator("north")->generate(sex::female, 2017, 12, 25);
	//auto sn2 = fact.get_generator("north")->generate(sex::female, 2017, 12, 25);
	auto sn3 = fact.get_generator("north")->generate(sex::male, 2017, 12, 25);


	auto ss1 = fact.get_generator("south")->generate(sex::female, 2020, 9, 11);
	//auto ss2 = fact.get_generator("south")->generate(sex::female, 2020, 9, 11);
	auto ss3 = fact.get_generator("south")->generate(sex::male, 2020, 9, 11);

	auto kr1 = fact.get_generator("korea")->generate(sex::male, 97, 12, 11);

	cout << sn1 << '\n'  << sn3 << '\n' << ss1 << '\n'  << ss3 <<'\n'<<kr1<< endl;

}