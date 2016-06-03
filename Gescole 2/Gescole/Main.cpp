#include"Application.h"
#include"TestUnitaire.h"
#include"ContainerEntity.h"
#include"Adresse.h"
#include"DropdownList.h"
#include<conio.h>
#include"Livraison.h"
#include"Commande.h"
#include"Date.h"
#include"RendezVous.h"


using namespace std;


#pragma warning (disable:4996) 


void main(void)
{
				  //test
	TestUnitaire::Run();
	Application<Commande>::Run();
	Application<Livraison>::Run();
	Application<RendezVous>::Run();
	//Adresse adr;
	

	//Menu menu("Statut DropdownList");
	//Application<Adresse> appli;

	//appli.setMenu(&menu);
	//appli.run();
	_getch();

}
