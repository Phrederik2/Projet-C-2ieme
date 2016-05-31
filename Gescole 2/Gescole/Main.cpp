#include"Application.h"
#include<fstream>
#include<iostream>
#include<conio.h>
#include"Professeur.h"
#include"Adresse.h"


using namespace std;


#pragma warning (disable:4996) 


void main(void)
{
	
	Adresse adresse;

	cout << adresse << endl;

	Menu menu("Test");
	Application<Professeur> AppProf;

	AppProf.setMenu(&menu);
	AppProf.run();
	_getch();

}
