#include"Application.h"
#include<fstream>
#include<iostream>
#include<conio.h>
#include"Professeur.h"
#include"Adresse.h"
#include<fstream>


using namespace std;


#pragma warning (disable:4996) 


void main(void)
{
	Adresse adr1;
	Adresse adr2;
	Adresse* adr3 = new Adresse;
	cout << adr1;
	cout << adr2;
	cout << "Alive Adresse: " << adr1.getAlive()<<endl;
	delete adr3;
	cout << "Alive Adresse: " << adr1.getAlive()<<endl;
	Adresse adr4;
	cout << adr4;

	/*Menu menu("Adresse");
	Application<Adresse> adresse;

	adresse.setMenu(&menu);
	adresse.run();*/
	_getch();

}
