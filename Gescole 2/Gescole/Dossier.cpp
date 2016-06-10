#include "Dossier.h"

Text Dossier::Title;

Dossier::Dossier()
{
	ID_Client = 0;
	ID_Commande = 0;
	ID_Livraison = 0;
	ID_RDV = 0;
	setTitle("Dossier");
}

Dossier::Dossier(Dossier & other)
{
	if (this == &other)return;
	*this = other;
}


Dossier::~Dossier()
{
}


void Dossier::setID(int id)
{
	ID.setPrimaryKey(id);
}

void Dossier::setID_Client(unsigned int id_client)
{
	ID_Client = id_client;
}

void Dossier::setID_Commande(unsigned int id_commande)
{
	ID_Commande =id_commande;
}

void Dossier::setID_Livraison(unsigned int id_livraison)
{
	ID_Livraison = id_livraison;
}

void Dossier::setID_RDV(unsigned int id_rdv)
{
	ID_RDV = id_rdv;
}

void Dossier::setTitle(const char * title)
{
	Title.setText(title);
}

unsigned int Dossier::getID_Client()
{
	return ID_Client;
}

unsigned int Dossier::getID_Commande()
{
	return ID_Commande;
}

unsigned int Dossier::getID_Livraison()
{
	return ID_Livraison;
}

unsigned int Dossier::getID_RDV()
{
	return ID_RDV;
}

const char * Dossier::getTitle()
{
	return Title.getText();
}

unsigned long Dossier::getID()
{
	return ID.getPrimaryKey();
}

unsigned long Dossier::getAlive()
{
	return ID.getAlive();
}

Dossier & Dossier::operator=(Dossier & other)
{
	if (this == &other)return *this;
	ID_Client = other.ID_Client;
	ID_Commande = other.ID_Commande;
	ID_Livraison = other.ID_Livraison;
	ID_RDV = other.ID_RDV;
	return *this;
}

