#pragma once
#include"Menu.h"
#include"Container.cpp"
class Menu_Adresse: public Menu
{	
protected:
	Container<LigneMenu> Ligne_Menu;
public:
	Menu_Adresse();
};

