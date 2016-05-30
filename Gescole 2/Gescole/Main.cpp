#include"Application.h"
#include<fstream>
#include<iostream>
#include<conio.h>
#include"Professeur.h"


using namespace std;


#pragma warning (disable:4996) 


void main(void)
{
	
	Menu menu("Test");
	Application<Professeur> AppProf;

	AppProf.setMenu(&menu);
	AppProf.run();
	_getch();

}
