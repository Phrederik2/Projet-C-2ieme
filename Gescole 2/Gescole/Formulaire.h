#pragma once
#include"Client.h"
#include"Livraison.h"
#include"Commande.h"
#include"RendezVous.h"
#include"Dossier.h"
#include "Message.h"
#include <iostream>
#include "ZoneSaisie.h"
#include"Search.h"

template<class ENTITY>
class Formulaire
{
public:
	ZoneSaisie zs;

	void operator<<(ENTITY* other);
	void operator>>(ENTITY* other);

	void Display(ostream& stream, Client* other);
	void Display(ostream& stream, Livraison* other);
	void Display(ostream& stream, Commande* other);
	void Display(ostream& stream, RendezVous* other);
	void Display(ostream& stream, Dossier* other);

	void DisplayClient(ostream& stream, Dossier* other);
	void DisplayLivraison(ostream& stream, Dossier* other);
	void DisplayCommande(ostream& stream, Dossier* other);
	void DisplayRendezVous(ostream& stream, Dossier* other);

	void Encode(Client* other);
	void Encode(Livraison* other);
	void Encode(Commande* other);
	void Encode(RendezVous* other);
	void Encode(Dossier* other);
	void Encode(Date* other);


};


template<class ENTITY>
void Formulaire<ENTITY>::operator<<(ENTITY* other)
{
	if (other) Display(cout, other);
}

template<class ENTITY>
void Formulaire<ENTITY>::operator>>(ENTITY* other)
{
	if (other) Encode(other);	
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Display(ostream & stream, Client * other)
{
	stream << "ID: " << other->getID() << endl;
	stream << "Nom: " << other->getNom() << endl;
	stream << "Prenom: " << other->getPrenom() << endl;
	stream << "Societe: " << other->getSociete() << endl;
	stream << "Localite: " << other->getLocalite() << endl;
	stream << "Rue: " << other->getRue() << endl;
	stream << "Numero: " << other->getNumero() << endl;
	stream << "Boite: " << other->getBoite() << endl;
	stream << "Code Postal: " << other->getCodePostal() << endl;
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Display(ostream & stream, Livraison * other)
{
	stream << "ID: " << other->getID() << endl;
	stream << "Statut: " << other->getName() << endl;
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Display(ostream & stream, Commande * other)
{
	stream << "ID: " << other->getID() << endl;
	stream << "Statut: " << other->getName() << endl;
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Display(ostream & stream, RendezVous * other)
{
	stream << "ID:" << other->getID() << endl;
	stream << "Date de debut: " << other->getDateDebut() << endl;
	stream << "Date de fin: " << other->getDateFin() << endl;
	stream << "Requarque: " << other->getRemark() << endl;
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Display(ostream & stream, Dossier * other)
{
	stream << "ID: " << other->getID() << endl;
	stream << "Client: " << other->getID_Client() << endl;
	DisplayClient(stream, other);
	stream << "RDV: " << other->getID_RDV() << endl;
	DisplayRendezVous(stream, other);
	stream << "Livraison: " << other->getID_Livraison() << endl;
	DisplayLivraison(stream, other);
	stream << "Commande: " << other->getID_Commande() << endl;
	DisplayCommande(stream, other);
}


template<typename ENTITY>
inline void Formulaire<ENTITY>::DisplayClient(ostream& stream, Dossier * other)
{
	Client* temp;
	temp = Search<Client>::ReturnValue(other->getID_Client());
	if (temp)
	{
		stream << temp->getNom() << " " << temp->getPrenom() << endl;
		stream << temp->getSociete() << endl;
		stream << temp->getRue() << " " << temp->getNumero() << temp->getBoite() << ", " << temp->getCodePostal() <<" " << temp->getLocalite() << endl;
	}
}

template<class ENTITY>
inline void Formulaire<ENTITY>::DisplayLivraison(ostream & stream, Dossier * other)
{
	Livraison* temp;
	temp = Search<Livraison>::ReturnValue(other->getID_Livraison());
	if (temp)
	{
		stream << temp->getName() << endl;
	}
}

template<class ENTITY>
inline void Formulaire<ENTITY>::DisplayCommande(ostream & stream, Dossier * other)
{
	Commande* temp;
	temp = Search<Commande>::ReturnValue(other->getID_Commande());
	if (temp)
	{
		stream << temp->getName() << endl;
	}
}

template<class ENTITY>
inline void Formulaire<ENTITY>::DisplayRendezVous(ostream & stream, Dossier * other)
{
	RendezVous* temp;
	temp = Search<RendezVous>::ReturnValue(other->getID_RDV());
	if (temp)
	{
		stream << "Debut: " << temp->getDateDebut() << " Fin: " << temp->getDateFin();
	}
}


template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(Client * other)
{
	cout << "ID: " << other->getID() << endl;
	cout << "Nom: " << endl;
	if (zs.Ask()) other->setNom(zs.ValString());
	cout << "Prenom: " << endl;
	if (zs.Ask()) other->setPrenom(zs.ValString());
	cout << "Societe: " << endl;
	if (zs.Ask()) other->setSociete(zs.ValString());
	cout << "Localite: " << endl;
	if (zs.Ask()) other->setLocalite(zs.ValString());
	cout << "Rue: " << endl;
	if (zs.Ask()) other->setRue(zs.ValString());
	cout << "Numero: " << endl;
	if (zs.Ask()) other->setNumero(zs.ValInt());
	cout << "Boite: " << endl;
	if (zs.Ask()) other->setBoite(zs.ValChar());
	cout << "Code Postal: " << endl;
	if (zs.Ask()) other->setCodePostal(zs.ValInt());

	cout << "------------------" << endl;
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(Livraison * other)
{
	cout << "ID: " << other->getID() << endl;
	cout << "Statut: " << endl;
	if (zs.Ask()) other->setName(zs.ValString());
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(Commande * other)
{
	cout << "ID: " << other->getID() << endl;
	cout << "Statut: " << endl;
	if (zs.Ask()) other->setName(zs.ValString());
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(RendezVous * other)
{
	cout << "ID: " << other->getID() << endl;
	cout << "Date de debut: " << endl;
	Encode(other->setDateDebut());
	cout << "Date de fin: " << endl;
	Encode(other->setDateFin());
	cout << "Requarque: " << endl;
	if (zs.Ask()) other->setRemark(zs.ValString());
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(Dossier * other)
{
	Client* client;
	Commande* commande;
	Livraison* livraison;
	RendezVous* rendezvous;

	cout << "ID: " << other->getID() << endl;
	cout << "Client: " << endl;
	cout << endl;
	client = Application<Client>::Run(1);
	other->setID_Client(client->getID());
	cout << "Commande: " << endl;
	commande = Application<Commande>::Run(1);
	other->setID_Commande(commande->getID());
	cout << "Livraison: " << endl;
	livraison = Application<Livraison>::Run(1);
	other->setID_Livraison(commande->getID());
	cout << "Rendez-vous: " << endl;
	rendezvous = Application<RendezVous>::Run(1);
	other->setID_RDV(commande->getID());
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(Date * other)
{
	cout << "Jour: " << endl;
	if (zs.Ask()) other->setDay(zs.ValUInt());
	cout << "Mois: " << endl;
	if (zs.Ask()) other->setMonth(zs.ValUInt());
	cout << "Annee: " << endl;
	if (zs.Ask()) other->setYear(zs.ValUInt());
}
