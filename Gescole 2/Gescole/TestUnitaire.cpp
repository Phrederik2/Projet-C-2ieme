#include "TestUnitaire.h"
#include"Adresse.h"
#include"DropdownList.h"
#include"Livraison.h"


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
	if (Test<Adresse>::Run()) cout <<"Adresse: OK" << endl;
	else cout << "Adresse: NOK" << endl;
	if (Test<DropdownList>::Run()) cout <<"DropdownList: OK" << endl;
	else cout << "DropdownList: NOK" << endl;
	if (Test<Livraison>::Run()) cout << "Livraison: OK" << endl;
	else cout << "Livraison: NOK" << endl;

}
