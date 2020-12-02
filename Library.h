#pragma once

/**
@file Library.h
@brieft 도서 검색 Library class의 헤더파일입니다.
@remark RentInfo.h 헤더파일을 포함해야합니다.
*/

#include "RentInfo.h"
#include <vector>
#include <map>
/**
@brief Library 클래스 입니다.
@author MJ
@date 2020-12-01
*/
class Library
{
public:
	/**
	@brief Library 클래스의 기본 생성자입니다.
	*/
	Library() {}
	/**
	@brief Library 클래스의 소멸자입니다. mock test를 위해 virtual로 선언하였습니다.
	*/
	virtual ~Library() {}
	/**
	@brief 현재 도서관에 있는 모든 책들의 정보를 보여주는 함수입니다.
	*/
	virtual void PrintAllContents();
	/**
	@brief 현재 도서관에 등록된 모든 회원들의 정보 및 대여 현황을 보여주는 함수입니다.
	*/
	virtual void PrintAllMember();
	/**
	@brief 현재 대여중인 모든 책들의 목록을 보여주는 함수입니다.
	*/
	virtual void PrintRentBook();
	/**
	@brief 책이 대여중인지 확인후 책을 빌리는 함수입니다.
	@param RentInfo 클래스를 인자로 받습니다.
	@remark 빌리려는 책, 회원 정보가 존재해야 합니다. 만약 존재하지 않을시 false를 반환합니다.
	@return 책이 이미 대여중이면 false를 반환하고 대여에 성공하면 true를 반환합니다.
	*/
	virtual bool RentBook(RentInfo& paramrentinfo);
	/**
	@brief 멤버 정보를 받아 멤버를 추가하는 함수입니다.
	@param Member 클래스를 인자로 받습니다.
	@remark 등록하려면 회원 정보가 이미 존재하거나 전화번호가 중복되면 등록에 실패합니다.
	@return 등록에 성공하면 true를 반환하고 실패시 false를 반환합니다.
	*/
	virtual bool AddMember(const Member& newMember);
	/**
	@brief 멤버 정보를 받아 해당 멤버를 삭제하는 함수입니다.
	@param Member 클래스를 인자로 받습니다.
	@remark 삭제하려면 회원 정보가 존재해야합니다. 존재하지 않는 회원을 삭제하려할시 실패합니다.
	@return 삭제에 성공하면 true를 반환하고 실패시 false를 반환합니다.
	*/
	virtual bool DeleteMember(const Member& newMember);
	/**
	@brief 책 정보를 받아 해당 책을 도서정보에 추가하는 함수입니다.
	@param Book 클래스를 인자로 받습니다.
	@remark 등록하려면 해당 책 정보가 기존 도서정보에 존재하지 않아야합니다. 이미 존재시 등록에 실패합니다.
	@return 등록에 성공시 true를 반환하고 실패시 false를 반환합니다.
	*/
	virtual bool AddBook(const Book& newMember);
	/**
	@brief 책 정보를 받아 해당 책을 도서정보에서 삭제하는 함수입니다.
	@param Book 클래스를 인자로 받습니다.
	@remark 삭제하라면 해당 책 정보가 기존 도서정보에 존재해야합니다. 존재하지 않을시 삭제에 실패합니다.
	@return 삭제에 성공시 true를 반환하고 실패시 false를 반환합니다.
	*/
	virtual bool DeleteBook(const Book& newMember);
	/**
	@brief 렌트 정보를 받아 해당 책을 대여 가능한지 반환하는 함수입니다.
	@param RentInfo 클래스를 인자로 받습니다.
	@return 해당 도서가 대여중이면 true를 대여중이지 않으면 false를 반환합니다.
	*/
	virtual bool IsRented(const RentInfo& paramrentinfo);
	/**
	@brief 작가 이름 또는 책 이름으로 책이 도서정보에 존재하는지 검색하는 함수입니다.
	@param key 책 이름 또는 작가 이름을 인자로 받습니다.
	@return 해당 도서가 존재하면 index를 반환하고 존재하지 않을시 -1을 반환합니다.
	*/
	virtual int SearchBookByKey(const string& key);
	/**
	@brief 해당 휴대폰 번호를 가진 멤버정보가 존재하는지 검색하는 함수입니다.
	@param key 휴대폰 번호입니다.
	@return 해당 멤버가 존재하면 index를 반환하고 존재하지 않을시 -1을 반환합니다.
	*/
	virtual int SearchMemberByKey(const string& key);
	/**
	@brief 해당 책 정보가 도서정보에 존재하는지 검색하는 함수입니다.
	@param Book 클래스를 인자로 받습니다.
	@return 해당 도서가 존재하면 index를 반환하고 존재하지 않을시 -1을 반환합니다.
	*/
	virtual int SearchBookByBook(const Book& book);
	/**
	@brief 해당 멤버가 멤버정보에 존재하는지 검색하는 함수입니다.
	@param Mmeber 클래스를 인자로 받습니다.
	@return 해당 멤버가 존재하면 index를 반환하고 존재하지 않을시 -1을 반환합니다.
	*/
	virtual int SearchMemberByMember(const Member& member);
private:
	/**
	@brief Library 클래스의 멤버 변수입니다.
	@param bookinfo 도서정보를 의미하는 변수입니다.
	@param memberinfo 멤버정보를 의미하는 변수입니다.
	@param rentinfo 대여정보를 의미하는 변수입니다.
	@param numOfBook 해당 도서가 총 몇권인지 저장하기 위한 변수입니다.
	
	*/
	vector<Book> bookinfo;
	vector<Member> memberinfo;
	vector<RentInfo> rentinfo;
	map<Book, int> numOfBook;
};