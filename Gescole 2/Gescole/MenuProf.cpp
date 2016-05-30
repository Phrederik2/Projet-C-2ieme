#include "MenuProf.h"



MenuProf::MenuProf(string title)
	:Menu()
{
	setTitle(title.c_str());

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
