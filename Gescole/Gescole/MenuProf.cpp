#include "MenuProf.h"



MenuProf::MenuProf()
	:Menu()
{
	setTitle("Menu des Professeur");

	Add(new LigneMenu(eCREATE, 'C', "Cree un prof."));
	Add(new LigneMenu(eREAD, 'A', "Afficher le prof courant."));
	Add(new LigneMenu(eUPDATE, 'M', "Modifier le prof."));
	Add(new LigneMenu(eDELETE, 'E', "Effacer le prof courant."));
	Add(new LigneMenu(eFIRST, 'P', "Aller au premier prof."));
	Add(new LigneMenu(eNEXT, 'S', "Aller au prof suivant."));
	Add(new LigneMenu(ePREVIOUS, 'R', "Aller au prof precedent."));
	Add(new LigneMenu(eLAST, 'D', "Aller au dernier prof."));
	Add(new LigneMenu(eLIST, 'L', "Lister les prof."));
	Add(new LigneMenu(eQUIT, 'Q', "Quitter."));
}
