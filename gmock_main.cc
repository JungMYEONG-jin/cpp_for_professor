// Copyright 2008, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/**
@file gmock_main.cc
@author MJ
@date 2020-12-01
@brief Library�ý����� Mock Test �����Դϴ�.

*/

#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../Library_Project/Library.h"




using ::testing::Return;
using ::testing::AtLeast;
using ::testing::ByMove;
using ::testing::Invoke;
using ::testing::ReturnRef;

/**
@brief Book Ŭ������ mock test�� ���� mocking class�Դϴ�.
*/
class MockBook : public Book
{ 
public:
	
	
	/**
	@brief get_book_name�� ���� �۵��ϴ��� �׽�Ʋ ���� mock_method�Դϴ�.
	*/
	MOCK_CONST_METHOD0(get_book_name, string());
	/**
	@brief get_writer_name�� ���� �۵��ϴ��� �׽�Ʋ ���� mock_method�Դϴ�.
	*/
	MOCK_CONST_METHOD0(get_writer_name, string());
	/**
	@brief get_id�� ���� �۵��ϴ��� �׽�Ʋ ���� mock_method�Դϴ�.
	*/
	MOCK_CONST_METHOD0(get_id, unsigned int());
	virtual bool operator<(const MockBook& left) const
	{
		return get_id() < left.get_id();
	}

};

/**
@brief MockBook ��� �Լ��� ȣ���ϱ� ���� class �Դϴ�.
*/
class Test_Mock_Book
{
	/**
	@brief MockBook class�� �Լ��� ȣ���ϱ� ���� Book class�� ��� ������ �����ϴ�.
	*/
	Book& book;
public:
	/**
	@brief ���� �������Դϴ�.
	@param Book reference�� ���ڷ� �޽��ϴ�.	
	*/
	Test_Mock_Book(Book& tbook)
		:book(tbook)
	{


	}
	/**
	@brief get_book_name �Լ��� ȣ���ϱ� ���� �Լ��Դϴ�.
	@param name : string�� �����Դϴ�. å �̸��� �ǹ��մϴ�.
	@return ��� ���� book�� å �̸��� ��ȯ�մϴ�.
	*/
	string init_book_name(string name)
	{
		book.set_name(name);
		return book.get_book_name();
	}
	/**
	@brief get_writer_name �Լ��� ȣ���ϱ� ���� �Լ��Դϴ�.
	@param name : string�� �����Դϴ�. �۰� �̸��� �ǹ��մϴ�.
	@return ��� ���� book�� �۰� �̸��� ��ȯ�մϴ�.
	*/
	string init_writer_name(string name)
	{
		book.set_writer(name);
		return book.get_writer_name();
	}
	/**
	@brief get_id �Լ��� ȣ���ϱ� ���� �Լ��Դϴ�.
	@param id : unsigned int�� �����Դϴ�. å id�� �ǹ��մϴ�.
	@return ��� ���� book�� å id�� ��ȯ�մϴ�.
	*/
	unsigned int init_id(unsigned int id)
	{
		book.set_id(id);
		return book.get_id();
	}

};

/**
@brief Book Ŭ������ equality�� üũ�ϴ� �׽�Ʈ�Դϴ�.
@details operator== �� overlodaing�� ���������� �۵��Ͽ� true�� ��ȯ�ϴ��� �׽�Ʈ�մϴ�.
*/
TEST(book_test, check_equality_true)
{
	// mock Ŭ������ ������ �񱳴� �Ұ����غ���
	// ������� ��� �Ҹ� - > default ������ ���Ե�
	Book a("mj", "devs", 123);
	Book b("mj", "devs", 1234);
	// map�� ���� å�� �����ϱ� ���� book operator==�� å�̸� �۰��̸��� ������ ���� å���� �����Ͽ���.
	bool is = (a == b);

	EXPECT_EQ(is, true);


}
/**
@brief Book Ŭ������ equality�� üũ�ϴ� �׽�Ʈ�Դϴ�.
@details operator== �� overlodaing�� ���������� �۵��Ͽ� false�� ��ȯ�ϴ��� �׽�Ʈ�մϴ�.
*/
TEST(book_test, check_equality_false)
{
	Book a("����", "devs", 123);
	Book b("mj", "devs", 1234);
	bool is = (a == b);

	EXPECT_EQ(is, false);

}
/**
@brief Book Ŭ������ get_book_name�� �׽�Ʈ �մϴ�.
@details MockBook, Test_Mock_Book class�� �̿��� Book class�� get_book_name�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark true case �̹Ƿ� �׽�Ʈ�� ����ؾ��մϴ�!
*/
TEST(book_test, check_get_name_success)
{
	MockBook a;
	Test_Mock_Book my(a);

	EXPECT_CALL(a, get_book_name()).Times(1).WillOnce(Return("����"));
	auto val = my.init_book_name("����");

	EXPECT_EQ(val, "����");


}
/**
@brief Book Ŭ������ get_book_name�� �׽�Ʈ �մϴ�.
@details MockBook, Test_Mock_Book class�� �̿��� Book class�� get_book_name�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark �Ϻη� Ʋ�� ���� ����ϴ�. �׽�Ʈ �� �����ؾ��մϴ�!
*/
TEST(book_test, check_get_name_failure)
{
	MockBook a;
	Test_Mock_Book my(a);

	EXPECT_CALL(a, get_book_name()).Times(1).WillOnce(Return("jmj"));
	auto val = my.init_book_name("jmj2");

	EXPECT_EQ(val, "jmj2");


}
/**
@brief Book Ŭ������ get_writer_name�� �׽�Ʈ �մϴ�.
@details MockBook, Test_Mock_Book class�� �̿��� Book class�� get_writer_name�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark true case �̹Ƿ� �׽�Ʈ�� ����ؾ��մϴ�!
*/
TEST(book_test, check_get_writer_success)
{
	MockBook a;
	Test_Mock_Book my(a);

	EXPECT_CALL(a, get_writer_name()).Times(1).WillOnce(Return("davinch"));
	auto val = my.init_writer_name("davinch");
	EXPECT_EQ(val, "davinch");
}
/**
@brief Book Ŭ������ get_writer_name�� �׽�Ʈ �մϴ�.
@details MockBook, Test_Mock_Book class�� �̿��� Book class�� get_writer_name�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark �Ϻη� Ʋ�� ���� ����ϴ�. �׽�Ʈ �� �����ؾ��մϴ�!
*/
TEST(book_test, check_get_writer_failure)
{
	MockBook a;
	Test_Mock_Book my(a);

	EXPECT_CALL(a, get_writer_name()).Times(1).WillOnce(Return("berber"));
	auto val = my.init_writer_name("davinch");
	EXPECT_EQ(val, "davinch");
}



/**
@brief Book Ŭ������ get_id�� �׽�Ʈ �մϴ�.
@details MockBook, Test_Mock_Book class�� �̿��� Book class�� get_id�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark true case �̹Ƿ� �׽�Ʈ�� ����ؾ��մϴ�!
*/
TEST(book_test, check_id_success)
{
	MockBook a;
	Test_Mock_Book my(a);

	EXPECT_CALL(a, get_id()).Times(1).WillOnce(Return(123));
	auto val = my.init_id(123);
	EXPECT_EQ(val, 123);
}

/**
@brief Book Ŭ������ get_id�� �׽�Ʈ �մϴ�.
@details MockBook, Test_Mock_Book class�� �̿��� Book class�� get_id�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark �Ϻη� Ʋ�� ���� ����ϴ�. �׽�Ʈ �� �����ؾ��մϴ�!
*/
TEST(book_test, check_id_failure)
{
	MockBook a;
	Test_Mock_Book my(a);

	EXPECT_CALL(a, get_id()).Times(1).WillOnce(Return(1235));
	auto val = my.init_id(123);
	EXPECT_EQ(val, 123);
}

/**
@brief Member Ŭ������ equality �׽�Ʈ�Դϴ�.
@remark true case �̹Ƿ� �׽�Ʈ�� ����ؾ��մϴ�!
*/
TEST(member_test, check_equality)
{
	Member a("010", "mj");
	Member b("010", "mj");

	bool is = a == b;
	EXPECT_EQ(is, true);


}

/**
@brief Member Ŭ������ equality �׽�Ʈ�Դϴ�.
@remark �Ϻη� Ʋ�� ���� ����ϴ�. �׽�Ʈ �� �����ؾ��մϴ�!
*/
TEST(member_test, check_equality_failure)
{
	Member a("010", "mj");
	Member c("02912", "kmg");

	bool is = a == c;
	EXPECT_EQ(is, false);

}

/**
@brief Member Ŭ������ mock test�� ���� mocking class�Դϴ�.
*/

class MockMbember : public Member
{

public:
	/**
	@brief getName �Լ��� �׽�Ʈ�� mock_method �Դϴ�.
	*/
	MOCK_CONST_METHOD0(getName, string());
	/**
	@brief getPhoneNumber �Լ��� �׽�Ʈ�� mock_method �Դϴ�.
	*/
	MOCK_CONST_METHOD0(getPhoneNumber, string());


};

/**
@brief Member Ŭ������ mocking class�� ���������� �Լ��� ȣ���ϴ��� �׽�Ʈ�� Ŭ�����Դϴ�.
*/
class Test_MockMember
{
	/**
	@brief Member class reference�� ��� ������ �����ϴ�.
	*/
	Member& mem;
public:
	/**
	@brief Ŭ������ ���� �������Դϴ�.
	@param Member reference�� ���ڷ� �޽��ϴ�.
	*/
	Test_MockMember(Member& _mem)
		:mem(_mem)
	{

	}
	/**
	@brief getName�Լ��� ���������� �۵��ϴ��� Ȯ���ϱ� ���� �Լ��Դϴ�.
	@param name : string�� �����Դϴ�. ��� �̸��� �ǹ��մϴ�.
	@return ��� ���� mem�� getName�� ȣ���մϴ�.
	*/
	string initName(string name)
	{
		mem.setName(name);
		return mem.getName();
	}
	/**
	@brief getPhoneNumber�Լ��� ���������� �۵��ϴ��� Ȯ���ϱ� ���� �Լ��Դϴ�.
	@param name : string�� �����Դϴ�. �޴��� ��ȣ�� �ǹ��մϴ�.
	@return ��� ���� mem�� getPhoneNumber�� ȣ���մϴ�.
	*/
	string initPhone(string phone)
	{
		mem.setPhone(phone);
		return mem.getPhoneNumber();
	}

};
/**
@brief Member Ŭ������ getName�� �׽�Ʈ �մϴ�.
@details MockMbember, Test_MockMember class�� �̿��� Member Ŭ������ getName�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark true case �̹Ƿ� �׽�Ʈ�� ����ؾ��մϴ�!
*/
TEST(member_test, check_get_name_success)
{
	MockMbember a;
	Test_MockMember my(a);
	EXPECT_CALL(a, getName()).Times(1).WillOnce(Return("mj"));

	auto val = my.initName("mj");
	EXPECT_EQ(val, "mj");

}
/**
@brief Member Ŭ������ getName�� �׽�Ʈ �մϴ�.
@details MockMbember, Test_MockMember class�� �̿��� Member Ŭ������ getName�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark �Ϻη� Ʋ�� ���� ����ϴ�. �׽�Ʈ �� �����ؾ��մϴ�!
*/
TEST(member_test, check_get_name_failure)
{
	MockMbember a;
	Test_MockMember my(a);
	EXPECT_CALL(a, getName()).Times(1).WillOnce(Return("JMJ"));

	auto val = my.initName("mj");
	EXPECT_EQ(val, "mj");

}

/**
@brief Member Ŭ������ getPhoneNumber�� �׽�Ʈ �մϴ�.
@details MockMbember, Test_MockMember class�� �̿��� Member Ŭ������ getPhoneNumber�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark true case �̹Ƿ� �׽�Ʈ�� ����ؾ��մϴ�!
*/
TEST(member_test, check_get_phone_success)
{
	MockMbember a;
	Test_MockMember my(a);
	EXPECT_CALL(a, getPhoneNumber()).Times(1).WillOnce(Return("0101234"));

	auto val = my.initPhone("0101234");
	EXPECT_EQ(val, "0101234");

}

/**
@brief Member Ŭ������ getPhoneNumber�� �׽�Ʈ �մϴ�.
@details MockMbember, Test_MockMember class�� �̿��� Member Ŭ������ getPhoneNumber�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark �Ϻη� Ʋ�� ���� ����ϴ�. �׽�Ʈ �� �����ؾ��մϴ�!
*/
TEST(member_test, check_get_phone_failure)
{
	MockMbember a;
	Test_MockMember my(a);
	EXPECT_CALL(a, getPhoneNumber()).Times(1).WillOnce(Return("01012345678"));

	auto val = my.initPhone("0101234");
	EXPECT_EQ(val, "0101234");

}

/**
@brief RentInfo Ŭ������ equality �׽�Ʈ�Դϴ�.
@remark true case �̹Ƿ� �׽�Ʈ�� ����ؾ��մϴ�!
*/
TEST(rentinfo_test, check_equality_success)
{
	RentInfo a("2020-11-27", Member("010", "mj"), Book("devbook", "davinch", 123));
	RentInfo b("2020-11-27", Member("010", "mj"), Book("devbook", "davinch", 123));
	bool is = a == b;
	EXPECT_EQ(is, true);
}

/**
@brief RentInfo Ŭ������ equality �׽�Ʈ�Դϴ�.
@remark �Ϻη� Ʋ�� ���� ����ϴ�. �׽�Ʈ �� �����ؾ��մϴ�!
*/
TEST(rentinfo_test, check_equality_failure)
{
	RentInfo a("2020-11-27", Member("010", "mj"), Book("devbook", "davinch", 123));
	RentInfo b("2020-11-27", Member("010", "mj"), Book("devbook", "davinch", 1234));
	bool is = a == b;
	EXPECT_EQ(is, true);
}
/**
@brief RentInfo Ŭ������ mock test�� ���� mocking class�Դϴ�.
*/
class Mock_Rent : public RentInfo
{
public:
	/**
	@brief getDate�� �׽�Ʈ�� ���� mock_method �Դϴ�.
	*/
	MOCK_CONST_METHOD0(getDate, string() );
	/**
	@brief getMember�� �׽�Ʈ�� ���� mock_method �Դϴ�.
	*/
	MOCK_CONST_METHOD0(getMember, const Member& ());
	/**
	@brief getBook�� �׽�Ʈ�� ���� mock_method �Դϴ�.
	*/
	MOCK_CONST_METHOD0(getBook, const Book& ());
};

/**
@brief RentInfo Ŭ������ mocking class�� ���������� �Լ��� ȣ���ϴ��� �׽�Ʈ�� Ŭ�����Դϴ�.
*/
class Test_Mock_Rent
{
	/**
	@brief RentInfo reference�� ��� ������ �����ϴ�.
	*/
	RentInfo& rent;
public:
	/**
	@brief ���� �������Դϴ�.
	@param RentInfo reference�� ���ڷ� �޽��ϴ�.
	*/
	Test_Mock_Rent(RentInfo& _rent)
		:rent(_rent)
	{

	}
	/**
	@brief getMember �Լ��� ���������� ȣ��Ǵ��� Ȯ���ϱ� ���� �Լ��Դϴ�.
	@return getMember �Լ��� ȣ���մϴ�.
	*/
	Member init_member(Member& mem)
	{
		rent.setMember(mem);
		return rent.getMember();
	}

	/**
	@brief getBook �Լ��� ���������� ȣ��Ǵ��� Ȯ���ϱ� ���� �Լ��Դϴ�.
	@return getBook �Լ��� ȣ���մϴ�.
	*/
	Book init_book(Book& book)
	{
		rent.setBook(book);
		return rent.getBook();
	}

	/**
	@brief getDate �Լ��� ���������� ȣ��Ǵ��� Ȯ���ϱ� ���� �Լ��Դϴ�.
	@return getDate �Լ��� ȣ���մϴ�.
	*/
	string init_date(string date)
	{
		rent.setDate(date);
		return rent.getDate();
	}

};



/**
@brief RentInfo Ŭ������ getDate�� �׽�Ʈ �մϴ�.
@details Mock_Rent, Test_Mock_Rent class�� �̿��� RentInfo Ŭ������ getDate�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark true case �̹Ƿ� �׽�Ʈ�� ����ؾ��մϴ�!
*/
TEST(rentinfo_test, check_get_date_success)
{
	Mock_Rent a;
	Test_Mock_Rent my(a);
	EXPECT_CALL(a, getDate()).Times(1).WillOnce(Return("2020-11-27"));
	auto val = my.init_date("2020-11-27");

	EXPECT_EQ(val, "2020-11-27");


}

/**
@brief RentInfo Ŭ������ getDate�� �׽�Ʈ �մϴ�.
@details Mock_Rent, Test_Mock_Rent class�� �̿��� RentInfo Ŭ������ getDate�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark �Ϻη� Ʋ�� ���� ����ϴ�. �׽�Ʈ �� �����ؾ��մϴ�!
*/
TEST(rentinfo_test, check_get_date_failure)
{
	Mock_Rent a;
	Test_Mock_Rent my(a);
	EXPECT_CALL(a, getDate()).Times(1).WillOnce(Return("2020-11-30"));
	auto val = my.init_date("2020-11-27");

	EXPECT_EQ(val, "2020-11-27");


}

/**
@brief RentInfo Ŭ������ getMember�� �׽�Ʈ �մϴ�.
@details Mock_Rent, Test_Mock_Rent class�� �̿��� RentInfo Ŭ������ getMember�� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark true case �̹Ƿ� �׽�Ʈ�� ����ؾ��մϴ�!
*/
TEST(rentinfo_test, check_get_member_success)
{
	Mock_Rent a;
	Test_Mock_Rent my(a);
	Member test("010", "mj");
	EXPECT_CALL(a, getMember()).Times(1).WillOnce(ReturnRef(test));
	auto mem = my.init_member(test);

	EXPECT_EQ(mem, test);



}

/**
@brief RentInfo Ŭ������ getMember �Լ��� �׽�Ʈ �մϴ�.
@details Mock_Rent, Test_Mock_Rent class�� �̿��� RentInfo Ŭ������ getMember �Լ��� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark �Ϻη� Ʋ�� ���� ����ϴ�. �׽�Ʈ �� �����ؾ��մϴ�!
*/
TEST(rentinfo_test, check_get_member_failure)
{
	Mock_Rent a;
	Test_Mock_Rent my(a);
	Member test("010", "mj");
	Member test2("12345", "kari");
	EXPECT_CALL(a, getMember()).Times(1).WillOnce(ReturnRef(test2));
	// ���н� �޸� �ּҰ� ������
	// ��� �κ��� Ʋ�ȴ����� �����Ҽ�������?

	auto mem = my.init_member(test);

	EXPECT_EQ(mem, test);


}

/**
@brief RentInfo Ŭ������ getBook �Լ��� �׽�Ʈ �մϴ�.
@details Mock_Rent, Test_Mock_Rent class�� �̿��� RentInfo Ŭ������ getBook �Լ��� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark true case �̹Ƿ� �׽�Ʈ�� ����ؾ��մϴ�!
*/
TEST(rentinfo_test, check_get_book_success)
{
	Book test("mj", "davinch", 1234);
	Book test2("mj", "picasso", 1292);

	Mock_Rent a;
	Test_Mock_Rent my(a);
	EXPECT_CALL(a, getBook()).Times(1).WillOnce(ReturnRef(test));
	auto val = my.init_book(test);

	EXPECT_EQ(val, test);

}

/**
@brief RentInfo Ŭ������ getBook �Լ��� �׽�Ʈ �մϴ�.
@details Mock_Rent, Test_Mock_Rent class�� �̿��� RentInfo Ŭ������ getBook �Լ��� ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark �Ϻη� Ʋ�� ���� ����ϴ�. �׽�Ʈ �� �����ؾ��մϴ�!
*/
TEST(rentinfo_test, check_get_book_failure)
{
	Book test("mj", "davinch", 1234);
	Book test2("mj", "picasso", 1292);

	Mock_Rent a;
	Test_Mock_Rent my(a);
	EXPECT_CALL(a, getBook()).Times(1).WillOnce(ReturnRef(test2));
	auto val = my.init_book(test);

	EXPECT_EQ(val, test);

}


/**
@brief Library Ŭ������ SearchMemberByMember �Լ��� ���� �۵��ϴ��� �׽�Ʈ �ϱ� ���� mocking class �Դϴ�.
*/
class Mock_Library_Search : public Library
{
public:
	//virtual int SearchMemberByMember(const Member& member);
	/**
	@brief SearchMemberByMember�� mock_method �Դϴ�.
	*/
	MOCK_METHOD1(SearchMemberByMember, int (const Member& member));
};

/**
@details mocking class���� AddMember�� ȣ���մϴ�. AddMember ȣ��� SearchMemberByMember �Լ��� ���������� ȣ��Ǵ��� �׽�Ʈ�մϴ�.
@remark ���� �۵��ϹǷ� �ùٸ� ���� ��ȯ�ؾ��մϴ�. ó�� ��� �˻� �� �ش� ����� �������� �����Ƿ� -1�� ��ȯ�մϴ�.
*/
TEST(Library_test, check_add_member)
{
	Mock_Library_Search a;
	Member test("010", "mj");
	EXPECT_CALL(a, SearchMemberByMember(test)).Times(1).WillOnce(Return(-1));
	a.AddMember(test);

}

/**
@details mocking class���� AddMember�� ȣ���մϴ�. AddMember ȣ��� SearchMemberByMember �Լ��� ���������� ȣ��Ǵ��� �׽�Ʈ�մϴ�.
@remark ���� �۵��ϹǷ� �ùٸ� ���� ��ȯ�ؾ��մϴ�. ó�� ��� �˻��� �ش� ����� �������� �����Ƿ� -1�� ��ȯ�ϰ� �� �Ŀ��� index�� ��ȯ�մϴ�.
*/
TEST(Library_test, check_add_member_index)
{
	Mock_Library_Search a;
	Member test("010", "mj");
	EXPECT_CALL(a, SearchMemberByMember(test)).Times(2).WillOnce(Return(-1)).WillOnce(Return(0));
	a.AddMember(test);
	a.AddMember(test);

}

/**
@details mocking class���� SearchMemberByMember �Լ��� ���������� ȣ��Ǵ��� �׽�Ʈ�մϴ�.
@remark ���� �۵��ϹǷ� �ùٸ� ���� ��ȯ�ؾ��մϴ�.
*/
TEST(Library_test, check_Search_Member_by_Member_success)
{
	Mock_Library_Search a;
	Member test("010", "mj");
	EXPECT_CALL(a, SearchMemberByMember(test)).Times(1).WillOnce(Return(-1));
	auto val = a.SearchMemberByMember(test);
	EXPECT_EQ(val, -1);

}

/**
@details mocking class���� SearchMemberByMember �Լ��� ���������� ȣ��Ǵ��� �׽�Ʈ�մϴ�.
@remark �Ϻη� Ʋ�� ���� ����ϴ�. �׽�Ʈ�� �����ؾ� �մϴ�!
*/
TEST(Library_test, check_Search_Member_by_Member_failure)
{
	Mock_Library_Search a;
	Member test("010", "mj");
	EXPECT_CALL(a, SearchMemberByMember(test)).Times(1).WillOnce(Return(-1));
	auto val = a.SearchMemberByMember(test);
	EXPECT_EQ(val, 0);

}

/**
@brief Library class�� RentBook �Լ��� �׽�Ʈ �ϱ� ���� mocking class �Դϴ�.
*/
class Mock_Library_rent : public Library
{
public:
	/**
	@brief RentBook �Լ� �׽�Ʈ�� ȣ��Ǵ� SearchMemberByMember�� �׽�Ʈ �ϱ� ���� mock_method �Դϴ�.
	*/
	MOCK_METHOD1(SearchMemberByMember, int(const Member& member));
	/**
	@brief RentBook �Լ� �׽�Ʈ�� ȣ��Ǵ� SearchBookByBook�� �׽�Ʈ �ϱ� ���� mock_method �Դϴ�.
	*/
	MOCK_METHOD1(SearchBookByBook, int(const Book& book));
	/**
	@brief RentBook �Լ� �׽�Ʈ�� ȣ��Ǵ� IsRented�� �׽�Ʈ �ϱ� ���� mock_method �Դϴ�.
	*/
	MOCK_METHOD1(IsRented, bool(const RentInfo& rent));

};

/**
@brief RentBook�� mock test�� �Ͽ� mock_method�� ���������� ȣ��Ǵ��� �׽�Ʈ�մϴ�.
@details SearchMemberByMember, SearchBookByBook, IsRented�� ȣ��Ǵ��� Ȯ���մϴ�.
@remark �׽�Ʈ�� �����ؾ��մϴ�!
*/
TEST(Library_test, check_Rent_book_success)
{
	Mock_Library_rent a;
	RentInfo test("2020-10-20", Member("123", "mj"), Book("QA", "mj", 13));
	a.AddBook(Book("QA", "mj", 13));
	a.AddMember(Member("123", "mj"));
	EXPECT_CALL(a, SearchMemberByMember(test.getMember())).Times(1).WillOnce(Return(0));
	EXPECT_CALL(a, SearchBookByBook(test.getBook())).Times(1).WillOnce(Return(0));
	EXPECT_CALL(a, IsRented(test)).Times(1).WillOnce(Return(false));
	bool is = a.RentBook(test);
	// �뿩�� ������
	EXPECT_EQ(is, true);

}

/**
@brief RentBook�� mock test�� �Ͽ� mock_method�� ���������� ȣ��Ǵ��� �׽�Ʈ�մϴ�.
@details SearchMemberByMember, SearchBookByBook, IsRented�� ȣ��Ǵ��� Ȯ���մϴ�.
@remark �׽�Ʈ�� �����ؾ��մϴ�!
*/
TEST(Library_test, check_Rent_book_failure)
{
	Mock_Library_rent a;
	RentInfo test("2020-10-20", Member("123", "mj"), Book("QA", "mj", 13));
	a.AddBook(Book("QA", "mj", 13));
	a.AddMember(Member("123", "mj"));
	a.RentBook(test);
	// �̹� �뿩�Ȱ� �� ������ error return
	EXPECT_CALL(a, SearchMemberByMember(test.getMember())).Times(1).WillOnce(Return(0));
	EXPECT_CALL(a, SearchBookByBook(test.getBook())).Times(1).WillOnce(Return(0));
	// �̹� �뿩���̴ϱ� true return �ؾ���
	EXPECT_CALL(a, IsRented(test)).Times(1).WillOnce(Return(true)); 
	bool is = a.RentBook(test);
	// already rented�� ����� �׸��� �̹� �뿩���̴ϱ� false return
	EXPECT_EQ(is, false);



}


/**
@brief Library Ŭ������ DeleteMember �Լ��� �׽�Ʈ �ϱ� ���� mocking class �Դϴ�.
*/
class Mock_Lib_Member_Delete : public Library
{
public:
	//DeleteMember(const Member& newMember)
	/**
	@brief DeleteMember �Լ��� mock_method �Դϴ�.
	*/
	MOCK_METHOD1(DeleteMember, bool(const Member& newMember));
	//MOCK_METHOD1(SearchMemberByMember, int(const Member& member));

};

/**
@brief DeleteMember �Լ��� ���������� ȣ��ǰ� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark �׽�Ʈ�� �����ؾ��մϴ�!
*/
TEST(Library_test, check_Delete_Member_success)
{

	Mock_Lib_Member_Delete a;
	Member test("010", "mj");
	Member test2("01011", "mj");
	a.AddMember(test2);
	EXPECT_CALL(a, DeleteMember(test2)).Times(1).WillOnce(Return(true));
	bool is = a.DeleteMember(test2);
	// ������ �����ϹǷ� true 
	EXPECT_EQ(is, true);


}

/**
@brief DeleteMember �Լ��� ���������� ȣ��ǰ� �۵��ϴ��� �׽�Ʈ�մϴ�.
@remark �׽�Ʈ�� �����ؾ��մϴ�!
*/
TEST(Library_test, check_Delete_Member_failure)
{

	Mock_Lib_Member_Delete a;
	Member test("010", "mj");
	EXPECT_CALL(a, DeleteMember(test)).Times(1).WillOnce(Return(false));
	bool is = a.DeleteMember(test);
	// ������ �����ϹǷ� true 
	EXPECT_EQ(is, false);


}


/**
@brief Library Ŭ������ SearchBookByBook �Լ��� �׽�Ʈ �ϱ� ���� mocking class �Դϴ�.
*/
class Mock_Library_Search_Book : public Library
{
public:
	//virtual int SearchMemberByMember(const Member& member);
	/**
	@brief SearchBookByBook �Լ��� mock_method �Դϴ�.
	*/
	MOCK_METHOD1(SearchBookByBook, int(const Book& member));
};

/**
@brief SearchBookByBook �Լ��� ���� �۵��ϴ��� �׽�Ʈ �մϴ�.
*/
TEST(Library_test, check_add_book)
{
	Mock_Library_Search_Book a;
	Book book("devops", "davinch", 1234);
	EXPECT_CALL(a, SearchBookByBook(book)).Times(1).WillOnce(Return(-1));
	a.AddBook(book);

}

/**
@brief SearchBookByBook �Լ��� ���� �۵��ϴ��� �׽�Ʈ �մϴ�.
@details ó���� -1, �׸��� 2��° ȣ�⿡�� index 0�� ��ȯ�ؾ��մϴ�.
*/
TEST(Library_test, check_add_book_index)
{
	Mock_Library_Search_Book a;
	Book book("devops", "davinch", 1234);
	EXPECT_CALL(a, SearchBookByBook(book)).Times(2).WillOnce(Return(-1)).WillOnce(Return(0));
	a.AddBook(book);
	a.AddBook(book);
}

/**
@brief Libray Ŭ������ PrintAllContents �Լ��� �׽�Ʈ�մϴ�.
*/
TEST(Libray_test, check_print_all_contents)
{
	Library lib;

	lib.AddMember(Member("123", "mj"));
	lib.AddMember(Member("1236", "ka"));
	lib.AddMember(Member("1234", "kaka"));

	lib.AddBook(Book("devops", "neo", 13));
	lib.AddBook(Book("c++ optimize", "mj", 13322));
	lib.AddBook(Book("modern c++ challenge", "bansilla", 1342));
	lib.PrintAllContents();


}

/**
@brief Libray Ŭ������ PrintAllMember �Լ��� �׽�Ʈ�մϴ�.
*/
TEST(Library_test, check_print_all_members)
{
	Library lib;

	lib.AddMember(Member("123", "mj"));
	lib.AddMember(Member("1236", "ka"));
	lib.AddMember(Member("1234", "kaka"));

	lib.AddBook(Book("devops", "neo", 13));
	lib.AddBook(Book("c++ optimize", "mj", 13322));
	lib.AddBook(Book("modern c++ challenge", "bansilla", 1342));

	RentInfo a("2020-10-30", Member("123", "mj"), Book("devops", "neo", 13));
	RentInfo c("2020-11-20", Member("1234", "kaka"), Book("c++ optimize", "mj", 13322));
	RentInfo b("2020-09-12", Member("123", "mj"), Book("modern c++ challenge", "bansilla", 1342));

	lib.RentBook(a);
	lib.RentBook(b);
	lib.RentBook(c);

	lib.PrintAllMember();
	lib.PrintAllContents();

}

/**
@brief Libray Ŭ������ PrintRentBook �Լ��� �׽�Ʈ�մϴ�.
*/
TEST(Library_test, check_print_all_rent)
{
	Library lib;

	lib.AddMember(Member("123", "mj"));
	lib.AddMember(Member("1236", "ka"));
	lib.AddMember(Member("1234", "kaka"));

	lib.AddBook(Book("devops", "neo", 13));
	lib.AddBook(Book("c++ optimize", "mj", 13322));
	lib.AddBook(Book("modern c++ challenge", "bansilla", 1342));

	RentInfo a("2020-10-30", Member("123", "mj"), Book("devops", "neo", 13));
	RentInfo c("2020-11-20", Member("1234", "kaka"), Book("c++ optimize", "mj", 13322));
	RentInfo b("2020-09-12", Member("123", "mj"), Book("modern c++ challenge", "bansilla", 1342));

	lib.RentBook(a);
	lib.RentBook(b);
	lib.RentBook(c);

	lib.PrintRentBook();


}


#ifdef ARDUINO
void setup() {
  // Since Google Mock depends on Google Test, InitGoogleMock() is
  // also responsible for initializing Google Test.  Therefore there's
  // no need for calling testing::InitGoogleTest() separately.
  testing::InitGoogleMock();
}
void loop() { RUN_ALL_TESTS(); }
#else

// MS C++ compiler/linker has a bug on Windows (not on Windows CE), which
// causes a link error when _tmain is defined in a static library and UNICODE
// is enabled. For this reason instead of _tmain, main function is used on
// Windows. See the following link to track the current status of this bug:
// https://web.archive.org/web/20170912203238/connect.microsoft.com/VisualStudio/feedback/details/394464/wmain-link-error-in-the-static-library
// // NOLINT
#if GTEST_OS_WINDOWS_MOBILE
# include <tchar.h>  // NOLINT

GTEST_API_ int _tmain(int argc, TCHAR** argv) {
#else
GTEST_API_ int main(int argc, char** argv) {
#endif  // GTEST_OS_WINDOWS_MOBILE
  std::cout << "Running main() from gmock_main.cc\n";
  // Since Google Mock depends on Google Test, InitGoogleMock() is
  // also responsible for initializing Google Test.  Therefore there's
  // no need for calling testing::InitGoogleTest() separately.
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
#endif
