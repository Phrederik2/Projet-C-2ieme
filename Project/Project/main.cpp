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

	// Test Stream

	Adresse adresse;
	Form_Adresse frm;
	fstream fileprof;
	Multi_Type buffeur;

	frm >> adresse;


	fileprof.open("Adresse.dat",
		ios_base::binary |
		ios_base::in |
		ios_base::out |
		ios_base::trunc);
	if (!fileprof.good())
	{
		cout << "Erreur de fichier" << endl;
		return;
	}

	fileprof.clear();

	buffeur.string = adresse.get_Id_Adresse();
	fileprof.write((char*)&buffeur, sizeof(char[TAILLE_GRD]));
	fileprof.write((char*)adresse.get_Localite(), sizeof(char[TAILLE_GRD]));
	fileprof.write((char*)adresse.get_Rue(), sizeof(char[TAILLE_GRD]));
	buffeur.i = adresse.get_Numero();
	fileprof.write((char*)&buffeur, sizeof(char[TAILLE_GRD]));
	buffeur.c = adresse.get_Boite();
	fileprof.write((char*)&buffeur, sizeof(char[TAILLE_GRD]));


	fileprof.close();

	fileprof.open("Adresse.dat");
	if (!fileprof.good())
	{
		cout << "Erreur de fichier" << endl;
		return;
	}

	fileprof.clear();
	string buf;
	for (size_t i = 0; i < 5; i++)
	{
		getline(fileprof, buf);
		cout << buf << endl;
	}
	

	_getch();

	/*Menu_Adresse MenuAdresse;
	Application ApplicationAdresse;

	ApplicationAdresse.setMenu(&MenuAdresse);
	ApplicationAdresse.run();*/

}

