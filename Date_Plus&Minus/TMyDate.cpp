#include "TMyDate.h"
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int TMyDate::JulianDay(int year, int month, int day) //将日期转换为儒略日天数
{
	int a = (14 - month) / 12;
	int y = year + 4800 - a;
	int m = month + 12 * a - 3;
	return day + (153 * m + 2) / 5 + y * 365 + y / 4 - y / 100 + y / 400 - 32045;
}

void TMyDate::AddDays(int DayCount) //日期+天数
{
	long int SecCount = DayCount * 86400;
	struct tm time_ = {}, gmt_ = {};
	struct tm* time = &time_, * gmt = &gmt_;

	time->tm_year = year - 1900;
	time->tm_mon = month - 1;
	time->tm_mday = day;
	time_t timep = mktime(time) + 8 * 3600 + SecCount;
	gmtime_s(gmt,&timep);
	year = gmt->tm_year + 1900;
	month = gmt->tm_mon + 1;
	day = gmt->tm_mday;
}

void TMyDate::DecDays(int DayCount) //日期-天数
{
	long int SecCount = DayCount * 86400;
	struct tm time_ = {}, gmt_ = {};
	struct tm* time = &time_, * gmt = &gmt_;

	time->tm_year = year - 1900;
	time->tm_mon = month - 1;
	time->tm_mday = day;
	time_t timep = mktime(time) + 8 * 3600 - SecCount;
	gmtime_s(gmt, &timep);
	year = gmt->tm_year + 1900;
	month = gmt->tm_mon + 1;
	day = gmt->tm_mday;
}

int TMyDate::DaysBetween() //日期间时间差
{
	struct tm tp_ = {};
	struct tm* tp = &tp_;

	time_t t = time(NULL);
	localtime_s(tp,&t);
	int diff_t = fabs(JulianDay(tp->tm_year + 1900, tp->tm_mon + 1, tp->tm_mday) - JulianDay(year, month, day));
	return diff_t;
}

void TMyDate::Print() //输出数据
{
	int date = year * 10000 + month * 100 + day;

	cout << date << endl;
}

void TMyDate::Input() //输入数据
{
	int date, wrong = 1;
	int monday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (wrong)
	{
		cin >> date;
		year = date / 10000;
		month = (date - year * 10000) / 100;
		day = date % 100;
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			monday[1]++;
		if (day > monday[month-1])
			cout << "Wrong Date. Please input the right date." << endl;
		else
			wrong = 0;
	}
}

TMyDate::TMyDate(int d, int m, int y)
{
	year = y;
	month = m;
	day = d;
}

int TMyDate::operator-(const TMyDate& t) //重载-号，日期-日期=日期差
{
	int diff_t = fabs(JulianDay(year, month, day) - JulianDay(t.year, t.month, t.day));
	return diff_t;
}

TMyDate TMyDate::operator-(const int DayCount) //重载-号，日期-天数=新日期
{
	TMyDate New = *this;
	New.DecDays(DayCount);
	return New;
}

TMyDate TMyDate::operator+(const int DayCount) //重载+号，日期+天数=新日期
{
	TMyDate New = *this;
	New.AddDays(DayCount);
	return New;
}

bool TNewDate::IsWeekDay(TMyDate Date)
{
	int diff = Date.JulianDay(year, month, day);
	if (diff % 7 == 6 || diff % 7 == 5)
		return false;
	else
		return true;
}