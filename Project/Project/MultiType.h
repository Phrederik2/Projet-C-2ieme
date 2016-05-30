#pragma once
typedef union Multi_Type
{
	char str[100]; // chaine de 120 char.
	char Char;
	long Long;
	unsigned long ULong;
	int Int;
	unsigned int UInt;
	float Float;
	double Double;
	void* Void;
	string* String;
} Multi_Type;