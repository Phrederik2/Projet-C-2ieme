#pragma once
#include<vector>
#include"LigneMenu.h"
#include<iostream>
#include"Container.cpp"

//template<class ENTITY>
class Menu: public Container<LigneMenu>
{

protected:
	string* m_title;// titre du menu
	eMENU m_choice;//choix fait dans le menu



public:
	Menu();				// sans paramettre
	Menu(char* title);	// avec paramettre
	Menu(const Menu& other);	// recopie
	~Menu();			// Destructeur
	Menu& operator=(Menu& other); // copie

	const char* getTitle() const;
	void setTitle(const char* Title);
	void display(ostream& COUT);
	eMENU askChoice(ostream & COUT);
	eMENU translateHotkey(char hotkey);
};

