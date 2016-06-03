#include "Client.h"
#include"ZoneSaisie.h"

Text Client::Title;

Client::Client()
{
	Numero = 0;
	Boite = ' ';
	CodePostal = 0;
	setTitle("Client");

}

Client::Client(Client& other)
{
	*this = other;
}


Client::~Client()
{
}

void Client::setTitle(const char* title)
{
	Title.setText(title);
}

void Client::setNom(const char * nom)
{
	Nom.setText(nom);
}

void Client::setPrenom(const char * prenom)
{
	Prenom.setText(prenom);
}

void Client::setSociete(const char * societe)
{
	Societe.setText(societe);
}

void Client::setLocalite(const char * localite)
{
	Localite.setText(localite);
}

void Client::setRue(const char * rue)
{
	Rue.setText(rue);
}

void Client::setNumero(int numero)
{
	Numero = numero;
}

void Client::setBoite(char boite)
{
	Boite = boite;
}

void Client::setCodePostal(int codepostal)
{
	CodePostal = codepostal;
}

unsigned long Client::getID()
{
	return ID.getPrimaryKey();
}

const char * Client::getTitle()
{
	return Title.getText();
}

const char * Client::getNom()
{
	return Nom.getText();
}

const char * Client::getPrenom()
{
	return Prenom.getText();
}

const char * Client::getSociete()
{
	return Societe.getText();
}

const char * Client::getLocalite()
{
	return Localite.getText();
}

const char * Client::getRue()
{
	return Rue.getText();
}

int Client::getNumero()
{
	return Numero;
}

char Client::getBoite()
{
	return Boite;
}

int Client::getCodePostal()
{
	return CodePostal;
}

unsigned long Client::getAlive()
{
	return ID.getAlive();
}

void Client::Display(ostream& stream)
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

void Client::Encode()
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

Client & Client::operator=(Client & other)
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

ostream & operator<<(ostream & COUT, Client& other)
{
	other.Display(COUT);
	return COUT;
}
