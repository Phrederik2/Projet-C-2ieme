#pragma once
#include "adresse.h"
#include <iostream>
#include <string>
#include <string.h>
#include "Message.h"

using namespace std;

unsigned long Adresse::CompteurAdresse = 0;
unsigned long Adresse::AdresseEnVie = 0;

// ------------ Constructeur ------------ 

Adresse::Adresse()
{
	
	CompteurAdresse++;
	AdresseEnVie++;
	
	InitializeString();

	set_Id_Adresse(new string(ASRESSE_ADRESSE + CompteurAdresse));
	set_Rue(new string(ASRESSE_INCONNU));
	set_Localite(new string(ASRESSE_INCONNU));
	set_Numero(0);
	set_Boite(0);
	set_Code_Postal(0);
}

Adresse::Adresse(Adresse& adresse)
{
	CompteurAdresse++;
	AdresseEnVie++;

	InitializeString();
	
	set_Id_Adresse(adresse.ID_Adresse);
	set_Localite(adresse.Localite);
	set_Rue(adresse.Rue);
	set_Numero(adresse.Numero);
	set_Boite(adresse.Boite);
	set_Code_Postal(adresse.Code_Postal);
}

Adresse::Adresse(string* localite, string* rue, int numero, char boite, int code_postal)
{

	CompteurAdresse++;
	AdresseEnVie++;

	InitializeString();

	set_Id_Adresse(new string(ASRESSE_ADRESSE + CompteurAdresse));
	set_Localite(localite);
	set_Rue(rue);
	set_Numero(numero);
	set_Boite(boite);
	set_Code_Postal(code_postal);

}


// ------------ Destructeur ------------ 

Adresse::~Adresse()
{
	AdresseEnVie--;
	cout << ASRESSE_INSTANCE << AdresseEnVie << endl;
	delete ID_Adresse;
	delete Localite;
	delete Rue;
}

// ------------ Seteur ------------ 

void Adresse::set_Id_Adresse(string* id_adresse)
{
	ID_Adresse = id_adresse;
}

void Adresse::set_Localite(string* localite)
{
	Localite = localite;
}

void Adresse::set_Rue(string* rue)
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

string* Adresse::get_Id_Adresse(void)
{
	return ID_Adresse;
}

// ------------ Geteur ------------ 

string* Adresse::get_Localite(void)
{
	return Localite;
}

string* Adresse::get_Rue(void)
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

void Adresse::InitializeString()
{
	ID_Adresse = new string;
	Localite = new string;
	Rue = new string;
}
