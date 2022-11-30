#include <cstddef>
#include <array>
#include <cstring>
#include <iostream>
#include "SpreadSheetCell.h"














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








int main()
{
    size_t res = NOT_FOUND;

    int myint = 3, intArr[] = { 1,2,3,4 };
    size_t sizeArray = std::size(intArr);


    res = Find(myint, intArr, sizeArray); //추론
    res = Find<int>(myint, intArr, sizeArray); //명시적


    double mydouble = 5.6, doubleArr[] = { 1.2, 3.4, 5.7, 7.5 };
    sizeArray = std::size(doubleArr);
    res = Find(mydouble, doubleArr, sizeArray);
    res = Find<double>(mydouble, doubleArr, sizeArray);


    const char* word = "two";
    const char* words[] = { "one", "two", "three", "four" };
    sizeArray = std::size(words);
    res = Find<const char*>(word, words, sizeArray);
    res = Find(word, words, sizeArray);




    int* intPointer = &myint, * pointerArr[] = { &myint, &myint };
    sizeArray = std::size(pointerArr);
    res = Find(intPointer, pointerArr, sizeArray);



    SpreadSheetCell cell(10), cellarr[] = { SpreadSheetCell(4), SpreadSheetCell(10) };
    sizeArray = std::size(cellarr);
    res = Find(cell, cellarr, sizeArray);
    res = Find<SpreadSheetCell>(cell, cellarr, sizeArray);




    SpreadSheetCell* cellPointer = &cell;
    SpreadSheetCell* cellPointerArr[] = { &cell, &cell };
    sizeArray = std::size(cellPointerArr);
    res = Find(cellPointer, cellPointerArr, sizeArray);



	return 0;
}