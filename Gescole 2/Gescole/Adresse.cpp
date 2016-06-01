#include "Adresse.h"
#include"ZoneSaisie.h"

Text Adresse::Title;

Adresse::Adresse()
{
	Numero = 0;
	Boite = ' ';
	CodePostal = 0;
	setTitle("Adresse");

}

Adresse::Adresse(Adresse& other)
{
	*this = other;
}


Adresse::~Adresse()
{
}

void Adresse::setTitle(const char* title)
{
	Title.setText(title);
}

void Adresse::setNom(const char * nom)
{
	Nom.setText(nom);
}

void Adresse::setPrenom(const char * prenom)
{
	Prenom.setText(prenom);
}

void Adresse::setSociete(const char * societe)
{
	Societe.setText(societe);
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

unsigned long Adresse::getID()
{
	return ID.getPrimaryKey();
}

const char * Adresse::getTitle()
{
	return Title.getText();
}

const char * Adresse::getNom()
{
	return Nom.getText();
}

const char * Adresse::getPrenom()
{
	return Prenom.getText();
}

const char * Adresse::getSociete()
{
	return Societe.getText();
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

unsigned long Adresse::getAlive()
{
	return ID.getAlive();
}

void Adresse::Display(ostream& stream)
{
	stream << "ID: " << getID() << endl;
	stream << "Nom: " << getNom() << endl;
	stream << "Prenom: " << getPrenom() << endl;
	stream << "Societe: " << getSociete() << endl;
	stream << "Localite: " << getLocalite() << endl;
	stream << "Rue: " << getRue() << endl;
	stream << "Numero: " << getNumero() << endl;
	stream << "Boite: " << getBoite() << endl;
	stream << "Code Postal: " << getCodePostal() << endl;
}

void Adresse::Encode()
{
	ZoneSaisie zs;

	cout << "ID: " << getID() << endl;
	cout << "Nom: " << endl;
	if (zs.Ask()) setNom(zs.ValString());
	cout << "Prenom: " << endl;
	if (zs.Ask()) setPrenom(zs.ValString());
	cout << "Societe: " << endl;
	if (zs.Ask()) setSociete(zs.ValString());
	cout << "Localite: " << endl;
	if (zs.Ask()) setLocalite(zs.ValString());
	cout << "Rue: " << endl;
	if (zs.Ask()) setRue(zs.ValString());
	cout << "Numero: " <<endl;
	if (zs.Ask()) setNumero(zs.ValInt());
	cout << "Boite: " <<  endl;
	if (zs.Ask()) setBoite(zs.ValChar());
	cout << "Code Postal: " <<  endl;
	if (zs.Ask()) setCodePostal(zs.ValInt());
	
	cout << "------------------" << endl;
}

Adresse & Adresse::operator=(Adresse & other)
{
	if (this == &other)return *this;

	setNom(other.getNom());
	setPrenom(other.getPrenom());
	setSociete(other.getSociete());
	setLocalite(other.getLocalite());
	setRue(other.getRue());
	setNumero(other.getNumero());
	setBoite(other.getBoite());
	setCodePostal(other.getCodePostal());
	return *this;
	
}

ostream & operator<<(ostream & COUT, Adresse& other)
{
	other.Display(COUT);
	return COUT;
}
