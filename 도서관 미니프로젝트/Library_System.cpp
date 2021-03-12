#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <string_view>
#include <unordered_map>


using namespace std;

class Book
{
public:
    Book() {}
    Book(string name, string writer, unsigned int id)
        :name(name), writer(writer), id(id)
    {
      
    }
    string get_book_name() const { return name; }
    string get_writer_name() const { return writer; }
    unsigned int get_id() const { return id; }
    bool operator==(const Book& left) const
    {
        return name == left.name && writer == left.writer; // id가 달라도 numOfBooks는 증가해야 하므로 id는 비교하지 않는다
    }
    //bool rent_stat() const { return isRented; }
    //void set_rent() { isRented = true; }
    bool operator<(const Book& left) const
    {
        // 
        return id < left.get_id();
    }
private:
    string name;
    string writer;
    unsigned int id;
   
};

class Member
{
public:
    Member() {}
    Member(string phone, string name)
        :phone_number(phone), name(name)
    {

    }

    string getName() const { return name; }
    string getPhoneNumber() const { return phone_number; }
    bool operator==(const Member& left) const
    {
        return phone_number == left.phone_number && name == left.name;
    }
private:
    string phone_number;
    string name;
};



class RentInfo
{
public:
    RentInfo(const string& date, const Member& member, const Book& book)
        :date(date), member(member), book(book)
    {
        IsRented = true;
        // rentinfo가 생성되면 책이 빌려진것임
    }
    string getDate() const { return date; }
    const Member& getMember() const { return member; }
    const Book& getBook() const { return book; }
    //void set_book_rent() { book.set_rent(); }
    bool operator==(const RentInfo& left)const
    {
        return date == left.date && member == left.member && book == left.book;
    }
    bool rent_stat() const { return IsRented; }
    void set_rent() { IsRented = true; }

private:
    string date;
    Member member;
    Book book;
    bool IsRented;
};


class Library
{
public:
    Library() {}

    void PrintAllContents()
    {
        cout << "------Contents information------" << endl;
        for (auto& it : bookInfo)
        {
            int count = 0;
            cout << "Book: " << it.get_book_name() << "   Writer: " << it.get_writer_name() << "   id: " << it.get_id() << "   Rent: ";
            for (auto& i : rentInfo)
            {

                if (i.getBook().get_id() == it.get_id())
                {
                    cout << i.getDate(); // 날짜
                    count++; // id는 unique 이므로 1이상 증가하지 않음
                }
            }
            if (count == 0)
                cout << "Can Rent";
            cout << endl;
        }
    }
    void PrintAllMember()
    {
        cout << "------Member information------" << endl;
        for (auto& it : memberInfo)
        {
            string rent_book;
            int count = 0;
            cout << "Name: " << it.getName() << "   Phone: " << it.getPhoneNumber();
            for (auto& i : rentInfo)
            {
                //unique phone number
                if (i.getMember().getPhoneNumber() == it.getPhoneNumber())
                {
                    count++;
                    rent_book += i.getBook().get_book_name() + "(" + i.getDate() + "), ";
                }
            }
            if (count >= 1)
                rent_book.erase(rent_book.size() - 2, 2); // erase comma and space
            cout << "   Total " + to_string(count) + " Rent: " << rent_book << endl;
        }
    }
    void PrintRentBook()
    {
        cout << "------Rent_Book information------" << endl;
        for (auto& it : rentInfo)
        {
            cout << "Book: " << it.getBook().get_book_name() << " Writer: " << it.getBook().get_writer_name() << " id: " << it.getBook().get_id() << " Date: " << it.getDate() << endl;
        }
        // book 정보와 대여날짜만 알려줌 멤버 정보는 보안상 알려주지 않는다.   
    }

    bool RentBook(RentInfo& paramrentInfo)
    {
        //일단 회원이 존재하는지 확인
        //auto it = find_if(memberInfo.begin(), memberInfo.end(), [&paramrentInfo](const Member& mem) {return paramrentInfo.getMember() == mem; });

        if (SearchMemberByMember(paramrentInfo.getMember())==-1)
        {
            cout << "The member is not existed in Member information!" << endl;
            return false;
        }
        //책도 존재하는지 확인

        //auto find_book = find_if(bookInfo.begin(), bookInfo.end(), [&paramrentInfo](const Book& mem) {return mem == paramrentInfo.getBook() && mem.get_id() == paramrentInfo.getBook().get_id(); });

        if (SearchBookByBook(paramrentInfo.getBook())==-1)
        {
            cout << "The book is not existed in Book information!" << endl;
            return false;
        }


        //auto it = find(rentInfo.begin(), rentInfo.end(), [&paramrentInfo](const RentInfo& rent) {return rent == paramrentInfo && rent.getBook().get_id() == paramrentInfo.getBook().get_id(); });
        if (IsRented(paramrentInfo)) // 이미 rent된것
        {
            // 대여가 된것임
            cout << "Already Rented!" << endl;
            return false;
        }

        cout << "The Book Rented Successfully" << endl;
        paramrentInfo.set_rent();
        rentInfo.push_back(paramrentInfo);
        // 만약 set rent 오류 발생시 이전 방법으로 복구. set rent 삭제
        return true;
    }
    bool AddMember(const Member& newMember)
    {
        //check phone Num
        for (auto& it : memberInfo)
        {
            // if exists phone number
            if (it.getPhoneNumber() == newMember.getPhoneNumber())
            {
                cout << "Phone Number Duplicated!" << endl;
                return false;
            }
        }
        cout << "Add Member Success!" << endl;
        memberInfo.push_back(newMember);
        return true;
    }
    bool DeleteMember(const Member& newMember)
    {
        // first check the member is existed
        for (auto& it : memberInfo)
        {
            if (it == newMember)// operator== 이용
            {
                // exist so delete it
                memberInfo.erase(remove_if(memberInfo.begin(), memberInfo.end(), [&newMember](const Member& mem) {
                    return mem.getPhoneNumber() == newMember.getPhoneNumber();
                    }), memberInfo.end());
                rentInfo.erase(remove_if(rentInfo.begin(), rentInfo.end(), [&newMember](const RentInfo& rent) {return rent.getMember() == newMember; }), rentInfo.end());
                cout << "Delete Success!" << endl;
                return true;
            }
        }
        cout << "Delete Failed! The Member is not existed in MemberInfo." << endl;
        return true;
    }
    bool AddBook(const Book& newMember)
    {
        // find 
        auto it = find_if(bookInfo.begin(), bookInfo.end(), [&newMember](const Book& book) {return book.get_id() == newMember.get_id(); });
        if (it != bookInfo.end()) // unique id existed 
        {
            cout << "The Book code is existed already!" << endl;
            return false;
        }
        cout << "The Book is added Successfully" << endl;
        bookInfo.push_back(newMember);
        numOfBook[newMember]++; // 총권수 증가
        return true;



    }
    bool DeleteBook(const Book& newMember)
    {
        for (auto& it : bookInfo)
        {
            if ( it == newMember && it.get_id() == newMember.get_id())
            {
                // delete
                bookInfo.erase(remove_if(bookInfo.begin(), bookInfo.end(), [&newMember](const Book& book) {return book.get_id() == newMember.get_id(); }), bookInfo.end());
                numOfBook[newMember]--;
                rentInfo.erase(remove_if(rentInfo.begin(), rentInfo.end(), [&newMember](const RentInfo& rent) {return rent.getBook() == newMember && rent.getBook().get_id() == newMember.get_id(); }), rentInfo.end());
                cout << "Book deleted Successfully" << endl;
                return true;
            }
        }
        cout << "Can not find the Book!" << endl;
        return false;
    }
    bool IsRented(const RentInfo& paramRentInfo)
    {
        //return count_if(rentInfo.begin(), rentInfo.end(), [&paramRentInfo](const RentInfo& rent) {return rent.getBook() == paramRentInfo.getBook() && rent.getBook().get_id() == paramRentInfo.getBook().get_id(); }) == 0 ? false : true;
        auto it = find_if(rentInfo.begin(), rentInfo.end(), [&paramRentInfo](const RentInfo& rent) {return rent.getBook() == paramRentInfo.getBook() &&   rent.getBook().get_id() == paramRentInfo.getBook().get_id(); });
        if (it == rentInfo.end())
            return false; // 일치 목록이 없으므로 대여되지 않은것
        return it->rent_stat();  // 대여된것임
        // rentinfo에 존재하지 않으면 대여 X 상황임 따라서 false return
        // 만약 위 방식에 문제 발생시 count_if로 다시 구현한다.
    }
    int SearchBookByKey(const string& key) {
        // key는 책이름 작가이름이 될수도있음

        auto it = find_if(bookInfo.begin(), bookInfo.end(), [&key](const Book& book) {return book.get_book_name() == key || book.get_writer_name() == key; });
        if (it == bookInfo.end())
            return -1;
        // 대여 가능 여부도 보여줘야함 
        vector<Book> res;
        for (auto& i : bookInfo)
            if (i == *it)
                res.push_back(i);

        for (auto& i : res)
        {
            bool find = false;
            cout << "Book: " << i.get_book_name() << " Writer: " << i.get_writer_name()<<" id: "<<i.get_id() << " Rent: ";
           
            for (auto& rent : rentInfo)
            {
                if (rent.getBook() == i && rent.getBook().get_id() == i.get_id())
                {
                    cout << "Rented!" << endl;
                    find = true;
                }
            }
            if(!find)
                cout << "Can Rent!" << endl;

        }
        return it - bookInfo.begin(); // return index

    }  //찾으면 인덱스 반환 못찾으면 -1반환
    int SearchMemberByKey(const string& key)
    {
        // member unique phone number
        auto it = find_if(memberInfo.begin(), memberInfo.end(), [&key](const Member& mem) {return mem.getPhoneNumber() == key; });
        if (it == memberInfo.end())
            return -1;
        return it - memberInfo.begin();


    }//찾으면 인덱스 반환 못찾으면 -1반환
    int SearchBookByBook(const Book& book)
    {
        // first compare name writer equal then check the id
        auto it = find_if(bookInfo.begin(), bookInfo.end(), [&book](const Book& books) {return book==books && book.get_id() == books.get_id(); });
        if (it == bookInfo.end())
            return -1;
        return it - bookInfo.begin();


    }//찾으면 인덱스 반환 못찾으면 -1반환
    int SearchMemberByMember(const Member& member)
    {
        // just use operator ==
        auto it = find(memberInfo.begin(), memberInfo.end(), member);
        if (it == memberInfo.end())
            return -1;
        return it - memberInfo.begin();
    }//찾으면 인덱스 반환 못찾으면 -1반환

private:
    vector<Book> bookInfo;
    vector<Member>memberInfo;
    vector<RentInfo>rentInfo;
    map<Book, int> numOfBook; //책이 총 몇권인지 체크하는 map변수
};


int main()
{
    Library lib;
    
    lib.AddMember(Member("123", "mj"));
    lib.AddMember(Member("123", "ka"));
    lib.AddMember(Member("1234", "kaka"));
    //lib.PrintAllMember();
    cout << lib.SearchMemberByKey("1234") << endl;
   
    //lib.PrintAllMember();
    cout << lib.SearchMemberByKey("1234") << endl;
   

    lib.AddBook(Book("QA", "mj", 13));
    lib.AddBook(Book("QA", "mj", 13322));
    lib.AddBook(Book("QA2", "kira", 1342));
    //lib.PrintAllContents();
   // lib.PrintRentBook();
    RentInfo a("2020-10-20", Member("123", "mj"), Book("QA", "mj", 13));
    RentInfo c("2020-10-20", Member("1234", "kaka"), Book("QA1", "mj", 13322));
    RentInfo b("2020-09-12", Member("123", "mj"), Book("QA2", "kira", 1342));
   // cout << lib.SearchBookByBook(Book("QA", "mj", 13)) << endl;
    

    //lib.DeleteBook(Book("QA", "mhh", 13));
    lib.PrintAllContents();
    //lib.DeleteBook(Book("QA", "mj", 13));
    //lib.PrintAllContents();
    lib.RentBook(a);
    lib.RentBook(b);
    lib.RentBook(c);
    RentInfo d("2020-09-12", Member("123", "mj"), Book("QA2312", "kira", 1342));
    cout << lib.IsRented(a) << endl;
    cout << lib.IsRented(b) << endl;
    cout << lib.IsRented(c) << endl;
    lib.RentBook(a);
    lib.RentBook(b);
    lib.RentBook(c);
    lib.RentBook(d);
    lib.PrintAllContents();
    lib.PrintAllMember();

    RentInfo e("2020-09-12", Member("123", "mj"), Book("QA2", "kira10", 13420));
    lib.RentBook(e);
   // lib.RentBook(c);
    
}


