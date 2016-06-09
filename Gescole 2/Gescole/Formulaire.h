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
#include"Stream.h"

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

	void DisplayClient(ostream& stream, Client* temp);
	void DisplayLivraison(ostream& stream, Livraison* temp);
	void DisplayCommande(ostream& stream, Commande* temp);
	void DisplayRendezVous(ostream& stream, RendezVous* temp);

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
	if (other->IsDelete)return;
	if (other)
	{
		cout << endl;
		Display(cout, other);
	}
}

template<class ENTITY>
void Formulaire<ENTITY>::operator>>(ENTITY* other)
{
	if (other->IsDelete)return;
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
	Client* client=NULL;
	Livraison* livraison=NULL;
	Commande* commande=NULL;
	RendezVous* rendezvous=NULL;
	Stream sql;
	stream << "ID: " << other->getID() << endl;
	stream << "Client: " << endl;
	sql.Write(other->getID_Client(), client, "client");
	DisplayClient(stream, client);
	stream << "RDV: "  << endl;
	sql.Write(other->getID_RDV(), rendezvous, "rendezvous");
	DisplayRendezVous(stream, rendezvous);
	stream << "Livraison: " << endl;
	sql.Write(other->getID_Livraison(), livraison, "livraison");
	DisplayLivraison(stream, livraison);
	stream << "Commande: " << endl;
	sql.Write(other->getID_Commande(), commande, "commande");
	DisplayCommande(stream, commande);
}


template<typename ENTITY>
inline void Formulaire<ENTITY>::DisplayClient(ostream& stream, Client * temp)
{
	
	if (temp)
	{
		stream << temp->getNom() << " " << temp->getPrenom() << endl;
		stream << temp->getSociete() << endl;
		stream << temp->getRue() << " " << temp->getNumero() << temp->getBoite() << ", " << temp->getCodePostal() <<" " << temp->getLocalite() << endl;
	}
}

template<class ENTITY>
inline void Formulaire<ENTITY>::DisplayLivraison(ostream & stream, Livraison * temp)
{
	if (temp)
	{
		stream << temp->getName() << endl;
	}
}

template<class ENTITY>
inline void Formulaire<ENTITY>::DisplayCommande(ostream & stream, Commande * temp)
{
	if (temp)
	{
		stream << temp->getName() << endl;
	}
}

template<class ENTITY>
inline void Formulaire<ENTITY>::DisplayRendezVous(ostream & stream, RendezVous * temp)
{
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

	cout << "ID: " << other->getID() << endl;
	cout << "Client: " << endl;
	cout << endl;
	other->setID_Client(Application<Client>::Run(1));
	cout << "Commande: " << endl;
	other->setID_Commande(Application<Commande>::Run(1));
	cout << "Livraison: " << endl;
	other->setID_Livraison(Application<Livraison>::Run(1));
	cout << "Rendez-vous: " << endl;
	other->setID_RDV(Application<RendezVous>::Run(1));
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
