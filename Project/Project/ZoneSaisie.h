#pragma once
#include <iostream>
using namespace std;
class ZoneSaisie
{

protected:
		char Temp[256];
public:
	char Ask();
	char ValChar();
	char* ValString();
	int ValInt();
	unsigned int ValUInt();
	long ValLong();
	unsigned long ValULong();
	float ValFloat();
	

};

