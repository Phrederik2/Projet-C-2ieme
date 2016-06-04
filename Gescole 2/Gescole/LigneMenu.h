#pragma once

// definition des mnemonique;
#include<string>
#include<vector>

using namespace std;
enum eMENU 
{
eNULL=0,
eNONE=0,
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
eSELECT,
eERROR=-1,
eQUIT=999
};

class LigneMenu
{
public:
	LigneMenu& operator=(LigneMenu& source);
	LigneMenu();
	LigneMenu(LigneMenu& source);
	LigneMenu(eMENU nemo,char hotkey, const char* ligne);
	char getHockey();
	eMENU getNemo();
	string* getLigne();

	
	~LigneMenu();
	
	
protected:
	string* m_Ligne;
	char m_Hotkey;
	eMENU m_Nemo;

	void Initialize(eMENU nemo, char hotkey, const char* ligne);


	
};

