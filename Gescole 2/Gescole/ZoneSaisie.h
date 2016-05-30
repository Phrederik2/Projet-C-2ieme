#pragma once
#include <string>
using namespace std;

class ZoneSaisie:public string
{

protected:
	const char*  pbuf;

public:
	ZoneSaisie();
	~ZoneSaisie();
	char Ask(void);
	const char* ValString(void);
	char ValChar(void);
	char ValCharUpper(void);
	char ValCharLower(void);
	int ValInt(void);
	float ValFloat(void);
	unsigned int ValUInt(void);



};

