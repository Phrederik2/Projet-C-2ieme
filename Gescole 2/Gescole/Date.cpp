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
	Year = format(year, 1070, 2030);
}

void Date::setMonth(int month)
{
	Month = format(month, 1, 12);
}

void Date::setDay(int day)
{
	Day = format(day, 1, 31);
}

int Date::format(int value, int min, int max)
{
	if (value < min) value = min;
	if (value > max) value = max;
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
