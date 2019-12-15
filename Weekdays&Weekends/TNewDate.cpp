#include "TNewDate.h"
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

bool TNewDate::IsWeekDay() 
{
	int diff = JulianDay(year, month, day);
	if (diff % 7 == 6 || diff % 7 == 5)
		return false;
	else
		return true;
}

bool TNewDate::operator==(const TNewDate Date)
{
	if (day == Date.day && month == Date.month && year == Date.year)
		return (true);
	else return (false);
}

bool TNewDate::operator<(const TNewDate Date)
{
	int day1 = year * 10000 + month * 100 + day;
	int day2 = Date.year * 10000 + Date.month * 100 + Date.day;
	if (day1 < day2)
		return (true);
	else return (false);
}

bool TNewDate::operator>(const TNewDate Date)
{
	int day1 = year * 10000 + month * 100 + day;
	int day2 = Date.year * 10000 + Date.month * 100 + Date.day;
	if (day1 > day2)
		return (true);
	else return (false);
}

TNewDate TNewDate::operator=(const TNewDate Date) {
	day = Date.day;
	month = Date.month;
	year = Date.year;
	return *this;
}

TNewDate TNewDate::operator+(const int Count) {
	this->AddDays(Count);
	return *this;
}
