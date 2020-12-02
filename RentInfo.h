#pragma once


/**
@file RentInfo.h
@brief RentInfo Ŭ���� ��������Դϴ�.
@remark Book.h Member.h ��������� �����ؾ��մϴ�.
*/

#include "Book.h"
#include "Member.h"
/**
@brief RentInfo Ŭ�����Դϴ�.
@author MJ
@date 2020-12-01
*/

class RentInfo
{
public:
	/**
	@brief RentInfo Ŭ������ �⺻ �������Դϴ�.
	*/
	RentInfo() {}
	/**
	@brief RentInfo Ŭ������ ���� �������Դϴ�. �ݳ���¥, ���, å ������ �޾� �����˴ϴ�.
	@param _date �ݳ���¥�Դϴ�.
	@param _member ��� �����Դϴ�.
	@param _book å �����Դϴ�.
	*/

	RentInfo(const string& _date, const Member& _member, const Book& _book)
		:date(_date), member(_member), book(_book)
	{

	}
	/**
	@brief RentInfo Ŭ������ �Ҹ����Դϴ�. mock test�� ���� virtual�� �����Ͽ����ϴ�.
	*/
	virtual ~RentInfo() {}
	/**
	@brief �ݳ���¥�� ��ȯ�ϴ� �Լ��Դϴ�.
	@return date 
	*/
	virtual string getDate() const;
	/**
	@brief Member ������ ��ȯ�ϴ� �Լ��Դϴ�.
	@return member
	*/
	virtual const Member& getMember() const;
	/**
	@brief Book ������ ��ȯ�ϴ� �Լ��Դϴ�.
	@return book
	*/
	virtual const Book& getBook() const;
	/**
	@brief operator overloading�Դϴ�
	*/
	virtual bool operator==(const RentInfo& left) const;
	/**
	@brief ��Ʈ �뿩 ���θ� ��ȯ�ϴ� �Լ��Դϴ�.
	@return IsRented
	*/
	virtual bool rent_stat() const;
	virtual void set_rent();

	/**
	@brief mocking class���� getDate �Լ��� �׽�Ʈ�ϱ� ���� ���Ǵ� �Լ��Դϴ�.
	*/
	virtual void setDate(string date);
	/**
	@brief mocking class���� getMember �Լ��� �׽�Ʈ�ϱ� ���� ���Ǵ� �Լ��Դϴ�.
	*/
	virtual void setMember(Member& member);
	/**
	@brief mocking class ���� getBook �Լ��� �׽�Ʈ�ϱ� ���� ���Ǵ� �Լ��Դϴ�.
	*/
	virtual void setBook(Book& book);



private:
	/**
	@param date �ݳ���¥�� �ǹ��ϴ� RentInfo�� ��������Դϴ�.
	@param member ��� ������ �ǹ��ϴ� RentInfo�� ��������Դϴ�.
	@param book å ������ �ǹ��ϴ� RentInfo�� ��������Դϴ�.
	@param IsRented �뿩 ���θ� �ǹ��ϴ� RentInfo�� ��������Դϴ�.
	*/
	string date;
	Member member;
	Book book;
	bool IsRented;
};