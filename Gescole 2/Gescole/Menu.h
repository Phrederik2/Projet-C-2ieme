#pragma once
#include<vector>
#include"LigneMenu.h"
#include<iostream>
#include"Container.h"

template<class ENTITY>
class Menu//: protected Container<LigneMenu>
{

protected:
	Container<LigneMenu> m_Menu;
	string* m_title;// titre du menu
	eMENU m_choice;//choix fait dans le menu



public:
	Menu();				// sans paramettre
	Menu(char* title);	// avec paramettre
	Menu(const Menu<ENTITY>& other);	// recopie
	~Menu();			// Destructeur
	Menu<ENTITY>& operator=(Menu<ENTITY>& other); // copie

	const char* getTitle() const;
	void setTitle(const char* Title);
	void display(ostream& COUT);
	eMENU askChoice(ostream & COUT);
	eMENU translateHotkey(char hotkey);
};

