#ifndef TMYDATE_H_INCLUDED
#define TMYDATE_H_INCLUDED

class TMyDate
{
public:
	TMyDate();
	TMyDate(int d, int m, int y);
	void AddDays(int DayCount); //����+����=������
	void DecDays(int DayCount); //����-����=������
	int DaysBetween(); //�������ڲ�
	void Print(); //�������
	void Input(); //��������
	int operator-(const TMyDate& t); //����-�ţ�����-����=���ڲ�
	TMyDate operator+(const int DayCount); //����+�ţ�����+����=������
	TMyDate operator-(const int DayCount); //����-�ţ�����-����=������

protected:
	int day;
	int month;
	int year;
	int JulianDay(int year, int month, int day);
};

#endif // NEWTYPE_H_INCLUDED
