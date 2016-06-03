#pragma once
#include"Text.h"
#include<iostream>
class Date
{
public:
	
	Date();
	~Date();
protected:
	unsigned int Year;
	unsigned int Month;
	unsigned int Day;
	Text TDate;

	int format(int value, int min, int max);

public:
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	const char* getDate();
};

