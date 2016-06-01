#include "TestUnitaire.h"
#include"Adresse.h"
#include"DropdownList.h"
#include"Livraison.h"
#include"Commande.h"
#include"RendezVous.h"
#include<iostream>

using namespace std;


template<class ENTITY>
Test<ENTITY>::Test()
{
}

template<class ENTITY>
Test<ENTITY>::~Test()
{
}

template<class ENTITY>
bool Test<ENTITY>::Run()
{
	int Alive1, Alive2;
	ENTITY adr1;
	ENTITY* adr2 = new ENTITY;
	Alive1 = adr1.getAlive();
	delete adr2;
	Alive2 = adr1.getAlive();
	return (bool)(Alive1 == 2 && Alive2 == 1);
}

void TestUnitaire::Run()
{
	if (Test<Adresse>::Run()) cout << "Adresse: OK" << endl;
	else cout << "Adresse: NOK" << endl;
	if (Test<Commande>::Run()) cout << "Commande: OK" << endl;
	else cout << "Commande: NOK" << endl;
	if (Test<Livraison>::Run()) cout << "Livraison: OK" << endl;
	else cout << "Livraison: NOK" << endl;
	if (Test<RendezVous>::Run()) cout << "RendezVous: OK" << endl;
	else cout << "RendezVous: NOK" << endl;

}
