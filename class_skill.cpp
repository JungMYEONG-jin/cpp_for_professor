#include <ostream>



using namespace std;

class X {
  int m_a;
  int m_b;
public:
  X()
    :m_a(1), m_b(2) {}
  X(int a, int b = 2)
    :m_a(a), m_b(b) {}
  X(const X& copy)
    :m_a(copy.m_a), m_b(copy.m_b) {}

  X& operator=(const X& x)
  {
    if (this == &x)
      return *this;
    m_a = x.m_a;
    m_b = x.m_b;
    return *this;
  }
  X& operator+=(const X& x)
  {
    m_a += x.m_a;
    m_b += x.m_b;
    return *this;
  }
  X operator+(const X& x)
  {
    X res;
    res.m_a = m_a+x.m_a;
    res.m_b = m_b+x.m_b;
    return res;
    
  }

  //전위식
  X& operator++()
  {
    m_a++;
    m_b++;
    return *this;
  }
  //후위식
  X operator++(int)
  {
    X th = X(*this);
    ++* this;
    return th;


  }


  string print(); // used for testing

  friend ostream& operator<<(ostream& os, const X& x);


};

string X::print()
{
  stringstream s;
  s << "[" << m_a << "," << m_b << "]";
  return s.str();
}

ostream& operator<<(ostream& os, const X& x)
{
  os << "[" << to_string(x.m_a) << "," << to_string(x.m_b) << "]";
  return os;
}









/*
최고 간결한 코드
class X {
public:
    X(int a = 1, int b = 2) : m_a(a), m_b(b) {}
    X& operator+=(const X& other) {m_a += other.m_a; m_b += other.m_b; return *this;}
    X& operator++() {++m_a; ++m_b; return *this;}
    X operator++(int) {X result(*this); ++*this; return result;}
    std::string print() const {std::ostringstream s; s << '[' << m_a << ',' << m_b << ']'; return s.str();}
private:
    int m_a, m_b;
};
X operator+(const X& lhs, const X& rhs) {return X(lhs) += rhs;}
std::ostream& operator<<(std::ostream& out, const X& x) {return out << x.print();}




*/
