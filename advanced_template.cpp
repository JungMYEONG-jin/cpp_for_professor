#include <cstddef>
#include <array>
#include <cstring>
#include <iostream>
#include "SpreadSheetCell.h"
#include "NDGrid.h"
#include <string>
#include <string_view>
#include <functional>










using namespace std;

static const size_t NOT_FOUND = static_cast<size_t>(-1);



namespace {
	int defInt = 11;
	SpreadSheetCell defCell(1.2);
}


string solution(string s) {
    string answer = "";
    int length = s.length();
    int count = 0;

    if (length % 2 != 0)
    {
        for (const auto& i : s)
        {
            count++;
            if (count == (length / 2 + 1))
                answer = i;
        }
    }

    if (length % 2 == 0)
    {
        answer = s[length / 2] + s[length / 2 + 1];
    }


    return answer;
}

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
    cout << "Original" << endl;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == value) {
            return i;
        }
    }
    return NOT_FOUND;
}
//인덱스 리턴임

template <typename T>
size_t Find(T* const& value, T* const* arr, size_t size)
{
    cout << "ptr special" << endl;
    for (size_t i = 0; i < size; i++)
    {
        if (*arr[i] == *value) {
            return i;
        }
    }
    return NOT_FOUND;
}

// 인덱스 리턴


template<>
size_t Find<const char*>(const char* const& value, const char* const* arr, size_t size)
{
    cout << "Specialized" << endl;
    for (size_t i = 0; i < size; i++) {
        if (strcmp(arr[i], value) == 0) {
            return i;
        }
    }
    return NOT_FOUND;
}

size_t Find(const char* const& value, const char* const* arr, size_t size)
{
    cout << "Overload" << endl;
    for (size_t i = 0; i < size; i++) {
        if (strcmp(arr[i], value) == 0) {
            return i;
        }
    }
    return NOT_FOUND;
}



void handleValue(int val)
{
    cout << "Int " << val << endl;
}

void handleValue(double val)
{
    cout << "Double " << val << endl;
}
void handleValue(string_view str)
{
    cout << "String " << str << endl;
}



template<typename... Tn>
void proc(const Tn&... args)
{
    (handleValue(args), ...);
}

void procRef()
{

}

template<typename T1, typename... Tn>
void procRef(T1&& arg1, Tn&&... args)
{
    handleValue(std::forward<T1>(arg1));
    procRef(std::forward<Tn>(args)...);
}



class Mixin1
{
public:
    Mixin1(int i) : mValue(i) {}
    virtual void Mixin1Func() { cout << "Mixin1 " << mValue << endl; }

private:
    int mValue;
};

class Mixin2
{
public:
    Mixin2(int i) : mValue(i) {}
    virtual void Mixin2Func() { cout << "Mixin2 " << mValue << endl; }

private:
    int mValue;
};



template<typename... Mixins>
class MyClass : public Mixins...
{
public:
    MyClass(const Mixins&... mixins) : Mixins(mixins)... {}
    virtual ~MyClass() = default;
};


template<typename... Values>
void printVal(const Values&... values)
{
    ((cout << values << endl), ...);
}



template <typename T, typename... Values>
double sumValue(const T& init, const Values&... values)
{
    return (init + ... + values);
}


template<unsigned char f>
class Factorial
{
public:
    static const unsigned long long val = { f * Factorial<f - 1>::val };
};

template<>
class Factorial<0>
{
public:
    static const unsigned long long val = 1;
};



constexpr unsigned long long factorial(unsigned char f)
{
    if (f == 0) {
        return 1;
    }
    else {
        return f * factorial(f - 1);
    }
}









int main()
{
    proc(1, 2, 3.46, "test", 1.1f);
   
    cout << endl;
   
    printVal(1, 2, 3.46, "test", 1.1f);

    cout << sumValue(1, 4, 6.6) << endl;
    cout << sumValue(1) << endl;


    cout << Factorial<6>::val << endl;


    constexpr auto f1 = factorial(6);
    cout << f1 << endl;

	return 0;
}
