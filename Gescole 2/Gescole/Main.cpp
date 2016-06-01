#include"Application.h"
#include"TestUnitaire.h"
#include"ContainerEntity.h"
#include"Adresse.h"
#include"StatutLivraison.h"
#include<conio.h>


using namespace std;


#pragma warning (disable:4996) 


void main(void)
{

	TestUnitaire::Run();

	Application<Adresse>::Run();
	//Adresse adr;
	

	//Menu menu("Statut Livraison");
	//Application<Adresse> appli;

	//appli.setMenu(&menu);
	//appli.run();
	_getch();

}
