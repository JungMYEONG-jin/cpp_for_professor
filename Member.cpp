#include "Member.h"




string Member::getName() const
{
	return name;

}

string Member::getPhoneNumber() const
{
	return phone;
}

bool Member::operator==(const Member& left) const
{
	return this->name == left.name && this->phone == left.phone;
}

void Member::setName(string name)
{
	name = name;
}

void Member::setPhone(string phone)
{
	phone = phone;
}