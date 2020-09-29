#include <string>
#include <vector>
#include <string_view>
#include <fstream>
#include <iostream>
#include <mutex>

using namespace std;

class role
{
public:
	virtual double approval_limit() const noexcept = 0;
	virtual ~role() {}

};

class employee_role : public role
{
public:
	virtual double approval_limit() const noexcept override { return 1000; }
};

class team_manager_role : public role
{
public:
	virtual double approval_limit() const noexcept override { return 10000; }
};

class department_manager_role : public role
{
public:
	virtual double approval_limit() const noexcept override { return 100000; }
};

class president_role : public role
{
public:
	virtual double approval_limit() const noexcept override { return std::numeric_limits<double>::max(); }
};

struct expense
{
	double amount;
	string description;

	explicit expense(double const amount, string text)
		:amount(amount), description(text)
	{

	}

	

};


class employee
{
private:
	string name;
	shared_ptr<employee> direct_manager;
	unique_ptr<role> own_role;
public:
	explicit employee(string name, unique_ptr<role> ownrole)
		:name(name), own_role(move(ownrole))
	{

	}


	virtual void set_direct_manager(shared_ptr<employee> a)
	{
		direct_manager = a;

	}
	void approve(expense const& exp)
	{
		if (exp.amount <= own_role->approval_limit())
			cout << name << " approve expense " << exp.description << " cost " << exp.amount << endl;
		else if (direct_manager != nullptr)
			direct_manager->approve(exp);
	}
};

int main()
{
	auto jhon = make_shared<employee>("john gale", make_unique<employee_role>());
	auto mj = make_shared<employee>("MJ Jung", make_unique<president_role>());
	auto hose = make_shared<employee>("Jose Hose", make_unique<department_manager_role>());


	jhon->set_direct_manager(hose);
	hose->set_direct_manager(mj);


	jhon->approve(expense{ 500, "magazine" });
	mj->approve(expense{ 541212, "building" });
	hose->approve(expense{ 45411, "drink" });



}