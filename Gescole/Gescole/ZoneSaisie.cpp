#include "ZoneSaisie.h"
#include <iostream>
#include <string>

using namespace std;

#define prNOMLEN 50
#define prPRENOMLEN 50

ZoneSaisie::ZoneSaisie()
{
}


ZoneSaisie::~ZoneSaisie()
{
}

char ZoneSaisie::Ask(void)
{

	getline(cin, *this);
	pbuf = c_str();

	return pbuf[0];
}

const char * ZoneSaisie::ValString(void)
{
	return pbuf;
}

char ZoneSaisie::ValChar(void)
{
	return pbuf[0];
}

char ZoneSaisie::ValCharUpper(void)
{

	return  toupper(ValChar());
}

char ZoneSaisie::ValCharLower(void)
{
	return tolower(ValChar());
}

int ZoneSaisie::ValInt(void)
{
	return (int)atoi(pbuf);
}

float ZoneSaisie::ValFloat(void)
{
	return (float)atof(pbuf);
}

unsigned int ZoneSaisie::ValUInt(void)
{
	return (unsigned int)atoi(pbuf);
}

