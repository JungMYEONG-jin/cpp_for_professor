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
@brief Library시스템의 Mock Test 파일입니다.

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
@brief Book 클래스의 mock test를 위한 mocking class입니다.
*/
class MockBook : public Book
{ 
public:
	
	
	/**
	@brief get_book_name이 정상 작동하는지 테스틀 위한 mock_method입니다.
	*/
	MOCK_CONST_METHOD0(get_book_name, string());
	/**
	@brief get_writer_name이 정상 작동하는지 테스틀 위한 mock_method입니다.
	*/
	MOCK_CONST_METHOD0(get_writer_name, string());
	/**
	@brief get_id가 정상 작동하는지 테스틀 위한 mock_method입니다.
	*/
	MOCK_CONST_METHOD0(get_id, unsigned int());
	virtual bool operator<(const MockBook& left) const
	{
		return get_id() < left.get_id();
	}

};

/**
@brief MockBook 멤버 함수를 호출하기 위한 class 입니다.
*/
class Test_Mock_Book
{
	/**
	@brief MockBook class의 함수를 호출하기 위해 Book class를 멤버 변수로 갖습니다.
	*/
	Book& book;
public:
	/**
	@brief 지정 생성자입니다.
	@param Book reference를 인자로 받습니다.	
	*/
	Test_Mock_Book(Book& tbook)
		:book(tbook)
	{


	}
	/**
	@brief get_book_name 함수를 호출하기 위한 함수입니다.
	@param name : string형 변수입니다. 책 이름을 의미합니다.
	@return 멤버 변수 book의 책 이름을 반환합니다.
	*/
	string init_book_name(string name)
	{
		book.set_name(name);
		return book.get_book_name();
	}
	/**
	@brief get_writer_name 함수를 호출하기 위한 함수입니다.
	@param name : string형 변수입니다. 작가 이름을 의미합니다.
	@return 멤버 변수 book의 작가 이름을 반환합니다.
	*/
	string init_writer_name(string name)
	{
		book.set_writer(name);
		return book.get_writer_name();
	}
	/**
	@brief get_id 함수를 호출하기 위한 함수입니다.
	@param id : unsigned int형 변수입니다. 책 id를 의미합니다.
	@return 멤버 변수 book의 책 id를 반환합니다.
	*/
	unsigned int init_id(unsigned int id)
	{
		book.set_id(id);
		return book.get_id();
	}

};

/**
@brief Book 클래스의 equality를 체크하는 테스트입니다.
@details operator== 의 overlodaing이 정상적으로 작동하여 true를 반환하는지 테스트합니다.
*/
TEST(book_test, check_equality_true)
{
	// mock 클래스로 생성자 비교는 불가능해보임
	// 만들어진 즉시 소멸 - > default 무조건 같게됨
	Book a("mj", "devs", 123);
	Book b("mj", "devs", 1234);
	// map에 같은 책을 저장하기 위해 book operator==은 책이름 작가이름이 같으면 같은 책으로 정의하였음.
	bool is = (a == b);

	EXPECT_EQ(is, true);


}
/**
@brief Book 클래스의 equality를 체크하는 테스트입니다.
@details operator== 의 overlodaing이 정상적으로 작동하여 false를 반환하는지 테스트합니다.
*/
TEST(book_test, check_equality_false)
{
	Book a("명진", "devs", 123);
	Book b("mj", "devs", 1234);
	bool is = (a == b);

	EXPECT_EQ(is, false);

}
/**
@brief Book 클래스의 get_book_name을 테스트 합니다.
@details MockBook, Test_Mock_Book class를 이용해 Book class의 get_book_name이 정상적으로 작동하는지 테스트합니다.
@remark true case 이므로 테스트에 통과해야합니다!
*/
TEST(book_test, check_get_name_success)
{
	MockBook a;
	Test_Mock_Book my(a);

	EXPECT_CALL(a, get_book_name()).Times(1).WillOnce(Return("명진"));
	auto val = my.init_book_name("명진");

	EXPECT_EQ(val, "명진");


}
/**
@brief Book 클래스의 get_book_name을 테스트 합니다.
@details MockBook, Test_Mock_Book class를 이용해 Book class의 get_book_name이 정상적으로 작동하는지 테스트합니다.
@remark 일부러 틀린 값을 줬습니다. 테스트 시 실패해야합니다!
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
@brief Book 클래스의 get_writer_name을 테스트 합니다.
@details MockBook, Test_Mock_Book class를 이용해 Book class의 get_writer_name이 정상적으로 작동하는지 테스트합니다.
@remark true case 이므로 테스트에 통과해야합니다!
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
@brief Book 클래스의 get_writer_name을 테스트 합니다.
@details MockBook, Test_Mock_Book class를 이용해 Book class의 get_writer_name이 정상적으로 작동하는지 테스트합니다.
@remark 일부러 틀린 값을 줬습니다. 테스트 시 실패해야합니다!
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
@brief Book 클래스의 get_id를 테스트 합니다.
@details MockBook, Test_Mock_Book class를 이용해 Book class의 get_id가 정상적으로 작동하는지 테스트합니다.
@remark true case 이므로 테스트에 통과해야합니다!
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
@brief Book 클래스의 get_id를 테스트 합니다.
@details MockBook, Test_Mock_Book class를 이용해 Book class의 get_id가 정상적으로 작동하는지 테스트합니다.
@remark 일부러 틀린 값을 줬습니다. 테스트 시 실패해야합니다!
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
@brief Member 클래스의 equality 테스트입니다.
@remark true case 이므로 테스트에 통과해야합니다!
*/
TEST(member_test, check_equality)
{
	Member a("010", "mj");
	Member b("010", "mj");

	bool is = a == b;
	EXPECT_EQ(is, true);


}

/**
@brief Member 클래스의 equality 테스트입니다.
@remark 일부러 틀린 값을 줬습니다. 테스트 시 실패해야합니다!
*/
TEST(member_test, check_equality_failure)
{
	Member a("010", "mj");
	Member c("02912", "kmg");

	bool is = a == c;
	EXPECT_EQ(is, false);

}

/**
@brief Member 클래스의 mock test를 위한 mocking class입니다.
*/

class MockMbember : public Member
{

public:
	/**
	@brief getName 함수를 테스트할 mock_method 입니다.
	*/
	MOCK_CONST_METHOD0(getName, string());
	/**
	@brief getPhoneNumber 함수를 테스트할 mock_method 입니다.
	*/
	MOCK_CONST_METHOD0(getPhoneNumber, string());


};

/**
@brief Member 클래스의 mocking class가 정상적으로 함수를 호출하는지 테스트할 클래스입니다.
*/
class Test_MockMember
{
	/**
	@brief Member class reference를 멤버 변수로 갖습니다.
	*/
	Member& mem;
public:
	/**
	@brief 클래스의 지정 생성자입니다.
	@param Member reference를 인자로 받습니다.
	*/
	Test_MockMember(Member& _mem)
		:mem(_mem)
	{

	}
	/**
	@brief getName함수가 정상적으로 작동하는지 확인하기 위한 함수입니다.
	@param name : string형 변수입니다. 멤버 이름을 의미합니다.
	@return 멤버 변수 mem의 getName을 호출합니다.
	*/
	string initName(string name)
	{
		mem.setName(name);
		return mem.getName();
	}
	/**
	@brief getPhoneNumber함수가 정상적으로 작동하는지 확인하기 위한 함수입니다.
	@param name : string형 변수입니다. 휴대폰 번호를 의미합니다.
	@return 멤버 변수 mem의 getPhoneNumber을 호출합니다.
	*/
	string initPhone(string phone)
	{
		mem.setPhone(phone);
		return mem.getPhoneNumber();
	}

};
/**
@brief Member 클래스의 getName을 테스트 합니다.
@details MockMbember, Test_MockMember class를 이용해 Member 클래스의 getName이 정상적으로 작동하는지 테스트합니다.
@remark true case 이므로 테스트에 통과해야합니다!
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
@brief Member 클래스의 getName을 테스트 합니다.
@details MockMbember, Test_MockMember class를 이용해 Member 클래스의 getName이 정상적으로 작동하는지 테스트합니다.
@remark 일부러 틀린 값을 줬습니다. 테스트 시 실패해야합니다!
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
@brief Member 클래스의 getPhoneNumber을 테스트 합니다.
@details MockMbember, Test_MockMember class를 이용해 Member 클래스의 getPhoneNumber가 정상적으로 작동하는지 테스트합니다.
@remark true case 이므로 테스트에 통과해야합니다!
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
@brief Member 클래스의 getPhoneNumber을 테스트 합니다.
@details MockMbember, Test_MockMember class를 이용해 Member 클래스의 getPhoneNumber가 정상적으로 작동하는지 테스트합니다.
@remark 일부러 틀린 값을 줬습니다. 테스트 시 실패해야합니다!
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
@brief RentInfo 클래스의 equality 테스트입니다.
@remark true case 이므로 테스트에 통과해야합니다!
*/
TEST(rentinfo_test, check_equality_success)
{
	RentInfo a("2020-11-27", Member("010", "mj"), Book("devbook", "davinch", 123));
	RentInfo b("2020-11-27", Member("010", "mj"), Book("devbook", "davinch", 123));
	bool is = a == b;
	EXPECT_EQ(is, true);
}

/**
@brief RentInfo 클래스의 equality 테스트입니다.
@remark 일부러 틀린 값을 줬습니다. 테스트 시 실패해야합니다!
*/
TEST(rentinfo_test, check_equality_failure)
{
	RentInfo a("2020-11-27", Member("010", "mj"), Book("devbook", "davinch", 123));
	RentInfo b("2020-11-27", Member("010", "mj"), Book("devbook", "davinch", 1234));
	bool is = a == b;
	EXPECT_EQ(is, true);
}
/**
@brief RentInfo 클래스의 mock test를 위한 mocking class입니다.
*/
class Mock_Rent : public RentInfo
{
public:
	/**
	@brief getDate의 테스트를 위한 mock_method 입니다.
	*/
	MOCK_CONST_METHOD0(getDate, string() );
	/**
	@brief getMember의 테스트를 위한 mock_method 입니다.
	*/
	MOCK_CONST_METHOD0(getMember, const Member& ());
	/**
	@brief getBook의 테스트를 위한 mock_method 입니다.
	*/
	MOCK_CONST_METHOD0(getBook, const Book& ());
};

/**
@brief RentInfo 클래스의 mocking class가 정상적으로 함수를 호출하는지 테스트할 클래스입니다.
*/
class Test_Mock_Rent
{
	/**
	@brief RentInfo reference를 멤버 변수로 갖습니다.
	*/
	RentInfo& rent;
public:
	/**
	@brief 지정 생성자입니다.
	@param RentInfo reference를 인자로 받습니다.
	*/
	Test_Mock_Rent(RentInfo& _rent)
		:rent(_rent)
	{

	}
	/**
	@brief getMember 함수가 정상적으로 호출되는지 확인하기 위한 함수입니다.
	@return getMember 함수를 호출합니다.
	*/
	Member init_member(Member& mem)
	{
		rent.setMember(mem);
		return rent.getMember();
	}

	/**
	@brief getBook 함수가 정상적으로 호출되는지 확인하기 위한 함수입니다.
	@return getBook 함수를 호출합니다.
	*/
	Book init_book(Book& book)
	{
		rent.setBook(book);
		return rent.getBook();
	}

	/**
	@brief getDate 함수가 정상적으로 호출되는지 확인하기 위한 함수입니다.
	@return getDate 함수를 호출합니다.
	*/
	string init_date(string date)
	{
		rent.setDate(date);
		return rent.getDate();
	}

};



/**
@brief RentInfo 클래스의 getDate를 테스트 합니다.
@details Mock_Rent, Test_Mock_Rent class를 이용해 RentInfo 클래스의 getDate가 정상적으로 작동하는지 테스트합니다.
@remark true case 이므로 테스트에 통과해야합니다!
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
@brief RentInfo 클래스의 getDate를 테스트 합니다.
@details Mock_Rent, Test_Mock_Rent class를 이용해 RentInfo 클래스의 getDate가 정상적으로 작동하는지 테스트합니다.
@remark 일부러 틀린 값을 줬습니다. 테스트 시 실패해야합니다!
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
@brief RentInfo 클래스의 getMember를 테스트 합니다.
@details Mock_Rent, Test_Mock_Rent class를 이용해 RentInfo 클래스의 getMember가 정상적으로 작동하는지 테스트합니다.
@remark true case 이므로 테스트에 통과해야합니다!
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
@brief RentInfo 클래스의 getMember 함수를 테스트 합니다.
@details Mock_Rent, Test_Mock_Rent class를 이용해 RentInfo 클래스의 getMember 함수가 정상적으로 작동하는지 테스트합니다.
@remark 일부러 틀린 값을 줬습니다. 테스트 시 실패해야합니다!
*/
TEST(rentinfo_test, check_get_member_failure)
{
	Mock_Rent a;
	Test_Mock_Rent my(a);
	Member test("010", "mj");
	Member test2("12345", "kari");
	EXPECT_CALL(a, getMember()).Times(1).WillOnce(ReturnRef(test2));
	// 실패시 메모리 주소가 지정됨
	// 어느 부분이 틀렸는지만 지정할수있을까?

	auto mem = my.init_member(test);

	EXPECT_EQ(mem, test);


}

/**
@brief RentInfo 클래스의 getBook 함수를 테스트 합니다.
@details Mock_Rent, Test_Mock_Rent class를 이용해 RentInfo 클래스의 getBook 함수가 정상적으로 작동하는지 테스트합니다.
@remark true case 이므로 테스트에 통과해야합니다!
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
@brief RentInfo 클래스의 getBook 함수를 테스트 합니다.
@details Mock_Rent, Test_Mock_Rent class를 이용해 RentInfo 클래스의 getBook 함수가 정상적으로 작동하는지 테스트합니다.
@remark 일부러 틀린 값을 줬습니다. 테스트 시 실패해야합니다!
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
@brief Library 클래스의 SearchMemberByMember 함수가 정상 작동하는지 테스트 하기 위한 mocking class 입니다.
*/
class Mock_Library_Search : public Library
{
public:
	//virtual int SearchMemberByMember(const Member& member);
	/**
	@brief SearchMemberByMember의 mock_method 입니다.
	*/
	MOCK_METHOD1(SearchMemberByMember, int (const Member& member));
};

/**
@details mocking class에서 AddMember를 호출합니다. AddMember 호출시 SearchMemberByMember 함수가 정상적으로 호출되는지 테스트합니다.
@remark 정상 작동하므로 올바른 값을 반환해야합니다. 처음 멤버 검색 시 해당 멤버가 존재하지 않으므로 -1을 반환합니다.
*/
TEST(Library_test, check_add_member)
{
	Mock_Library_Search a;
	Member test("010", "mj");
	EXPECT_CALL(a, SearchMemberByMember(test)).Times(1).WillOnce(Return(-1));
	a.AddMember(test);

}

/**
@details mocking class에서 AddMember를 호출합니다. AddMember 호출시 SearchMemberByMember 함수가 정상적으로 호출되는지 테스트합니다.
@remark 정상 작동하므로 올바른 값을 반환해야합니다. 처음 멤버 검색시 해당 멤버가 존재하지 않으므로 -1을 반환하고 그 후에는 index를 반환합니다.
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
@details mocking class에서 SearchMemberByMember 함수가 정상적으로 호출되는지 테스트합니다.
@remark 정상 작동하므로 올바른 값을 반환해야합니다.
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
@details mocking class에서 SearchMemberByMember 함수가 정상적으로 호출되는지 테스트합니다.
@remark 일부러 틀린 값을 줬습니다. 테스트에 실패해야 합니다!
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
@brief Library class의 RentBook 함수를 테스트 하기 위한 mocking class 입니다.
*/
class Mock_Library_rent : public Library
{
public:
	/**
	@brief RentBook 함수 테스트에 호출되는 SearchMemberByMember을 테스트 하기 위한 mock_method 입니다.
	*/
	MOCK_METHOD1(SearchMemberByMember, int(const Member& member));
	/**
	@brief RentBook 함수 테스트에 호출되는 SearchBookByBook을 테스트 하기 위한 mock_method 입니다.
	*/
	MOCK_METHOD1(SearchBookByBook, int(const Book& book));
	/**
	@brief RentBook 함수 테스트에 호출되는 IsRented를 테스트 하기 위한 mock_method 입니다.
	*/
	MOCK_METHOD1(IsRented, bool(const RentInfo& rent));

};

/**
@brief RentBook시 mock test를 하여 mock_method가 정상적으로 호출되는지 테스트합니다.
@details SearchMemberByMember, SearchBookByBook, IsRented가 호출되는지 확인합니다.
@remark 테스트에 성공해야합니다!
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
	// 대여에 성공함
	EXPECT_EQ(is, true);

}

/**
@brief RentBook시 mock test를 하여 mock_method가 정상적으로 호출되는지 테스트합니다.
@details SearchMemberByMember, SearchBookByBook, IsRented가 호출되는지 확인합니다.
@remark 테스트에 실패해야합니다!
*/
TEST(Library_test, check_Rent_book_failure)
{
	Mock_Library_rent a;
	RentInfo test("2020-10-20", Member("123", "mj"), Book("QA", "mj", 13));
	a.AddBook(Book("QA", "mj", 13));
	a.AddMember(Member("123", "mj"));
	a.RentBook(test);
	// 이미 대여된걸 또 빌리면 error return
	EXPECT_CALL(a, SearchMemberByMember(test.getMember())).Times(1).WillOnce(Return(0));
	EXPECT_CALL(a, SearchBookByBook(test.getBook())).Times(1).WillOnce(Return(0));
	// 이미 대여중이니까 true return 해야함
	EXPECT_CALL(a, IsRented(test)).Times(1).WillOnce(Return(true)); 
	bool is = a.RentBook(test);
	// already rented가 뜰것임 그리고 이미 대여중이니까 false return
	EXPECT_EQ(is, false);



}


/**
@brief Library 클래스의 DeleteMember 함수를 테스트 하기 위한 mocking class 입니다.
*/
class Mock_Lib_Member_Delete : public Library
{
public:
	//DeleteMember(const Member& newMember)
	/**
	@brief DeleteMember 함수의 mock_method 입니다.
	*/
	MOCK_METHOD1(DeleteMember, bool(const Member& newMember));
	//MOCK_METHOD1(SearchMemberByMember, int(const Member& member));

};

/**
@brief DeleteMember 함수가 정상적으로 호출되고 작동하는지 테스트합니다.
@remark 테스트에 성공해야합니다!
*/
TEST(Library_test, check_Delete_Member_success)
{

	Mock_Lib_Member_Delete a;
	Member test("010", "mj");
	Member test2("01011", "mj");
	a.AddMember(test2);
	EXPECT_CALL(a, DeleteMember(test2)).Times(1).WillOnce(Return(true));
	bool is = a.DeleteMember(test2);
	// 삭제에 성공하므로 true 
	EXPECT_EQ(is, true);


}

/**
@brief DeleteMember 함수가 정상적으로 호출되고 작동하는지 테스트합니다.
@remark 테스트에 실패해야합니다!
*/
TEST(Library_test, check_Delete_Member_failure)
{

	Mock_Lib_Member_Delete a;
	Member test("010", "mj");
	EXPECT_CALL(a, DeleteMember(test)).Times(1).WillOnce(Return(false));
	bool is = a.DeleteMember(test);
	// 삭제에 성공하므로 true 
	EXPECT_EQ(is, false);


}


/**
@brief Library 클래스의 SearchBookByBook 함수를 테스트 하기 위한 mocking class 입니다.
*/
class Mock_Library_Search_Book : public Library
{
public:
	//virtual int SearchMemberByMember(const Member& member);
	/**
	@brief SearchBookByBook 함수의 mock_method 입니다.
	*/
	MOCK_METHOD1(SearchBookByBook, int(const Book& member));
};

/**
@brief SearchBookByBook 함수가 정상 작동하는지 테스트 합니다.
*/
TEST(Library_test, check_add_book)
{
	Mock_Library_Search_Book a;
	Book book("devops", "davinch", 1234);
	EXPECT_CALL(a, SearchBookByBook(book)).Times(1).WillOnce(Return(-1));
	a.AddBook(book);

}

/**
@brief SearchBookByBook 함수가 정상 작동하는지 테스트 합니다.
@details 처음은 -1, 그리고 2번째 호출에는 index 0을 반환해야합니다.
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
@brief Libray 클래스의 PrintAllContents 함수를 테스트합니다.
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
@brief Libray 클래스의 PrintAllMember 함수를 테스트합니다.
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
@brief Libray 클래스의 PrintRentBook 함수를 테스트합니다.
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
