#pragma once



/**
@file Book.h


*/


#include <string>
using namespace std;
/**
@brief Book class�Դϴ�.
@author MJ
@date 2020-12-01
*/
class Book
{

public:
	/**
	@brief �⺻ �������Դϴ�.
	
	*/
	Book() {}
	/**
	@brief ���� ������ �Դϴ�. å�̸�, �۰��̸�, å id�� �μ��� �޽��ϴ�.
	@param _name : string�� å�̸�
	@param _writer : string�� �۰��̸�
	@param _id : unsigned int�� å id
	
	*/
	Book(string _name, string _writer, unsigned int _id)
		:name(_name), writer(_writer), id(_id)
	{}
	/**
	@brief �Ҹ����Դϴ�. �ٸ� mock test�� ���� virtual�� �������־����ϴ�.
	
	*/
	virtual ~Book() {}
	/**
	@brief å �̸��� ��ȯ�ϴ� �Լ��Դϴ�. mock test�� ���� virtual�� �������־����ϴ�.
	@return name

	*/
	virtual string get_book_name() const;
	/**
	@brief �۰� �̸��� ��ȯ�ϴ� �Լ��Դϴ�. mock test�� ���� virtual�� �������־����ϴ�.
	@return writer
	
	*/
	virtual string get_writer_name() const;
	/**
	@brief å id�� ��ȯ�ϴ� �Լ��Դϴ�. mock test�� ���� virtual�� �������־����ϴ�.
	@return id
	
	*/
	virtual unsigned int get_id() const;
	/**
	@brief get_book_name�� mocking class���� �׽�Ʈ �� �� ���Ǵ� �Լ��Դϴ�.
	
	*/
	virtual void set_name(string name);
	/**
	@brief get_writer_name�� mocking class���� �׽�Ʈ �� �� ���Ǵ� �Լ��Դϴ�.
	*/
	virtual void set_writer(string writer);
	/**
	@brief get_id�� mocing class���� �׽�Ʈ �� �� ���Ǵ� �Լ��Դϴ�.
	
	*/
	virtual void set_id(unsigned int id);
	/**
	@brief operator overlodaing�Դϴ�. å�鰣 equality�� ���� ���˴ϴ�.
	*/
	virtual bool operator==(const Book& left) const;
	/**
	@brief operator overloading�Դϴ�. map�� Book �ڷ����� �����ϱ� ���� ���˴ϴ�.
	
	*/
	virtual bool operator<(const Book& left) const;



private:
	/**
	@param name Book Ŭ������ ��� �����Դϴ�.
	@param writer  Book Ŭ������ ��� �����Դϴ�.
	@param id Book Ŭ������ ��� �����Դϴ�.
	*/
	string name;
	string writer;
	unsigned int id;

};