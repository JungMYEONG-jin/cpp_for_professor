#include "Library.h"
#include <iostream>




void Library::PrintAllContents()
{
	cout << "------Contents information------" << endl;

	for (auto& it : bookinfo)
	{
		int count = 0;
		cout << "Book: " << it.get_book_name() << "   Writer: " << it.get_writer_name() << "   id: " << it.get_id() << "   Rent: ";

		auto i = find_if(rentinfo.begin(), rentinfo.end(), [&it](const RentInfo& rent) {return rent.getBook() == it && rent.getBook().get_id() == it.get_id(); });

		if (i != rentinfo.end())
		{
			cout << i->getDate() << endl;
		}
		else
			cout << "Can Rent" << endl;
		/*
		for (auto& i : rentinfo)
		{
			if (i.getBook()==it && i.getBook().get_id() == it.get_id())
			{
				cout << i.getDate();// �ݳ��ؾ��� ��¥
				count++;
			}
		}
		if (count == 0)
			cout << "Can Rent";
		cout << endl;
		*/
	}

}


void Library::PrintAllMember()
{
	cout << "------Member information------" << endl;
	for (auto& it : memberinfo)
	{

		string rent_book;
		int count = 0;
		cout << "Name: " << it.getName() << "   Phone: " << it.getPhoneNumber();
		for (auto& i : rentinfo)
		{
			if (i.getMember() == it)
			{
				count++;
				rent_book+= i.getBook().get_book_name() + "(" + i.getDate() + "), ";
			}

		}
		if (count >= 1)
			rent_book.erase(rent_book.size() - 2, 2);
		cout << "   Total " + to_string(count) + " Rent: " << rent_book << endl;

	}
}


void Library::PrintRentBook()
{

	cout << "------Rent_Book information------" << endl;
	for (auto& it : rentinfo)
	{
		cout << "Book: " << it.getBook().get_book_name() << " Writer: " << it.getBook().get_writer_name() << " id: " << it.getBook().get_id() << " Date: " << it.getDate() << endl;
	}
	// ���� ���ȴ����� �������� �ʴ´� ���� ��������
}


bool Library::RentBook(RentInfo& paramrentinfo)
{

	// �ϴ� ȸ���� �����ϴ��� Ȯ���ؾ���

	if (SearchMemberByMember(paramrentinfo.getMember()) == -1)
	{
		cout << "The member is not existed in Member information!" << endl;
		return false;
	}


	if (SearchBookByBook(paramrentinfo.getBook()) == -1)
	{
		cout << "The book is not existed in Book information!" << endl;
		return false;
	}

	if (IsRented(paramrentinfo))
	{
		// �뿩�� �Ȱ���
		cout << "Already Rented!" << endl;
		return false;
	}
	cout << "The Book Rented Successfully" << endl;
	paramrentinfo.set_rent();
	rentinfo.push_back(paramrentinfo);
	return true;

}

bool Library::AddMember(const Member& newMember)
{
	if (SearchMemberByMember(newMember) != -1)
	{
		cout << "Phone Number Duplicated!" << endl;
		return false;
	}
	cout << "Add Member Success!" << endl;
	memberinfo.push_back(newMember);
	return true;
}

bool Library::DeleteMember(const Member& newMember)
{

	int idx = SearchMemberByMember(newMember);

	if (idx != -1)
	{
		memberinfo.erase(memberinfo.begin() + idx);
		rentinfo.erase(remove_if(rentinfo.begin(), rentinfo.end(), [&newMember](const RentInfo& rent) {return rent.getMember() == newMember; }), rentinfo.end());
		cout << "Delete Success!" << endl;
		return true;

	}
	//�ش� ����� �������� �ʴ� ���
	cout << "Delete Failed! The Member is not existed in MemberInfo." << endl;
	return false;


}


bool Library::AddBook(const Book& newMember)
{
	if (SearchBookByBook(newMember) != -1)
	{
		cout << "The Book code is existed already!" << endl;
		return false;
	}
	cout << "The Book is added Successfully" << endl;
	bookinfo.push_back(newMember);
	numOfBook[newMember]++; // �ѱǼ� ����
	return true;

}

bool Library::DeleteBook(const Book& newMember)
{
	int idx = SearchBookByBook(newMember);


	if (idx != -1)// �����ϸ�
	{
		bookinfo.erase(bookinfo.begin() + idx);
		numOfBook[newMember]--;
		rentinfo.erase(remove_if(rentinfo.begin(), rentinfo.end(), [&newMember](const RentInfo& rent) {return rent.getBook() == newMember && rent.getBook().get_id() == newMember.get_id(); }),rentinfo.end());
		cout << "Book deleted Successfully" << endl;
		return true;
	}
	cout << "Can not find the Book!" << endl;
	return false;
	


}

bool Library::IsRented(const RentInfo& paramRentInfo)
{
	auto it = find_if(rentinfo.begin(), rentinfo.end(), [&paramRentInfo](const RentInfo& rent) {return rent.getBook() == paramRentInfo.getBook() && rent.getBook().get_id() == paramRentInfo.getBook().get_id(); });
	if (it == rentinfo.end())
		return false; // ��ġ����� ����

	return true; // �뿩���ΰ���

}



int Library::SearchBookByKey(const string& key)
{
	// key�� �۰��̸� �Ǵ� å�̸��� �� �� �ִ�

	auto it = find_if(bookinfo.begin(), bookinfo.end(), [&key](const Book& book) {return book.get_book_name() == key || book.get_writer_name() == key; });
	if (it == bookinfo.end())
		return -1; // �ش� å�� �������� ����
	// �뿩 ���� ���ε� ���������
	vector<Book> res;
	for (auto& i : bookinfo)
		if (*it == i)
			res.push_back(i);
	// å�̸� �Ǵ� �۰��̸��� ������ �ϴ� push

	for (auto& i : res)
	{
		bool find = false;
		cout << "Book: " << i.get_book_name() << " Writer: " << i.get_writer_name() << " id: " << i.get_id() << " Rent: ";

		for (auto& rent : rentinfo)
		{
			if (rent.getBook() == i && rent.getBook().get_id() == i.get_id())
			{
				cout << "Rented!" << endl;
				find = true;
			}
		}
		if (!find)
			cout << "Can Rent!" << endl;


	}
	return it - bookinfo.begin(); // index return
}


int Library::SearchMemberByKey(const string& key)
{
	auto it = find_if(memberinfo.begin(), memberinfo.end(), [&key](const Member& member) {return member.getPhoneNumber() == key; });

	if (it == memberinfo.end())
		return -1;
	return it - memberinfo.begin();
    // phonenumber�� ã��
}

int Library::SearchBookByBook(const Book& book)
{
	auto it = find_if(bookinfo.begin(), bookinfo.end(), [&book](const Book& books) {return book == books && book.get_id() == books.get_id(); });
	if (it == bookinfo.end())
		return -1;
	return it - bookinfo.begin();
}

int Library::SearchMemberByMember(const Member& member)
{
	//just use operator==
	auto it = find(memberinfo.begin(), memberinfo.end(),member);
	if (it == memberinfo.end())
		return -1;
	return it - memberinfo.begin();
}



