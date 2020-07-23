#include <assert.h>
#include <array>
#include <iostream>
#include <sstream>
#include <regex>
#include <string>

using namespace std;



void check_Ipv4(string code)
{
	regex re("(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9]?)(\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9]?)){3}");

	cout << code << ": " << boolalpha << regex_match(code, re) << endl;
}


class ipv4
{
	array<unsigned char, 4> data;

public:

	ipv4() : data{ {0} } {}
	ipv4(unsigned char const a, unsigned char const b, unsigned char const c, unsigned char const d) :
		data{ {a,b,c,d} } {}


	ipv4(ipv4 const& ip) : data(ip.data) {}

	ipv4 operator=(ipv4 const& ip) noexcept
	{
		data = ip.data;
		return *this;
	}

	string to_string() const
	{
		stringstream ss;
		ss << *this;
		return ss.str();

	}

	constexpr explicit ipv4(unsigned long a) :
		data{ {static_cast<unsigned char>((a >> 24) & 0xFF),
			static_cast<unsigned char>((a >> 16) & 0xFF),
			static_cast<unsigned char>((a >> 8) & 0xFF),
			static_cast<unsigned char>((a) & 0xFF)} }
	{}


	constexpr unsigned long to_ulong() const noexcept
	{
		return  (static_cast<unsigned long>(data[0] << 24),static_cast<unsigned long>(data[1] << 16), static_cast<unsigned long>(data[2] << 8), static_cast<unsigned long>(data[3]));
	}







	friend ostream& operator<<(ostream& os, ipv4 const& ip)
	{
		os << static_cast<int>(ip.data[0]) <<'.'<< static_cast<int>(ip.data[1]) <<'.'<< static_cast<int>(ip.data[2]) <<'.'<< static_cast<int>(ip.data[3]);
		return os;
	}


	
	friend istream& operator>>(istream& is, ipv4& ip)
	{
		int a, b, c, d;
		char n, m, l;
		is >> a >> n >> b >> m >> c >> l >> d;
		if (n == '.' && m == '.' && l == '.')
			ip = ipv4(a, b, c, d);
		else
			is.setstate(ios_base::failbit);

		return is;
	}



	ipv4& operator++()
	{
		*this = ipv4(to_ulong() + 1);
		return *this;
	}


	ipv4& operator--()
	{
		*this = ipv4(to_ulong() - 1);
		return *this;
	}

	ipv4& operator++(int)
	{
		ipv4 res(*this);
		++(* this);
		return *this;
	}


	friend bool operator<(ipv4& const a, ipv4& const b)
	{
		return a.to_ulong() < b.to_ulong();
	}

	friend bool operator>(ipv4& const a, ipv4& const b)
	{
		return b < a;
	}


	friend bool operator>=(ipv4& const a, ipv4& const b)
	{
		return !(a < b);
	}

	friend bool operator<=(ipv4& const a, ipv4& const b)
	{
		return !(a > b);
	}


	friend bool operator==(ipv4& const a, ipv4& const b)
	{
		return a.data == b.data;
	}

	friend bool operator!=(ipv4& const a, ipv4& const b)
	{
		return !(a.data ==b.data);
	}

	constexpr bool is_loopback() const noexcept
	{
		return (to_ulong() & 0xFF000000) == 0x7F000000;
	}


	constexpr bool is_unspecified() const noexcept
	{
		return to_ulong() == 0;
	}

	constexpr bool is_class_A() const noexcept
	{
		return (to_ulong() & 0x80000000) == 0;
	}

	constexpr bool is_class_B() const noexcept
	{
		return (to_ulong() & 0xC0000000) == 0x80000000;
	}

	constexpr bool is_class_C() const noexcept
	{
		return (to_ulong() & 0xE0000000) == 0xC0000000;
	}

	constexpr bool is_multicast() const noexcept
	{
		return (to_ulong() & 0xF0000000) == 0xE0000000;
	}






};

/*








Bitmask (Bits)	Dotted Decimal	Hexadecimal	Binary
/0	0.0.0.0	0x00000000	00000000 00000000 00000000 00000000
/1	128.0.0.0	0x80000000	10000000 00000000 00000000 00000000
/2	192.0.0.0	0xc0000000	11000000 00000000 00000000 00000000
/3	224.0.0.0	0xe0000000	11100000 00000000 00000000 00000000
/4	240.0.0.0	0xf0000000	11110000 00000000 00000000 00000000
/5	248.0.0.0	0xf8000000	11111000 00000000 00000000 00000000
/6	252.0.0.0	0xfc000000	11111100 00000000 00000000 00000000
/7	254.0.0.0	0xfe000000	11111110 00000000 00000000 00000000
/8	255.0.0.0	0xff000000	11111111 00000000 00000000 00000000
/9	255.128.0.0	0xff800000	11111111 10000000 00000000 00000000
/10	255.192.0.0	0xffc00000	11111111 11000000 00000000 00000000
/11	255.224.0.0	0xffe00000	11111111 11100000 00000000 00000000
/12	255.240.0.0	0xfff00000	11111111 11110000 00000000 00000000
/13	255.248.0.0	0xfff80000	11111111 11111000 00000000 00000000
/14	255.252.0.0	0xfffc0000	11111111 11111100 00000000 00000000
/15	255.254.0.0	0xfffe0000	11111111 11111110 00000000 00000000
/16	255.255.0.0	0xffff0000	11111111 11111111 00000000 00000000
/17	255.255.128.0	0xffff8000	11111111 11111111 10000000 00000000
/18	255.255.192.0	0xffffc000	11111111 11111111 11000000 00000000
/19	255.255.224.0	0xffffe000	11111111 11111111 11100000 00000000
/20	255.255.240.0	0xfffff000	11111111 11111111 11110000 00000000
/21	255.255.248.0	0xfffff800	11111111 11111111 11111000 00000000
/22	255.255.252.0	0xfffffc00	11111111 11111111 11111100 00000000
/23	255.255.254.0	0xfffffe00	11111111 11111111 11111110 00000000
/24	255.255.255.0	0xffffff00	11111111 11111111 11111111 00000000
/25	255.255.255.128	0xffffff80	11111111 11111111 11111111 10000000
/26	255.255.255.192	0xffffffc0	11111111 11111111 11111111 11000000
/27	255.255.255.224	0xffffffe0	11111111 11111111 11111111 11100000
/28	255.255.255.240	0xfffffff0	11111111 11111111 11111111 11110000
/29	255.255.255.248	0xfffffff8	11111111 11111111 11111111 11111000
/30	255.255.255.252	0xfffffffc	11111111 11111111 11111111 11111100
/31	255.255.255.254	0xfffffffe	11111111 11111111 11111111 11111110
/32	255.255.255.255	0xffffffff	11111111 11111111 11111111 11111111

















*/

int main()
{
	string  a= "0.1.2.3";
	check_Ipv4(a);
	check_Ipv4("251.255.255.255");
	check_Ipv4("251.255.255.256");

	ipv4 ip(162,78,7,1);
	cout << ip << endl;

}