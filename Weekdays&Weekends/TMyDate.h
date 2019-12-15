#ifndef TMYDATE_H_INCLUDED
#define TMYDATE_H_INCLUDED

class TMyDate
{
public:
	TMyDate();
	TMyDate(int d, int m, int y);
	void AddDays(int DayCount); //日期+天数=新日期
	void DecDays(int DayCount); //日期-天数=新日期
	int DaysBetween(); //计算日期差
	void Print(); //输出数据
	void Input(); //输入数据
	int operator-(const TMyDate& t); //重载-号，日期-日期=日期差
	TMyDate operator+(const int DayCount); //重载+号，日期+天数=新日期
	TMyDate operator-(const int DayCount); //重载-号，日期-天数=新日期

protected:
	int day;
	int month;
	int year;
	int JulianDay(int year, int month, int day);
};

#endif // NEWTYPE_H_INCLUDED
