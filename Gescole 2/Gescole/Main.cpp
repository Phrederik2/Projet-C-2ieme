#include"Application.h"
#include"TestUnitaire.h"
#include"ContainerEntity.h"
#include"Client.h"
#include"DropdownList.h"
#include<conio.h>
#include"Livraison.h"
#include"Commande.h"
#include"Date.h"
#include"RendezVous.h"
#include"Dossier.h"


using namespace std;


#pragma warning (disable:4996) 


void main(void)
{
				  //test
	TestUnitaire::Run();

	Application<Client>::Run();
	Application<Dossier>::Run();
	//Application<Commande>::Run();
	//Application<Livraison>::Run();
	//Application<RendezVous>::Run();
	//Application<Dossier>::Run();
	//Client adr;
	

	//Menu menu("Statut DropdownList");
	//Application<Client> appli;

	//appli.setMenu(&menu);
	//appli.run();
	_getch();

}
