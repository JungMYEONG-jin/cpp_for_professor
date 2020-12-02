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

//���̵� ����
bool Book::operator<(const Book& left) const
{
	return this->id < left.id;
}


// numofMap�� ��ϵǾ�� �ϹǷ� book�� equality�� �۰� �׸��� å �̸��� ������ ������ �ǹ��Ѵ�.
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