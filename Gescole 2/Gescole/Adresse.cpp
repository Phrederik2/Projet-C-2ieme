#include "Adresse.h"
#include"ZoneSaisie.h"

double Adresse::Alive = 0;
double Adresse::Compter = 0;

Adresse::Adresse()
{
	Alive++;
	Compter++;
	ID = Alive;
	Numero = 0;
	Boite = ' ';
	CodePostal = 0;

}


Adresse::~Adresse()
{
	Alive--;
}

void Adresse::setLocalite(const char * localite)
{
	Localite.setText(localite);
}

void Adresse::setRue(const char * rue)
{
	Rue.setText(rue);
}

void Adresse::setNumero(int numero)
{
	Numero = numero;
}

void Adresse::setBoite(char boite)
{
	Boite = boite;
}

void Adresse::setCodePostal(int codepostal)
{
	CodePostal = codepostal;
}

int Adresse::getID()
{
	return ID;
}

const char * Adresse::getLocalite()
{
	return Localite.getText();
}

const char * Adresse::getRue()
{
	return Rue.getText();
}

int Adresse::getNumero()
{
	return Numero;
}

char Adresse::getBoite()
{
	return Boite;
}

int Adresse::getCodePostal()
{
	return CodePostal;
}

double Adresse::getAlive()
{
	return Alive;
}

void Adresse::Display(Adresse& other)
{
	cout << "ID: " << other.getID() << endl;
	cout << "Localite: " << other.getLocalite() << endl;
	cout << "Rue: " << other.getRue() << endl;
	cout << "Numero: " << other.getNumero() << endl;
	cout << "Boite: " << other.getBoite() << endl;
	cout << "Code Postal: " << other.getCodePostal() << endl;
}

void Adresse::Encode(Adresse & other)
{
	ZoneSaisie zs;

	cout << "ID: " << other.getID() << endl;
	cout << "Localite: " << endl;
	if (zs.Ask()) other.setLocalite(zs.ValString());
	cout << "Rue: " << endl;
	if (zs.Ask()) other.setRue(zs.ValString());
	cout << "Numero: " <<endl;
	if (zs.Ask()) other.setNumero(zs.ValInt());
	cout << "Boite: " <<  endl;
	if (zs.Ask()) other.setBoite(zs.ValChar());
	cout << "Code Postal: " <<  endl;
	if (zs.Ask()) other.setCodePostal(zs.ValInt());
	
	cout << "------------------" << endl;
}

ostream & operator<<(ostream & COUT, Adresse& other)
{
	other.Display(other);
	return COUT;
}
