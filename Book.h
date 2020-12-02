#pragma once



/**
@file Book.h


*/


#include <string>
using namespace std;
/**
@brief Book class입니다.
@author MJ
@date 2020-12-01
*/
class Book
{

public:
	/**
	@brief 기본 생성자입니다.
	
	*/
	Book() {}
	/**
	@brief 지정 생성자 입니다. 책이름, 작가이름, 책 id를 인수로 받습니다.
	@param _name : string형 책이름
	@param _writer : string형 작가이름
	@param _id : unsigned int형 책 id
	
	*/
	Book(string _name, string _writer, unsigned int _id)
		:name(_name), writer(_writer), id(_id)
	{}
	/**
	@brief 소멸자입니다. 다만 mock test를 위해 virtual로 선언해주었습니다.
	
	*/
	virtual ~Book() {}
	/**
	@brief 책 이름을 반환하는 함수입니다. mock test를 위해 virtual로 선언해주었습니다.
	@return name

	*/
	virtual string get_book_name() const;
	/**
	@brief 작가 이름을 반환하는 함수입니다. mock test를 위해 virtual로 선언해주었습니다.
	@return writer
	
	*/
	virtual string get_writer_name() const;
	/**
	@brief 책 id를 반환하는 함수입니다. mock test를 위해 virtual로 선언해주었습니다.
	@return id
	
	*/
	virtual unsigned int get_id() const;
	/**
	@brief get_book_name을 mocking class에서 테스트 할 때 사용되는 함수입니다.
	
	*/
	virtual void set_name(string name);
	/**
	@brief get_writer_name을 mocking class에서 테스트 할 때 사용되는 함수입니다.
	*/
	virtual void set_writer(string writer);
	/**
	@brief get_id를 mocing class에서 테스트 할 때 사용되는 함수입니다.
	
	*/
	virtual void set_id(unsigned int id);
	/**
	@brief operator overlodaing입니다. 책들간 equality를 위해 사용됩니다.
	*/
	virtual bool operator==(const Book& left) const;
	/**
	@brief operator overloading입니다. map에 Book 자료형을 지정하기 위해 사용됩니다.
	
	*/
	virtual bool operator<(const Book& left) const;



private:
	/**
	@param name Book 클래스의 멤버 변수입니다.
	@param writer  Book 클래스의 멤버 변수입니다.
	@param id Book 클래스의 멤버 변수입니다.
	*/
	string name;
	string writer;
	unsigned int id;

};