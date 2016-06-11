#pragma once
#include<vector>
#include"LigneMenu.h"
#include<iostream>
#include"List.h"
#include"ZoneSaisie.h"
#include"Message.h"

template<class ENTITY>
class Menu
{

protected:
	List<LigneMenu>* m_Menu;
	eMENU m_choice;//choix fait dans le menu
public:
	Menu();				// sans paramettre
	Menu(const Menu<ENTITY>& other);	// recopie
	~Menu();			// Destructeur
	Menu<ENTITY>& operator=(Menu<ENTITY>& other); // copie

	void display(ostream& COUT, int value=0);
	eMENU askChoice(ostream & COUT);
	eMENU translateHotkey(char hotkey);
};



template<class ENTITY>
Menu<ENTITY>::Menu()
{
	m_Menu = new List<LigneMenu>;

	string entity = typeid(ENTITY).name();

	m_choice = eNULL;

	std::size_t found = entity.find("Lancer");
	if (found != std::string::npos)
	{
		m_Menu->Add(new LigneMenu(eDOSSIER, 'W', Menu_eDossier Pct_Point));
		m_Menu->Add(new LigneMenu(eCLIENT, 'X', Menu_eClient Pct_Point));
		m_Menu->Add(new LigneMenu(eLIVRAISON, 'V', Menu_eLivraison Pct_Point));
		m_Menu->Add(new LigneMenu(eCOMMANDE, 'B', Menu_eCommande Pct_Point));
		m_Menu->Add(new LigneMenu(eRENDEZVOUS, 'N', Menu_eRDV Pct_Point));

	}
	else
	{
		m_Menu->Add(new LigneMenu(eSELECT, 'T', Menu_eDossier Pct_Point));
		m_Menu->Add(new LigneMenu(eCREATE, 'C', Menu_eCreate Pct_Point));
		m_Menu->Add(new LigneMenu(eREAD, 'A', Menu_eRead Pct_Point));
		m_Menu->Add(new LigneMenu(eUPDATE, 'M', Menu_eUpdate Pct_Point));
		m_Menu->Add(new LigneMenu(eDELETE, 'E', Menu_eDelete Pct_Point));
		m_Menu->Add(new LigneMenu(eFIRST, 'P', Menu_eFirst Pct_Point));
		m_Menu->Add(new LigneMenu(eNEXT, 'S', Menu_eNext Pct_Point));
		m_Menu->Add(new LigneMenu(ePREVIOUS, 'R', Menu_ePrevious Pct_Point));
		m_Menu->Add(new LigneMenu(eLAST, 'D', Menu_eLast Pct_Point));
		m_Menu->Add(new LigneMenu(eLIST, 'L', Menu_eList Pct_Point));
		
	}

	m_Menu->Add(new LigneMenu(eQUIT, 'Q', Menu_eQuit Pct_Point));
	
}

template<class ENTITY>
Menu<ENTITY>::Menu(const Menu<ENTITY> & other)
{
	if (this == &other) return;
	m_choice = other.m_choice;
}

template<class ENTITY>
Menu<ENTITY>::~Menu()
{
	delete m_Menu;
}

template<class ENTITY>
Menu<ENTITY> & Menu<ENTITY>::operator=(Menu<ENTITY> & other)
{
	if (this == &other)return *this;
	List<LigneMenu>::operator=(other);

	m_choice = other.m_choice;
	return *this;
}

template<class ENTITY>
void Menu<ENTITY>::display(ostream & COUT, int value)
{
	LigneMenu* temp_Menu;
	eMENU HotKey;
	string* title;
	title = new string;
	Formulaire<ENTITY>::getTitle(title);
	COUT << endl << *title << endl;
	temp_Menu = m_Menu->First();
	HotKey = temp_Menu->getNemo();

	do
	{
		if ((value == 1 || temp_Menu->getNemo() != eSELECT)) COUT << Pct_Tabulation << temp_Menu->getHockey() << Pct_Tiret << *(temp_Menu->getLigne()) << endl;
		temp_Menu = m_Menu->Next();
	}while (temp_Menu);

	delete title;

}

template<class ENTITY>
eMENU Menu<ENTITY>::askChoice(ostream & COUT)
{
	ZoneSaisie zs;
	do
	{
		COUT << Menu_Choice Pct_DeuxPoint;
	} while (!zs.Ask() || translateHotkey(zs.ValCharUpper()) == eNULL); // doit introduire au moins 1 caractere.

	return m_choice;

}

template<class ENTITY>
eMENU Menu<ENTITY>::translateHotkey(char hotkey)
{
	LigneMenu* temp;
	temp = m_Menu->First();

	while (temp && (temp->getHockey() != hotkey))
	{
		temp = m_Menu->Next();
	}

	if (temp) m_choice = temp->getNemo();
	else m_choice = eNULL;

	return m_choice;
}



