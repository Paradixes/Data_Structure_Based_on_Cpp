#ifndef TNEWDATE_H
#define TNEWDATE_H
#include "TMyDate.h"
#include <ostream>

class TNewDate : public TMyDate {
public:
	bool IsWeekDay();
	bool operator==(const TNewDate Date);
	bool operator<(const TNewDate Date);
	bool operator>(const TNewDate Date);
	TNewDate operator=(const TNewDate Date);
	TNewDate operator+(const int Count);
	friend std::ostream& operator<<(std::ostream& os, TNewDate& Date)
	{
		Date.Print();
		return os;
	}
};

#endif // TNEWDATE_H

