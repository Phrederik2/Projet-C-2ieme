#pragma once
#include"Menu_Adresse.h"
#include"Application.h"


#pragma warning (disable:4996)

using namespace std;



void main(void)
{
	Menu_Adresse MenuAdresse;
	Application ApplicationAdresse;

	ApplicationAdresse.setMenu(&MenuAdresse);
	ApplicationAdresse.run();

}

