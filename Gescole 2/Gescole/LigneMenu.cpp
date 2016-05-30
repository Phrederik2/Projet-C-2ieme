#include "LigneMenu.h"




LigneMenu & LigneMenu::operator=(LigneMenu & source)
{
	if (&source == this) return(*this);
	*m_Ligne = *source.m_Ligne,
	m_Nemo = source.m_Nemo;
	m_Hotkey = source.m_Hotkey;
	return (*this);
}

LigneMenu::LigneMenu()
{
	Initialize(eNULL, ' ', NULL);
}

LigneMenu::LigneMenu(LigneMenu & source)
{

	Initialize(source.m_Nemo, source.m_Hotkey, source.m_Ligne->c_str());
}

LigneMenu::LigneMenu(eMENU nemo, char hotkey, const char * ligne)
{
	Initialize(nemo,hotkey,ligne);
}

char LigneMenu::getHockey()
{
	
	return m_Hotkey;
}

eMENU LigneMenu::getNemo()
{
	return m_Nemo;
}

string * LigneMenu::getLigne()
{

	return m_Ligne;
}




LigneMenu::~LigneMenu()
{
}

void LigneMenu::Initialize(eMENU nemo, char hotkey, const char * ligne)
{
	m_Ligne = new string(ligne);
	m_Nemo = nemo;
	m_Hotkey = hotkey;
}
