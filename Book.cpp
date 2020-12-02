#include "Book.h"





string Book::get_book_name() const
{
	return name;
}

string Book::get_writer_name() const
{
	return writer;
}

unsigned int Book::get_id() const
{
	return id;
}

//아이디별 정리
bool Book::operator<(const Book& left) const
{
	return this->id < left.id;
}


// numofMap에 기록되어야 하므로 book의 equality는 작가 그리고 책 이름이 같으면 같은걸 의미한다.
bool Book::operator==(const Book& left) const
{
	return this->name == left.name && this->writer == left.writer;
}

void Book::set_id(unsigned int id)
{
	id = id;
}

void Book::set_name(string name)
{
	name = name;
}
void Book::set_writer(string writer)
{
	writer = writer;
}