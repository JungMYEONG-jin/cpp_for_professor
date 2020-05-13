#pragma once


#include <cstddef>
#include <string>
#include <string_view>


class SpreadSheetCell
{
public:
	SpreadSheetCell() = default;
	SpreadSheetCell(double initVal);
	explicit SpreadSheetCell(std::string_view initVal);

	void set(double inVal);
	void set(std::string_view inStr);

	double getValue() const {mNum++; return mValue; }
	std::string getString() const { mNum++; return doubleToString(mValue); }

	static std::string doubleToString(double inVal);
	static double stringToDouble(std::string_view inStr);

	SpreadSheetCell& operator+=(const SpreadSheetCell& rhs);
	SpreadSheetCell& operator-=(const SpreadSheetCell& rhs);
	SpreadSheetCell& operator*=(const SpreadSheetCell& rhs);
	SpreadSheetCell& operator/=(const SpreadSheetCell& rhs);




private:
	double mValue = 0;
	mutable size_t mNum = 0;
};


SpreadSheetCell operator+(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
SpreadSheetCell operator-(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
SpreadSheetCell operator*(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
SpreadSheetCell operator/(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator==(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator<(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator>(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator!=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator<=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator>=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);