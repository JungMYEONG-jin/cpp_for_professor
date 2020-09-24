#include <string>
#include <string_view>
#include <mutex>
#include <iostream>
#include <random>
#include <array>
#include <algorithm>
#include <random>
#include <numeric>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

enum class sex_type { female, male };
enum class region_type { 서울특별시, 경기도, 전라도 };
//서울 00~08 경기도 11~15 전라도 55~56
class social_number_generator
{
public:
	virtual int sex_digit(sex_type const sex) const noexcept = 0;
	virtual int modulo_value() const noexcept = 0;
	virtual int next_random(unsigned int  year, unsigned int  month, unsigned int day) = 0;
	virtual string region_digit(region_type const reg) const noexcept = 0;
	social_number_generator(int const min, int const max)
		:ud(min, max)
	{
		auto seed_data = array<int, mt19937::state_size>{};
		random_device rd;
		std::generate(seed_data.begin(), seed_data.end(), std::ref(rd));
		std::seed_seq seq(seed_data.begin(), seed_data.end());
		mt.seed(seq);
	}

	string generate(sex_type const sex, region_type const reg, unsigned int const year, unsigned int const month, unsigned int const day)
	{
		stringstream snum;
		snum << year;
		if (month >= 10)
			snum << year;
		else
			snum << "0" << month;
		snum << day << "-";
		snum << sex_digit(sex);
		snum << region_digit(reg);
		snum << next_random(year, month, day);

		auto number = snum.str();

		auto idx = number.length();

		auto sum = std::accumulate(begin(number), end(number), 0, [&idx](unsigned int const s, char const c) {
			return s + idx-- * (c - '0');
			});

		auto rest = sum % modulo_value();
		snum << modulo_value() - rest;

		return snum.str();

	}



protected:
	map<unsigned, int> cache;
	mt19937 mt;
	uniform_int_distribution<> ud;
};


class korea_number_generator final : public social_number_generator
{
public:
	korea_number_generator() :
		social_number_generator(100, 999)
	{

	}

protected:
	virtual int sex_digit(sex_type const sex) const noexcept override { if (sex == sex_type::female) return 2; else return 1; }
	virtual int modulo_value() const noexcept override { return 11; }
	virtual string region_digit(region_type const reg) const noexcept override
	{
		if (reg == region_type::서울특별시)
			return "00";
		else if (reg == region_type::전라도)
			return "55";
		else if (reg == region_type::경기도)
			return "11";
		else
			return "13";
	}
	virtual int next_random(unsigned int year, unsigned int month, unsigned int day) override
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


};

class social_number_generator_factory
{
public:
	social_number_generator_factory()
	{
		generators["korea"] = make_unique<korea_number_generator>();
	}
	social_number_generator* get_generator(string_view country) const
	{
		auto it = generators.find(country.data());
		if (it != generators.end())
			return it->second.get();
		throw runtime_error("Not Found");
	}
private:
	map<string, unique_ptr<social_number_generator>> generators;
};





int main()
{
	social_number_generator_factory fact;

	auto sn1 = fact.get_generator("korea")->generate(sex_type::female, region_type::서울특별시, 17, 9, 25);
	cout << sn1 << endl;
}