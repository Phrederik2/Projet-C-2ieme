#pragma once
class Lancer
{
public:
	bool IsNew;
	bool IsChanged;
	bool IsDelete;
	Lancer();
	~Lancer();
	int getID();
	const char* getTitle();
};

