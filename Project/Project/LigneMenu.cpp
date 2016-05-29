#include "LigneMenu.h"



LigneMenu & LigneMenu::operator=(LigneMenu & source)
{
	duplication(&source);
	return *this;
}

LigneMenu::LigneMenu()
{
	initialize(eNULL, ' ', NULL);
}

LigneMenu::LigneMenu(LigneMenu & source)
{
	duplication(&source);
}

LigneMenu::LigneMenu(enum_Menu mnemo, char hotkey, string ligne)
{
	initialize(mnemo, hotkey, &ligne);
}

LigneMenu::~LigneMenu()
{
	delete Ligne;
}

char LigneMenu::getHockey()
{
	return Hotkey;
}

enum_Menu LigneMenu::getNemo()
{

	return Mnemo;
}

string * LigneMenu::getLigne()
{
	return Ligne;
}

void LigneMenu::initialize(enum_Menu mnemo, char hotkey, string * ligne)
{
	Mnemo = mnemo;
	Hotkey = hotkey;
	Ligne = new string(*ligne);
}

LigneMenu& LigneMenu::duplication(LigneMenu * source)
{
	if (this == source) return *this;
	Mnemo = source->Mnemo;
	Hotkey = source->Hotkey;
	Ligne = source->Ligne;
	return *this;
}
