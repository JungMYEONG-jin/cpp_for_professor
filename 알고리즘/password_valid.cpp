#include <regex>
#include <string>
#include <iostream>
#include <mutex>

using namespace std;

bool check_password(string message)
{
	if (message.size() < 10)
		return false;

	//첫번째로 길이검증

	int low = 0;
	int high = 0;
	int digit = 0;
	int special = 0;

	for (auto i : message)
	{
		if (islower(i))
			low++;
		if (isupper(i))
			high++;
		if (isdigit(i))
			digit++;
		if (!isalnum(i))
			special++;
	}

	if (high >= 1 && special >= 1 && digit>=1)
		return true;

	return false;

}


// 데코레이터 패턴을 사용

class password_validator
{
public:
	virtual ~password_validator() {}
	virtual bool validate(string_view password) = 0;
};

class length_validator final : public password_validator
{
public:
	length_validator(unsigned int minlen)
		:len(minlen)
	{}

	virtual bool validate(string_view message) override { return message.size() >= len; }


private:
	unsigned int len;
};



class passwrod_validator_decorator : public password_validator
{
public:

	explicit passwrod_validator_decorator(unique_ptr<password_validator> i) :
		inner(move(i))
	{

	}

	virtual bool validate(string_view pass) override { return inner->validate(pass); };



private:
	unique_ptr<password_validator> inner;
};



class digit_validator_decorator final: public passwrod_validator_decorator
{
public:

	explicit digit_validator_decorator(unique_ptr<password_validator> i)
		:passwrod_validator_decorator(move(i))
	{}



	virtual bool validate(string_view pass) override
	{
		if (!passwrod_validator_decorator::validate(pass))
			return false;

		return pass.find_first_of("0123456789") != string::npos;
	}
};



class case_validator_decorator : public passwrod_validator_decorator
{
public:
	explicit case_validator_decorator(unique_ptr<password_validator> i)
		:passwrod_validator_decorator(move(i))
	{

	}


	virtual bool validate(string_view pass) override
	{
		if (!passwrod_validator_decorator::validate(pass))
			return false;
		bool islow = false;
		bool isupp = false;

		for (int i = 0; i < pass.size() && !(islow && isupp); i++)
		{
			if (islower(pass[i])) islow = true;
			if (isupper(pass[i])) isupp = true;
		}

		return islow && isupp;
	}
};






class symbol_validator_decorator : public passwrod_validator_decorator
{
public:

	explicit symbol_validator_decorator(unique_ptr<password_validator> i)
		:passwrod_validator_decorator(move(i))
	{}



	virtual bool validate(string_view pass) override
	{
		if (!passwrod_validator_decorator::validate(pass))
			return false;

		return pass.find_first_of("!@#$%^&*(){}[]?<>") != string::npos;
		
	}
};



int main()
{
	cout << check_password("asdadadaeewwe") << endl;
	cout << check_password("asdad1Aadaeew^we") << endl;

	auto validator1 = std::make_unique<digit_validator_decorator>(make_unique<length_validator>(8));

	cout << validator1->validate("ABcdsewqeqw11") << endl;
	cout << validator1->validate("eqw11") << endl;

	auto validator2 = std::make_unique<symbol_validator_decorator>(make_unique<case_validator_decorator>(make_unique<digit_validator_decorator>(make_unique<length_validator>(8))));

	cout << validator2->validate("ABcdsewqeqw11") << endl;
	cout << validator2->validate("ABcdsewqeqw@#11") << endl;


}