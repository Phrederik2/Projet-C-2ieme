#include "Menu.h"
#include"ZoneSaisie.h"

Menu::Menu()
	
{
	m_title = new string;
	setTitle("");
	m_choice = eNULL;
}

Menu::Menu(char * title)
	
{
	m_title = new string;
	setTitle(title);
	m_choice = eNULL;

}

Menu::Menu(const Menu & other)
	
{
	if (this == &other) return;
	Ligne_Menu = other.Ligne_Menu;
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
	Ligne_Menu = other.Ligne_Menu;
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
	temp_Menu = Ligne_Menu.First();
	while (temp_Menu)
	{
		COUT << "\t" << temp_Menu->getHockey() << " - " << *(temp_Menu->getLigne()) << endl;
		temp_Menu = Ligne_Menu.Next();
	}

}

enum_Menu Menu::askChoice(ostream & COUT)
{
	ZoneSaisie zs;
	do
	{
		COUT << "Votre choix: ";
	} while (!zs.Ask() || translateHotkey(toupper(zs.ValChar())) == eNULL); // doit introduire au moins 1 caractere.

	return m_choice;

}

enum_Menu Menu::translateHotkey(char hotkey)
{
	LigneMenu* temp;
	temp = Ligne_Menu.First();

	while (temp && (temp->getHockey() != hotkey))
	{
		temp = Ligne_Menu.Next();
	}

	if (temp) m_choice = temp->getNemo();
	else m_choice = eNULL;

	return m_choice;
}

