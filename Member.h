#pragma once


/**
@file Member.h
*/

#include <string>

using namespace std;

/**
@brief Member 클래스입니다.
@author MJ
@date 2020-12-01

*/
class Member
{
public:
	/**
	@brief Member 클래스의 기본 생성자입니다.
	*/
	Member() {};
	/**
	@brief Member 클래스의 지정 생성자입니다. 핸드폰 번호, 이름을 입력 받아 생성됩니다.
	@param _phone : 핸드폰 번호입니다.
	@param _name : 멤버 이름입니다.
	*/
	Member(string _phone, string _name)
		:phone(_phone), name(_name)
	{

	}
	/**
	@brief Member 함수의 소멸자 입니다. mock test를 위해 virtual로 선언하였습니다.
	*/
	virtual ~Member() {}
	/**
	@brief 멤버의 이름을 반환하는 함수입니다.
	@return name
	*/
	virtual string getName() const;
	/**
	@brief 멤버의 핸드폰 번호를 반환하는 함수입니다.
	@return phone
	*/
	virtual string getPhoneNumber() const;
	/**
	@brief operator overloading입니다. 멤버간 equality 비교를 위해 사용됩니다.
	*/
	virtual bool operator==(const Member& left) const;
	/**
	@brief mocking class에서 getName함수를 test하기 위해 사용되는 함수입니다.
	*/
	virtual void setName(string name);
	/**
	@brief mocking class에서 getPhoneNumber함수를 test하기 위해 사용되는 함수입니다.
	*/
	virtual void setPhone(string phone);


private:
	/**
	@param name Member 클래스의 멤버 변수입니다.
	@param phone Member 클래스의 멤버 변수입니다.
	*/
	string name;
	string phone;
};