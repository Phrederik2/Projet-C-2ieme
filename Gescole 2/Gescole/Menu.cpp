#include "Menu.h"
#include"ZoneSaisie.h"

template<class ENTITY>
Menu<ENTITY>::Menu()
{
	
	m_title = new string("Test");
	m_choice = eNULL;

	m_Menu.Add(new LigneMenu(eSELECT, 'T', "Selectionner."));
	m_Menu.Add(new LigneMenu(eCREATE, 'C', "Cree."));
	m_Menu.Add(new LigneMenu(eREAD, 'A', "Afficher l'enregistrement courant."));
	m_Menu.Add(new LigneMenu(eUPDATE, 'M', "Modifier."));
	m_Menu.Add(new LigneMenu(eDELETE, 'E', "Effacer l'enregistrement courant."));
	m_Menu.Add(new LigneMenu(eFIRST, 'P', "Premier."));
	m_Menu.Add(new LigneMenu(eNEXT, 'S', "Suivant."));
	m_Menu.Add(new LigneMenu(ePREVIOUS, 'R', "Precedent."));
	m_Menu.Add(new LigneMenu(eLAST, 'D', "Dernier."));
	m_Menu.Add(new LigneMenu(eLIST, 'L', "Lister les enregistrement."));
	m_Menu.Add(new LigneMenu(eQUIT, 'Q', "Quitter."));
}

template<class ENTITY>
Menu<ENTITY>::Menu(const Menu<ENTITY> & other)
{
	if (this == &other) return;
	m_title = new string;
	setTitle(" ");
	m_choice = other.m_choice;
}

template<class ENTITY>
Menu<ENTITY>::~Menu()
{
	delete m_title;
}

template<class ENTITY>
Menu<ENTITY> & Menu<ENTITY>::operator=(Menu<ENTITY> & other)
{
	if (this == &other)return *this;
	Container<LigneMenu>::operator=(other);
	*m_title = *other.m_title;
	m_choice = other.m_choice;
	return *this;
}

template<class ENTITY>
const char * Menu<ENTITY>::getTitle() const
{
	return (m_title->c_str());
}

template<class ENTITY>
void Menu<ENTITY>::setTitle(const char * Title)
{
	m_title = " ";
}

template<class ENTITY>
void Menu<ENTITY>::display(ostream & COUT, bool value)
{
	LigneMenu* temp_Menu;
	ENTITY temp;

	COUT << temp.getTitle() << endl;
	temp_Menu = m_Menu.First();
	while (temp_Menu)
	{
		if ((value == 1 ||  temp_Menu->getNemo() != eSELECT)) COUT << "\t" << temp_Menu->getHockey() << " - " << *(temp_Menu->getLigne()) << endl;
		temp_Menu = m_Menu.Next();
	}

}

template<class ENTITY>
eMENU Menu<ENTITY>::askChoice(ostream & COUT)
{
	ZoneSaisie zs;
	do
	{
		COUT << "Votre choix: ";
	} 
	while (!zs.Ask() || translateHotkey(zs.ValCharUpper())== eNULL); // doit introduire au moins 1 caractere.
	
	return m_choice;
	
}

template<class ENTITY>
eMENU Menu<ENTITY>::translateHotkey(char hotkey)
{
	LigneMenu* temp;
	temp = m_Menu.First();

	while (temp && (temp->getHockey() != hotkey))
	{
		temp = m_Menu.Next();
	}

	if (temp) m_choice = temp->getNemo();
	else m_choice = eNULL;

	return m_choice;
}

