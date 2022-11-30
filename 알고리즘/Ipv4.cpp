#include <vector>
#include <array>
#include <regex>
#include <iostream>
#include <string_view>
#include <assert.h>
#include <sstream>
using namespace std;


void isIpv4(string code)
{
	
	regex re("(25[0-5]|2[0-4][0-9]|[1][0-9][0-9]|[1-9][0-9]|[0-9]?)(\.(25[0-5]|2[0-4][0-9]|[1][0-9][0-9]|[1-9][0-9]|[0-9]?)){3}");


	cout << code << ": " << boolalpha << regex_match(code, re) << endl;
}



class Ipv4
{
	array<unsigned char, 4> data;

public:
	constexpr Ipv4() : data{ {0} } {}
	constexpr Ipv4(unsigned char const a, unsigned char const b, unsigned char const c, unsigned char const d) :
		data{ {a,b,c,d } } {}



	explicit constexpr Ipv4(unsigned long a) :
		data{ {static_cast<unsigned char const>((a >> 24) & 0xFF),
			static_cast<unsigned char const>((a >> 16) & 0xFF),
			static_cast<unsigned char const>((a >> 8) & 0xFF),
			static_cast<unsigned char const>((a) & 0xFF)} } {}


	Ipv4(Ipv4 const& other) : data(other.data) {}

	Ipv4 operator=(Ipv4 const& other) noexcept
	{
		data = other.data;
		return *this;

	}

	unsigned long to_ulong() const noexcept
	{
		return (static_cast<unsigned long>(data[0] << 24), static_cast<unsigned long>(data[1] << 16), static_cast<unsigned long>(data[2] << 8), static_cast<unsigned long>(data[3]));
	}




	string to_string() const
	{
		stringstream sstr;
		sstr << *this;
		return sstr.str();
	}



	friend ostream& operator<<(ostream& os, const Ipv4& ip)
	{
		os << static_cast<int>(ip.data[0]) << "." << static_cast<int>(ip.data[1]) << "." << static_cast<int>(ip.data[2]) << "." << static_cast<int>(ip.data[3]);
		return os;
	}


	friend istream& operator>>(istream& is, Ipv4& ip)
	{
		int a, b, c, d;
		char n, m, l;
		is >> a >> n >> b >> m >> c >> l >> d;
		if (n == '.' and m == '.' and l == '.')
			ip = Ipv4(a, b, c, d);
		else
			is.setstate(ios_base::failbit);
		return is;
	}


	


};










int main()
{
	string code = "0.1.2.1";
	string code2 = "25.256.1.1";

	isIpv4(code);
	isIpv4(code2);


	Ipv4 ip(162, 0, 2, 3);
	cout << ip << endl;
	isIpv4(ip.to_string());

	Ipv4 ap;
	cout << ap << endl;
	cin >> ap;
	if (!cin.fail())
		cout << ap << endl;
}