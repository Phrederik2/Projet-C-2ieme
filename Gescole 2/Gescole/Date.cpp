#include "Date.h"
#include"ZoneSaisie.h"


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

void Date::Encode()
{
	ZoneSaisie zs;
	cout << "Jour: " << endl;
	if (zs.Ask()) setDay(zs.ValUInt());
	cout << "Mois: " << endl;
	if (zs.Ask()) setMonth(zs.ValUInt());
	cout << "Annee: " << endl;
	if (zs.Ask()) setYear(zs.ValUInt());
}

ostream & operator<<(ostream & stream, Date & date)
{
	stream << date.getDate();
	return stream;
}
