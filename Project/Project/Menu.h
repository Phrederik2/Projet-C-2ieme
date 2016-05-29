#pragma once
#include<vector>
#include"LigneMenu.h"
#include<iostream>
#include"Container.cpp"

class Menu 
{

protected:
	Container<LigneMenu> Ligne_Menu;
	string* m_title;// titre du menu
	enum_Menu m_choice;//choix fait dans le menu



public:
	Menu();				// sans paramettre
	Menu(char* title);	// avec paramettre
	Menu(const Menu& other);	// recopie
	~Menu();			// Destructeur
	Menu& operator=(Menu& other); // copie

	const char* getTitle() const;
	virtual void setTitle(const char* Title);
	void display(ostream& COUT);
	enum_Menu askChoice(ostream & COUT);
	enum_Menu translateHotkey(char hotkey);
};

