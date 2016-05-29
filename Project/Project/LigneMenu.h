#pragma once
#include<string>
#include<iostream>
using namespace std;

enum enum_Menu
{
	eNULL = 0,
	eNONE = 0,
	eCREATE,
	eREAD,
	eUPDATE,
	eDELETE,
	eDELETEALL,
	eLIST,
	eFIRST,
	eNEXT,
	eLAST,
	ePREVIOUS,
	eSORT,
	eSEARCH,
	eERROR = -1,
	eQUIT = 999
};


class LigneMenu
{
protected:
	enum_Menu Mnemo;
	char Hotkey;
	string* Ligne;
public:
	LigneMenu& operator=(LigneMenu& source);
	LigneMenu();
	LigneMenu(LigneMenu& source);
	LigneMenu(enum_Menu mnemo, char hotkey, string ligne);
	~LigneMenu();
	char getHockey();
	enum_Menu getNemo();
	string* getLigne();
	LigneMenu& duplication(LigneMenu* source);
protected:
	void initialize(enum_Menu mnemo, char hotkey, string* ligne);
};

