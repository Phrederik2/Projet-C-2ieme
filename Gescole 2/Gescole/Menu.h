#pragma once
#include<vector>
#include"LigneMenu.h"
#include<iostream>
#include"List.h"
#include"ZoneSaisie.h"

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

	void display(ostream& COUT, bool value=0);
	eMENU askChoice(ostream & COUT);
	eMENU translateHotkey(char hotkey);
};



template<class ENTITY>
Menu<ENTITY>::Menu()
{
	m_Menu = new List<LigneMenu>;

	
		m_choice = eNULL;

		//cout << m_Menu->Size();

		m_Menu->Add(new LigneMenu(eSELECT, 'T', "Selectionner."));
		m_Menu->Add(new LigneMenu(eCREATE, 'C', "Cree."));
		m_Menu->Add(new LigneMenu(eREAD, 'A', "Afficher l'enregistrement courant."));
		m_Menu->Add(new LigneMenu(eUPDATE, 'M', "Modifier."));
		m_Menu->Add(new LigneMenu(eDELETE, 'E', "Effacer l'enregistrement courant."));
		m_Menu->Add(new LigneMenu(eFIRST, 'P', "Premier."));
		m_Menu->Add(new LigneMenu(eNEXT, 'S', "Suivant."));
		m_Menu->Add(new LigneMenu(ePREVIOUS, 'R', "Precedent."));
		m_Menu->Add(new LigneMenu(eLAST, 'D', "Dernier."));
		m_Menu->Add(new LigneMenu(eLIST, 'L', "Lister les enregistrement."));
		m_Menu->Add(new LigneMenu(eQUIT, 'Q', "Quitter."));
	



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
void Menu<ENTITY>::display(ostream & COUT, bool value)
{
	LigneMenu* temp_Menu;
	ENTITY temp;
	eMENU HotKey;

	COUT << temp.getTitle() << endl;
	temp_Menu = m_Menu->First();
	HotKey = temp_Menu->getNemo();

	do
	{
		if ((value == 1 || temp_Menu->getNemo() != eSELECT)) COUT << "\t" << temp_Menu->getHockey() << " - " << *(temp_Menu->getLigne()) << endl;
		temp_Menu = m_Menu->Next();
	}while (temp_Menu);

}

template<class ENTITY>
eMENU Menu<ENTITY>::askChoice(ostream & COUT)
{
	ZoneSaisie zs;
	do
	{
		COUT << "Votre choix: ";
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



