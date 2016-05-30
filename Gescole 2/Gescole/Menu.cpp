#include "Menu.h"
#include"ZoneSaisie.h"

Menu::Menu()
	:Container<LigneMenu>()
{
	m_title = new string;
	setTitle("");
	m_choice = eNULL;
}

Menu::Menu(char * title)
	:Container<LigneMenu>()
{
	m_title = new string;
	setTitle(title);
	m_choice = eNULL;


	Add(new LigneMenu(eCREATE, 'C', "Cree."));
	Add(new LigneMenu(eREAD, 'A', "Afficher l'enregistrement courant."));
	Add(new LigneMenu(eUPDATE, 'M', "Modifier."));
	Add(new LigneMenu(eDELETE, 'E', "Effacer l'enregistrement courant."));
	Add(new LigneMenu(eFIRST, 'P', "Premier."));
	Add(new LigneMenu(eNEXT, 'S', "Suivant."));
	Add(new LigneMenu(ePREVIOUS, 'R', "Precedent."));
	Add(new LigneMenu(eLAST, 'D', "Dernier."));
	Add(new LigneMenu(eLIST, 'L', "Lister les enregistrement."));
	Add(new LigneMenu(eQUIT, 'Q', "Quitter."));
	
	
}

Menu::Menu(const Menu & other)
	: Container<LigneMenu>(other)
{
	if (this == &other) return;
	m_title = new string;
	setTitle(other.m_title->c_str());
	m_choice = other.m_choice;
}

Menu::~Menu()
{
	delete m_title;
}

Menu & Menu::operator=(Menu & other)
{
	if (this == &other)return *this;
	Container<LigneMenu>::operator=(other);
	*m_title = *other.m_title;
	m_choice = other.m_choice;
	return *this;
}



const char * Menu::getTitle() const
{
	return (m_title->c_str());
}

void Menu::setTitle(const char * Title)
{
	*m_title = Title;
}

void Menu::display(ostream & COUT)
{
	LigneMenu* temp_Menu;

	COUT << getTitle() << endl;
	temp_Menu = First();
	while (temp_Menu)
	{
		COUT << "\t" << temp_Menu->getHockey() << " - " << *(temp_Menu->getLigne()) << endl;
		temp_Menu = Next();
	}

}

eMENU Menu::askChoice(ostream & COUT)
{
	ZoneSaisie zs;
	do
	{
		COUT << "Votre choix: ";
	} 
	while (!zs.Ask() || translateHotkey(zs.ValCharUpper())== eNULL); // doit introduire au moins 1 caractere.
	
	return m_choice;
	
}

eMENU Menu::translateHotkey(char hotkey)
{
	LigneMenu* temp;
	temp = First();

	while (temp && (temp->getHockey() != hotkey))
	{
		temp = Next();
	}

	if (temp) m_choice = temp->getNemo();
	else m_choice = eNULL;

	return m_choice;
}

