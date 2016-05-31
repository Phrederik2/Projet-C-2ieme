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

	Menu menu("Adresse");
	Application<Adresse> adresse;

	adresse.setMenu(&menu);
	adresse.run();
	_getch();

}
