#include"Application.h"
#include<fstream>
#include<iostream>
#include<conio.h>
#include"Professeur.h"
#include"Adresse.h"
#include"StatutLivraison.h"
#include<fstream>
#include"TestUnitaire.h"


using namespace std;


#pragma warning (disable:4996) 


void main(void)
{

	TestUnitaire::Run();

	Adresse adr;
	

	

	//Menu menu("Statut Livraison");
	Application<Adresse> appli;

	//appli.setMenu(&menu);
	appli.run();
	_getch();

}
