#include <regex>
#include <string>
#include <iostream>
#include <mutex>
#include <random>
#include <array>
#include <unordered_map>
#include <map>


using namespace std;


class password_generator
{
public:
	virtual string generate() = 0;
	virtual string allowed_chars() const = 0;
	virtual size_t length() const = 0;
	virtual void add(unique_ptr<password_generator>) = 0;

	virtual ~password_generator() {}
};

class basic_password_generator : public password_generator
{
	size_t len;
public:
	explicit basic_password_generator(size_t const min) noexcept
		:len(min)
	{

	}

	virtual size_t length() const noexcept  override final
	{
		return len;
	}



	virtual string generate() override
	{
		throw runtime_error("실행되지 않았습니다");
	}

	virtual string allowed_chars() const override 
	{
		throw runtime_error("실행되지 않았습니다");
	}

	virtual void add(unique_ptr<password_generator>) override
	{
		throw runtime_error("실행되지 않았습니다");
	}

	
};

class digit_generator : public basic_password_generator
{
public:
	explicit digit_generator(size_t const len) noexcept
		:basic_password_generator(len)
	{

	}

	virtual string allowed_chars() const override
	{
		return "0123456789";
	}


};

class symbol_generator : public basic_password_generator
{
public:
	explicit symbol_generator(size_t const len) noexcept
		:basic_password_generator(len)
	{

	}

	virtual string allowed_chars() const override
	{
		return "!@#$%^&*(){}[]?<>";
	}


};

class upper_generator : public basic_password_generator
{
public:
	explicit upper_generator(size_t const len) noexcept
		:basic_password_generator(len)
	{

	}

	virtual string allowed_chars() const override
	{
		return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	}
};


class lower_generator : public basic_password_generator
{
public:
	explicit lower_generator(size_t const len) noexcept
		:basic_password_generator(len)
	{

	}

	virtual string allowed_chars() const override
	{
		return "abcdefghijklmnopqrstuvwxyz";
	}
};


class composite_password_generator : public password_generator
{
	
	
	virtual size_t length() const override
	{
		throw runtime_error("실행되지 않았습니다");
	}

	virtual string allowed_chars() const override
	{
		throw runtime_error("실행되지 않았습니다");
	}

public:
	composite_password_generator()
	{
		auto seed_data = array<int, std::mt19937::state_size>{};

		std::generate(begin(seed_data), end(seed_data), ref(rd));

		std::seed_seq seq(begin(seed_data), end(seed_data));
		eng.seed(seq);

	}

	virtual string generate() override
	{
		string pass;


		for (auto& i : generators)
		{
			string res = i->allowed_chars();

			uniform_int_distribution<> ud(0, static_cast<int>(res.size() - 1));

			for (size_t k = 0; k < i->length(); k++)
			{
				pass += res[ud(eng)];
			}
		}

		std::shuffle(begin(pass), end(pass), eng);
		return pass;

	}



	virtual void add(unique_ptr<password_generator> i) override
	{
		generators.push_back(move(i));
	
	}

private:
	random_device rd;
	mt19937 eng;
	vector<unique_ptr<password_generator>> generators;
};

int main()
{
	composite_password_generator i;
	i.add(make_unique<symbol_generator>(2));
	i.add(make_unique<digit_generator>(3));
	i.add(make_unique<lower_generator>(2));
	i.add(make_unique<upper_generator>(1));
	cout << i.generate() << endl;
}