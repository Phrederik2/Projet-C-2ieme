#include "MenuCours.h"



MenuCours::MenuCours()
{
	setTitle("Menu des Cours");

	Add(new LigneMenu(eCREATE, 'C', "Cree un Cours."));
	Add(new LigneMenu(eREAD, 'A', "Afficher le Cours courant."));
	Add(new LigneMenu(eUPDATE, 'M', "Modifier le Cours."));
	Add(new LigneMenu(eDELETE, 'E', "Effacer le Cours courant."));
	Add(new LigneMenu(eFIRST, 'P', "Aller au premier Cours."));
	Add(new LigneMenu(eNEXT, 'S', "Aller au Cours suivant."));
	Add(new LigneMenu(ePREVIOUS, 'R', "Aller au Cours precedent."));
	Add(new LigneMenu(eLAST, 'D', "Aller au dernier Cours."));
	Add(new LigneMenu(eQUIT, 'Q', "Quitter."));
}

