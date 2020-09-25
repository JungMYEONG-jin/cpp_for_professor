#include <iostream>
#include <vector>

using namespace std;


#define COMPARE(OP) \
friend Magic_Compare<T> operator OP(Magic_Compare<T> self, T other){\
 return Magic_Compare(other, self.prev && self.value OP other);\
}\
friend Magic_Compare<T> operator OP(T other, Magic_Compare<T> self){\
return Magic_Compare(self.value, self.prev&& other OP self.value); \
}\
friend Magic_Compare<T> operator OP(Magic_Compare<T> self, Magic_Compare<T> other){\
return Magic_Compare(other.value, self.prev && self.value OP other.value);\
}\

#define ARITHMETIC(OP)\
friend Magic_Compare<T> operator OP(T other, Magic_Compare<T> self){\
return Magic_Compare(other OP self.value, self.prev);\
}\
friend Magic_Compare<T> operator OP(Magic_Compare<T> self, T other){\
return Magic_Compare(other OP self.value, self.prev);\
}\
friend Magic_Compare<T> operator OP(Magic_Compare<T> self, Magic_Compare<T> other){\
return Magic_Compare(other.value OP self.value, self.prev);\
}

#define ARITHMETIC_INPLACE(OP)\
void operator OP(T other){\
value OP other;\
}\
void operator OP(Magic_Compare<T>& other){\
value OP other.value;\
}

#define UNARY(OP)\
Magic_Compare<T>& operator OP(){\
this->value;\
return *this;\
}\


template<typename T>
class Magic_Compare
{
public:
	Magic_Compare(T val, bool pr = true)
		:value(val), prev(pr)
	{}

	Magic_Compare<T>& operator=(T other)
	{
		this->value = other;
		return *this;
	}

	explicit operator bool()
	{
		return this->prev;
	}

	operator T()
	{
		if (!prev)
			return Magic_Compare(0);
		return this->value;
	}

	COMPARE(== )
		COMPARE(!= )
		COMPARE(< )
		COMPARE(<= )
		COMPARE(> )
		COMPARE(>= )

		ARITHMETIC(+)
		ARITHMETIC(-)
		ARITHMETIC(*)
		ARITHMETIC(/ )

		ARITHMETIC_INPLACE(+= )
		ARITHMETIC_INPLACE(-= )
		ARITHMETIC_INPLACE(*= )
		ARITHMETIC_INPLACE(/= )

		UNARY(++)
		UNARY(--)



private:
	T value;
	bool prev = true;
};