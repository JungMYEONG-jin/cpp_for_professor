#include "RentInfo.h"





string RentInfo::getDate() const
{
	return date;
}

const Member& RentInfo::getMember() const
{
	return member;
}

const Book& RentInfo::getBook() const
{
	return book;
}

bool RentInfo::operator==(const RentInfo& left) const
{
	return this->date == left.date && this->member == left.member && this->book == left.book && this->book.get_id() == left.book.get_id();
}

bool RentInfo::rent_stat() const
{
	return IsRented;
}

void RentInfo::set_rent()
{
	IsRented = true;
}

void RentInfo::setBook(Book& book)
{
	book = book;
}

void RentInfo::setMember(Member& member)
{
	member = member;
}

void RentInfo::setDate(string date)
{
	date = date;
}