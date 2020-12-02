#pragma once

/**
@file Library.h
@brieft ���� �˻� Library class�� ��������Դϴ�.
@remark RentInfo.h ��������� �����ؾ��մϴ�.
*/

#include "RentInfo.h"
#include <vector>
#include <map>
/**
@brief Library Ŭ���� �Դϴ�.
@author MJ
@date 2020-12-01
*/
class Library
{
public:
	/**
	@brief Library Ŭ������ �⺻ �������Դϴ�.
	*/
	Library() {}
	/**
	@brief Library Ŭ������ �Ҹ����Դϴ�. mock test�� ���� virtual�� �����Ͽ����ϴ�.
	*/
	virtual ~Library() {}
	/**
	@brief ���� �������� �ִ� ��� å���� ������ �����ִ� �Լ��Դϴ�.
	*/
	virtual void PrintAllContents();
	/**
	@brief ���� �������� ��ϵ� ��� ȸ������ ���� �� �뿩 ��Ȳ�� �����ִ� �Լ��Դϴ�.
	*/
	virtual void PrintAllMember();
	/**
	@brief ���� �뿩���� ��� å���� ����� �����ִ� �Լ��Դϴ�.
	*/
	virtual void PrintRentBook();
	/**
	@brief å�� �뿩������ Ȯ���� å�� ������ �Լ��Դϴ�.
	@param RentInfo Ŭ������ ���ڷ� �޽��ϴ�.
	@remark �������� å, ȸ�� ������ �����ؾ� �մϴ�. ���� �������� ������ false�� ��ȯ�մϴ�.
	@return å�� �̹� �뿩���̸� false�� ��ȯ�ϰ� �뿩�� �����ϸ� true�� ��ȯ�մϴ�.
	*/
	virtual bool RentBook(RentInfo& paramrentinfo);
	/**
	@brief ��� ������ �޾� ����� �߰��ϴ� �Լ��Դϴ�.
	@param Member Ŭ������ ���ڷ� �޽��ϴ�.
	@remark ����Ϸ��� ȸ�� ������ �̹� �����ϰų� ��ȭ��ȣ�� �ߺ��Ǹ� ��Ͽ� �����մϴ�.
	@return ��Ͽ� �����ϸ� true�� ��ȯ�ϰ� ���н� false�� ��ȯ�մϴ�.
	*/
	virtual bool AddMember(const Member& newMember);
	/**
	@brief ��� ������ �޾� �ش� ����� �����ϴ� �Լ��Դϴ�.
	@param Member Ŭ������ ���ڷ� �޽��ϴ�.
	@remark �����Ϸ��� ȸ�� ������ �����ؾ��մϴ�. �������� �ʴ� ȸ���� �����Ϸ��ҽ� �����մϴ�.
	@return ������ �����ϸ� true�� ��ȯ�ϰ� ���н� false�� ��ȯ�մϴ�.
	*/
	virtual bool DeleteMember(const Member& newMember);
	/**
	@brief å ������ �޾� �ش� å�� ���������� �߰��ϴ� �Լ��Դϴ�.
	@param Book Ŭ������ ���ڷ� �޽��ϴ�.
	@remark ����Ϸ��� �ش� å ������ ���� ���������� �������� �ʾƾ��մϴ�. �̹� ����� ��Ͽ� �����մϴ�.
	@return ��Ͽ� ������ true�� ��ȯ�ϰ� ���н� false�� ��ȯ�մϴ�.
	*/
	virtual bool AddBook(const Book& newMember);
	/**
	@brief å ������ �޾� �ش� å�� ������������ �����ϴ� �Լ��Դϴ�.
	@param Book Ŭ������ ���ڷ� �޽��ϴ�.
	@remark �����϶�� �ش� å ������ ���� ���������� �����ؾ��մϴ�. �������� ������ ������ �����մϴ�.
	@return ������ ������ true�� ��ȯ�ϰ� ���н� false�� ��ȯ�մϴ�.
	*/
	virtual bool DeleteBook(const Book& newMember);
	/**
	@brief ��Ʈ ������ �޾� �ش� å�� �뿩 �������� ��ȯ�ϴ� �Լ��Դϴ�.
	@param RentInfo Ŭ������ ���ڷ� �޽��ϴ�.
	@return �ش� ������ �뿩���̸� true�� �뿩������ ������ false�� ��ȯ�մϴ�.
	*/
	virtual bool IsRented(const RentInfo& paramrentinfo);
	/**
	@brief �۰� �̸� �Ǵ� å �̸����� å�� ���������� �����ϴ��� �˻��ϴ� �Լ��Դϴ�.
	@param key å �̸� �Ǵ� �۰� �̸��� ���ڷ� �޽��ϴ�.
	@return �ش� ������ �����ϸ� index�� ��ȯ�ϰ� �������� ������ -1�� ��ȯ�մϴ�.
	*/
	virtual int SearchBookByKey(const string& key);
	/**
	@brief �ش� �޴��� ��ȣ�� ���� ��������� �����ϴ��� �˻��ϴ� �Լ��Դϴ�.
	@param key �޴��� ��ȣ�Դϴ�.
	@return �ش� ����� �����ϸ� index�� ��ȯ�ϰ� �������� ������ -1�� ��ȯ�մϴ�.
	*/
	virtual int SearchMemberByKey(const string& key);
	/**
	@brief �ش� å ������ ���������� �����ϴ��� �˻��ϴ� �Լ��Դϴ�.
	@param Book Ŭ������ ���ڷ� �޽��ϴ�.
	@return �ش� ������ �����ϸ� index�� ��ȯ�ϰ� �������� ������ -1�� ��ȯ�մϴ�.
	*/
	virtual int SearchBookByBook(const Book& book);
	/**
	@brief �ش� ����� ��������� �����ϴ��� �˻��ϴ� �Լ��Դϴ�.
	@param Mmeber Ŭ������ ���ڷ� �޽��ϴ�.
	@return �ش� ����� �����ϸ� index�� ��ȯ�ϰ� �������� ������ -1�� ��ȯ�մϴ�.
	*/
	virtual int SearchMemberByMember(const Member& member);
private:
	/**
	@brief Library Ŭ������ ��� �����Դϴ�.
	@param bookinfo ���������� �ǹ��ϴ� �����Դϴ�.
	@param memberinfo ��������� �ǹ��ϴ� �����Դϴ�.
	@param rentinfo �뿩������ �ǹ��ϴ� �����Դϴ�.
	@param numOfBook �ش� ������ �� ������� �����ϱ� ���� �����Դϴ�.
	
	*/
	vector<Book> bookinfo;
	vector<Member> memberinfo;
	vector<RentInfo> rentinfo;
	map<Book, int> numOfBook;
};