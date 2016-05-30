#pragma once
#include"Menu_Adresse.h"
#include"Application.h"
#include"MultiType.h"
#include"adresse.h"
#include<fstream>
#include"form_adresse.h"
#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>


#pragma warning (disable:4996)

using namespace std;



void main(void)
{

	Menu_Adresse MenuAdresse;
	Application ApplicationAdresse;

	ApplicationAdresse.setMenu(&MenuAdresse);
	ApplicationAdresse.run();

	_getch();

}

