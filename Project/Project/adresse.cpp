#pragma once
#include "adresse.h"
#include <iostream>
#include "Message.h"

using namespace std;

unsigned long Adresse::CompteurAdresse = 0;
unsigned long Adresse::AdresseEnVie = 0;

// ------------ Constructeur ------------ 

Adresse::Adresse()
{
	
	Initialize(ADRESSE_INCONNU,ADRESSE_INCONNU,0,' ',0);

	
}

Adresse::Adresse(Adresse& adresse)
{

	Initialize(adresse.Localite, adresse.Rue, adresse.Numero, adresse.Boite, adresse.Code_Postal);
}

Adresse::Adresse(char* localite, char* rue, int numero, char boite, int code_postal)
{

	Initialize(localite, rue, numero, boite, code_postal);

}


// ------------ Destructeur ------------ 

Adresse::~Adresse()
{
	AdresseEnVie--;
	cout << ADRESSE_INSTANCE << AdresseEnVie << endl;
	delete Localite;
	delete Rue;
}

// ------------ Seteur ------------ 

void Adresse::set_Id_Adresse(int id_adresse)
{
	ID_Adresse = id_adresse;
}

void Adresse::set_Localite(char* localite)
{
	Localite = localite;
}

void Adresse::set_Rue(char* rue)
{
	Rue = rue;
}

void Adresse::set_Numero(int numero)
{
	if (numero < 0) numero = -numero;
	Numero = numero;
}

void Adresse::set_Boite(char boite)
{
	Boite = boite;
}

void Adresse::set_Code_Postal(int code_postal)
{
	if (code_postal < 0) code_postal = -code_postal;
	Code_Postal = code_postal;
}

int Adresse::get_Id_Adresse(void)
{
	return ID_Adresse;
}

// ------------ Geteur ------------ 

char* Adresse::get_Localite(void)
{
	return Localite;
}

char* Adresse::get_Rue(void)
{
	return Rue;
}

int Adresse::get_Numero(void)
{
	return Numero;
}

char Adresse::get_Boite(void)
{
	return Boite;
}

int Adresse::get_Code_Postal(void)
{
	return Code_Postal;
}

void Adresse::Initialize(char* localite, char* rue, int numero, char boite, int code_postal)
{
	
	Localite = new char[TAILLE_GRD];
	Rue = new char[TAILLE_GRD];
	memset(Localite, 0, sizeof(char[TAILLE_GRD]));
	memset(Rue, 0, sizeof(char[TAILLE_GRD]));

	CompteurAdresse++;
	AdresseEnVie++;

	char bufID[TAILLE_GRD];
	sprintf(bufID, "%s%04d", ADRESSE_ADRESSE, CompteurAdresse);

	set_Id_Adresse(CompteurAdresse);
	set_Rue(rue);
	set_Localite(localite);
	set_Numero(numero);
	set_Boite(boite);
	set_Code_Postal(code_postal);

}
