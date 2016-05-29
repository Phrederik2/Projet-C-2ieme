#include "Menu_Adresse.h"



Menu_Adresse::Menu_Adresse()
{
	setTitle("Menu des Professeur");

	Ligne_Menu.Add(new LigneMenu(eCREATE, 'C', "Cree un prof."));
	Ligne_Menu.Add(new LigneMenu(eREAD, 'A', "Afficher le prof courant."));
	Ligne_Menu.Add(new LigneMenu(eUPDATE, 'M', "Modifier le prof."));
	Ligne_Menu.Add(new LigneMenu(eDELETE, 'E', "Effacer le prof courant."));
	Ligne_Menu.Add(new LigneMenu(eFIRST, 'P', "Aller au premier prof."));
	Ligne_Menu.Add(new LigneMenu(eNEXT, 'S', "Aller au prof suivant."));
	Ligne_Menu.Add(new LigneMenu(ePREVIOUS, 'R', "Aller au prof precedent."));
	Ligne_Menu.Add(new LigneMenu(eLAST, 'D', "Aller au dernier prof."));
	Ligne_Menu.Add(new LigneMenu(eQUIT, 'Q', "Quitter."));
}