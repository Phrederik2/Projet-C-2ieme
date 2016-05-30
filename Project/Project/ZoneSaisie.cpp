#include "ZoneSaisie.h"

char ZoneSaisie::Ask()
{
	cin.getline(Temp, 256);
	return Temp[0];
}

char ZoneSaisie::ValChar()
{
	return Temp[0];
}

char* ZoneSaisie::ValString()
{
	return Temp;
}

int ZoneSaisie::ValInt()
{
	return (int)atoi(Temp);
}

unsigned int ZoneSaisie::ValUInt()
{
	return (unsigned int)atoi(Temp);
}

long ZoneSaisie::ValLong()
{
	return (long)atol(Temp);
}

unsigned long ZoneSaisie::ValULong()
{
	return (unsigned long)atol(Temp);
}

float ZoneSaisie::ValFloat()
{
	return (float)atof(Temp);
}
