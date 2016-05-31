#include"Application.h"
#include<fstream>
#include<iostream>
#include<conio.h>
#include"Professeur.h"
#include"Adresse.h"
#include"StatutLivraison.h"
#include<fstream>


using namespace std;


#pragma warning (disable:4996) 


void main(void)
{
#define ENTITY StatutLivraison
	ENTITY adr1;
	ENTITY adr2;
	ENTITY* adr3 = new ENTITY;
	cout << adr1;
	cout << adr2;
	cout << "Alive ENTITY: " << adr1.getAlive()<<endl;
	delete adr3;
	cout << "Alive ENTITY: " << adr1.getAlive()<<endl;
	ENTITY adr4;
	cout << adr4;
	Adresse::

	Menu menu("Statut Livraison");
	Application<ENTITY> adresse;

	adresse.setMenu(&menu);
	adresse.run();
	_getch();

}
