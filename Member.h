#pragma once


/**
@file Member.h
*/

#include <string>

using namespace std;

/**
@brief Member Ŭ�����Դϴ�.
@author MJ
@date 2020-12-01

*/
class Member
{
public:
	/**
	@brief Member Ŭ������ �⺻ �������Դϴ�.
	*/
	Member() {};
	/**
	@brief Member Ŭ������ ���� �������Դϴ�. �ڵ��� ��ȣ, �̸��� �Է� �޾� �����˴ϴ�.
	@param _phone : �ڵ��� ��ȣ�Դϴ�.
	@param _name : ��� �̸��Դϴ�.
	*/
	Member(string _phone, string _name)
		:phone(_phone), name(_name)
	{

	}
	/**
	@brief Member �Լ��� �Ҹ��� �Դϴ�. mock test�� ���� virtual�� �����Ͽ����ϴ�.
	*/
	virtual ~Member() {}
	/**
	@brief ����� �̸��� ��ȯ�ϴ� �Լ��Դϴ�.
	@return name
	*/
	virtual string getName() const;
	/**
	@brief ����� �ڵ��� ��ȣ�� ��ȯ�ϴ� �Լ��Դϴ�.
	@return phone
	*/
	virtual string getPhoneNumber() const;
	/**
	@brief operator overloading�Դϴ�. ����� equality �񱳸� ���� ���˴ϴ�.
	*/
	virtual bool operator==(const Member& left) const;
	/**
	@brief mocking class���� getName�Լ��� test�ϱ� ���� ���Ǵ� �Լ��Դϴ�.
	*/
	virtual void setName(string name);
	/**
	@brief mocking class���� getPhoneNumber�Լ��� test�ϱ� ���� ���Ǵ� �Լ��Դϴ�.
	*/
	virtual void setPhone(string phone);


private:
	/**
	@param name Member Ŭ������ ��� �����Դϴ�.
	@param phone Member Ŭ������ ��� �����Դϴ�.
	*/
	string name;
	string phone;
};