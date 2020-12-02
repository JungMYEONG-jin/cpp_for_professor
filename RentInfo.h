#pragma once


/**
@file RentInfo.h
@brief RentInfo 클래스 헤더파일입니다.
@remark Book.h Member.h 헤더파일을 포함해야합니다.
*/

#include "Book.h"
#include "Member.h"
/**
@brief RentInfo 클래스입니다.
@author MJ
@date 2020-12-01
*/

class RentInfo
{
public:
	/**
	@brief RentInfo 클래스의 기본 생성자입니다.
	*/
	RentInfo() {}
	/**
	@brief RentInfo 클래스의 지정 생성자입니다. 반납날짜, 멤버, 책 정보를 받아 생성됩니다.
	@param _date 반납날짜입니다.
	@param _member 멤버 정보입니다.
	@param _book 책 정보입니다.
	*/

	RentInfo(const string& _date, const Member& _member, const Book& _book)
		:date(_date), member(_member), book(_book)
	{

	}
	/**
	@brief RentInfo 클래스의 소멸자입니다. mock test를 위해 virtual로 선언하였습니다.
	*/
	virtual ~RentInfo() {}
	/**
	@brief 반납날짜를 반환하는 함수입니다.
	@return date 
	*/
	virtual string getDate() const;
	/**
	@brief Member 변수를 반환하는 함수입니다.
	@return member
	*/
	virtual const Member& getMember() const;
	/**
	@brief Book 변수를 반환하는 함수입니다.
	@return book
	*/
	virtual const Book& getBook() const;
	/**
	@brief operator overloading입니다
	*/
	virtual bool operator==(const RentInfo& left) const;
	/**
	@brief 렌트 대여 여부를 반환하는 함수입니다.
	@return IsRented
	*/
	virtual bool rent_stat() const;
	virtual void set_rent();

	/**
	@brief mocking class에서 getDate 함수를 테스트하기 위해 사용되는 함수입니다.
	*/
	virtual void setDate(string date);
	/**
	@brief mocking class에서 getMember 함수를 테스트하기 위해 사용되는 함수입니다.
	*/
	virtual void setMember(Member& member);
	/**
	@brief mocking class 에서 getBook 함수를 테스트하기 위해 사용되는 함수입니다.
	*/
	virtual void setBook(Book& book);



private:
	/**
	@param date 반납날짜를 의미하는 RentInfo의 멤버변수입니다.
	@param member 멤버 정보를 의미하는 RentInfo의 멤버변수입니다.
	@param book 책 정보를 의미하는 RentInfo의 멤버변수입니다.
	@param IsRented 대여 여부를 의미하는 RentInfo의 멤버변수입니다.
	*/
	string date;
	Member member;
	Book book;
	bool IsRented;
};