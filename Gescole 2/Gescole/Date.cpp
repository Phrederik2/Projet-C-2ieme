#include "Date.h"
#include"ZoneSaisie.h"
#include<ctime>


Date::Date()
{
	Year = 1970;
	Month = 1;
	Day = 1;
	TDate = "";
}


Date::~Date()
{
}



Date * Date::setDate()
{
	return this;
}

void Date::setDate(const char * date)
{
	string ddate = date;
	ddate.find('/');
}

void Date::setYear(int year)
{
	Year = format(1970, 2030, year);
}

void Date::setMonth(int month)
{
	Month = format(1, 12, month);
}

void Date::setDay(int day)
{
	Day = format(1, 31, day);
}

int Date::format(int value, int min, int max)
{
	if (value < min) value = min;
	else if (value > max) value = max;
	return value;
}

const char * Date::getDate()
{
	TDate = "";
	TDate + Day + "/" + Month + "/" + Year;
	return TDate.getText();
}

int Date::getYear()
{
	return Year;
}

int Date::getMonth()
{
	return Month;
}

int Date::getDay()
{
	return Day;
}
