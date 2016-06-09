
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

void Client::setID(int id)
{
	ID.setPrimaryKey(id);
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

