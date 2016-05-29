#include "Professeur.h"
#include "FormProf.h"
#include "Message.h"
#include <string.h>
#include <iostream>
#include "ZoneSaisie.h"

using namespace std;


void FormProf::operator<<(Professeur& Prof)
{
	if (&Prof)
	{
		cout << endl;
		cout << FRM_PROF_ID << FRM_PROF_DEUXPOINTS << Prof.getId() << endl;
		cout << FRM_PROF_NOM << FRM_PROF_DEUXPOINTS << Prof.getNom() << endl;
		cout << FRM_PROF_PRENOM << FRM_PROF_DEUXPOINTS << Prof.getPrenom() << endl;
		cout << FRM_PROF_ANNEE_NAISSANCE << FRM_PROF_DEUXPOINTS << Prof.getAnneeNaissance() << endl;
		cout << FRM_PROF_POIDS << FRM_PROF_DEUXPOINTS << Prof.getPoids_Kg() << endl;
		cout << FRM_PROF_SALAIRE << FRM_PROF_DEUXPOINTS << Prof.getSalaireMensuel_Eur() << endl;
		cout << "------------------" << endl;
	}
	
}

void FormProf::operator>>(Professeur& Prof)
{
	ZoneSaisie zs;
	cout << FRM_PROF_NOM << FRM_PROF_DEUXPOINTS << endl;
	if (zs.Ask()) Prof.setNom(zs.ValString());
	cout << FRM_PROF_PRENOM << FRM_PROF_DEUXPOINTS << endl;
	if (zs.Ask()) Prof.setPrenom(zs.ValString());
	cout << FRM_PROF_ANNEE_NAISSANCE << FRM_PROF_DEUXPOINTS << endl;
	if (zs.Ask()) Prof.setAnneeNaissance(zs.ValInt());
	cout << FRM_PROF_POIDS << FRM_PROF_DEUXPOINTS << endl;
	if (zs.Ask()) Prof.setPoids_Kg(zs.ValFloat());
	cout << FRM_PROF_SALAIRE << FRM_PROF_DEUXPOINTS << endl;
	if (zs.Ask()) Prof.setSalaireMensuel_Eur(zs.ValFloat());
	cout << "------------------" << endl;
	
}
