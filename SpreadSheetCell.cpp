#include "SpreadSheetCell.h"
#include <stdexcept>

using namespace std;

SpreadSheetCell::SpreadSheetCell(double initialValue)
	: mValue(initialValue)
{
}

SpreadSheetCell::SpreadSheetCell(string_view initialValue)
	: mValue(stringToDouble(initialValue))
{
}

void SpreadSheetCell::set(double inValue)
{
	mValue = inValue;
}

void SpreadSheetCell::set(string_view inString)
{
	mValue = stringToDouble(inString);
}

string SpreadSheetCell::doubleToString(double inValue)
{
	return to_string(inValue);
}

double SpreadSheetCell::stringToDouble(string_view inString)
{
	return strtod(inString.data(), nullptr);
}

SpreadSheetCell operator+(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return SpreadSheetCell(lhs.getValue() + rhs.getValue());
}

SpreadSheetCell operator-(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return SpreadSheetCell(lhs.getValue() - rhs.getValue());
}

SpreadSheetCell operator*(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return SpreadSheetCell(lhs.getValue() * rhs.getValue());
}

SpreadSheetCell operator/(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	if (rhs.getValue() == 0) {
		throw invalid_argument("Divide by zero.");
	}
	return SpreadSheetCell(lhs.getValue() / rhs.getValue());
}

SpreadSheetCell& SpreadSheetCell::operator+=(const SpreadSheetCell& rhs)
{
	set(getValue() + rhs.getValue());
	return *this;
}

SpreadSheetCell& SpreadSheetCell::operator-=(const SpreadSheetCell& rhs)
{
	set(getValue() - rhs.getValue());
	return *this;
}

SpreadSheetCell& SpreadSheetCell::operator*=(const SpreadSheetCell& rhs)
{
	set(getValue() * rhs.getValue());
	return *this;
}

SpreadSheetCell& SpreadSheetCell::operator/=(const SpreadSheetCell& rhs)
{
	if (rhs.getValue() == 0) {
		throw invalid_argument("Divide by zero.");
	}
	set(getValue() / rhs.getValue());
	return *this;
}

bool operator==(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() == rhs.getValue());
}

bool operator<(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() < rhs.getValue());
}

bool operator>(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() > rhs.getValue());
}

bool operator!=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() != rhs.getValue());
}

bool operator<=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() <= rhs.getValue());
}

bool operator>=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() >= rhs.getValue());
}
