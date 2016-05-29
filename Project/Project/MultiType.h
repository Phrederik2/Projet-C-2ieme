#pragma once
typedef union Multi_Type
{
	char str[120]; // chaine de 120 char.
	long l;
	unsigned long ul;
	int i;
	unsigned int ui;
	float f;
	double d;
	void* p;
}; Multi_Type;