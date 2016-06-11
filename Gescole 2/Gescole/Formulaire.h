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
#include"Lancer.h"
#include"Message.h"

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
	void Display(ostream& stream, Lancer* other);

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
	void Encode(Lancer* other);

	static void getTitle(string* title);

};


template<class ENTITY>
void Formulaire<ENTITY>::operator<<(ENTITY* other)
{
	
	if (other)
	{
		if (other->IsDelete)return;
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
	stream << Client_ID Pct_DeuxPoint << other->getID() << endl;
	stream << Client_Nom Pct_DeuxPoint << other->getNom() << endl;
	stream << Client_Prenom Pct_DeuxPoint << other->getPrenom() << endl;
	stream << Client_Societe Pct_DeuxPoint << other->getSociete() << endl;
	stream << Client_Localite Pct_DeuxPoint << other->getLocalite() << endl;
	stream << Client_Rue Pct_DeuxPoint << other->getRue() << endl;
	stream << Client_Numero Pct_DeuxPoint << other->getNumero() << endl;
	stream << Client_Boite Pct_DeuxPoint << other->getBoite() << endl;
	stream << Client_CodePostal Pct_DeuxPoint << other->getCodePostal() << endl;
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Display(ostream & stream, Livraison * other)
{
	stream << Livraison_ID Pct_DeuxPoint << other->getID() << endl;
	stream << Livraison_Statut Pct_DeuxPoint << other->getName() << endl;
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Display(ostream & stream, Commande * other)
{
	stream << Commande_ID Pct_DeuxPoint << other->getID() << endl;
	stream << Commande_Statut Pct_DeuxPoint << other->getName() << endl;
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Display(ostream & stream, RendezVous * other)
{
	stream << RDV_ID Pct_DeuxPoint << other->getID() << endl;
	stream << RDV_DateDebut Pct_DeuxPoint << other->getDateDebut() << endl;
	stream << RDV_DateFin Pct_DeuxPoint << other->getDateFin() << endl;
	stream << RDV_Remarque Pct_DeuxPoint << other->getRemark() << endl;
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Display(ostream & stream, Dossier * other)
{
	Client* client = new Client;
	Livraison* livraison = new Livraison;
	Commande* commande = new Commande;
	RendezVous* rendezvous = new RendezVous;
	Stream sql;
	stream << Dossier_ID Pct_DeuxPoint << other->getID() << endl;
	stream << Dossier_Client  Pct_DeuxPoint << endl;
	sql.Write(other->getID_Client(), client, "client");
	DisplayClient(stream, client);
	stream << Dossier_RDV Pct_DeuxPoint << endl;
	sql.Write(other->getID_RDV(), rendezvous, "rendezvous");
	DisplayRendezVous(stream, rendezvous);
	stream << Dossier_Livraison  Pct_DeuxPoint << endl;
	sql.Write(other->getID_Livraison(), livraison, "livraison");
	DisplayLivraison(stream, livraison);
	stream << Dossier_Commande  Pct_DeuxPoint << endl;
	sql.Write(other->getID_Commande(), commande, "commande");
	DisplayCommande(stream, commande);

	delete client;
	delete livraison;
	delete commande;
	delete rendezvous;
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Display(ostream & stream, Lancer * other)
{
}


template<typename ENTITY>
inline void Formulaire<ENTITY>::DisplayClient(ostream& stream, Client * temp)
{
	
	if (temp)
	{
		stream << temp->getNom() << Pct_Espace << temp->getPrenom() << endl;
		stream << temp->getSociete() << endl;
		stream << temp->getRue() << Pct_Espace << temp->getNumero() << temp->getBoite() << ", " << temp->getCodePostal() <<" " << temp->getLocalite() << endl;
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
		stream << RDV_Debut Pct_DeuxPoint << temp->getDateDebut() << RDV_Fin Pct_DeuxPoint << temp->getDateFin() << endl;
	}
}


template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(Client * other)
{
	cout << Client_ID Pct_DeuxPoint << other->getID() << endl;
	cout << Client_Nom Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setNom(zs.ValString());
	cout << Client_Prenom Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setPrenom(zs.ValString());
	cout << Client_Societe Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setSociete(zs.ValString());
	cout << Client_Localite Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setLocalite(zs.ValString());
	cout << Client_Rue Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setRue(zs.ValString());
	cout << Client_Numero Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setNumero(zs.ValInt());
	cout << Client_Boite Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setBoite(zs.ValChar());
	cout << Client_CodePostal Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setCodePostal(zs.ValInt());

}

template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(Livraison * other)
{
	cout << Livraison_ID Pct_DeuxPoint << other->getID() << endl;
	cout << Livraison_Statut Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setName(zs.ValString());
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(Commande * other)
{
	cout << Commande_ID Pct_DeuxPoint << other->getID() << endl;
	cout << Commande_Statut Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setName(zs.ValString());
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(RendezVous * other)
{
	cout << RDV_ID Pct_DeuxPoint << other->getID() << endl;
	cout << RDV_DateDebut Pct_DeuxPoint << endl;
	Encode(other->setDateDebut());
	cout << RDV_DateFin Pct_DeuxPoint << endl;
	Encode(other->setDateFin());
	cout << RDV_Remarque Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setRemark(zs.ValString());
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(Dossier * other)
{

	cout << Dossier_ID Pct_DeuxPoint << other->getID() << endl;
	cout << Dossier_Client Pct_DeuxPoint << endl;
	cout << endl;
	other->setID_Client(Application<Client>::Run(other->getID_Client()));
	cout << Dossier_Commande Pct_DeuxPoint << endl;
	other->setID_Commande(Application<Commande>::Run(other->getID_Commande()));
	cout << Dossier_Livraison Pct_DeuxPoint << endl;
	other->setID_Livraison(Application<Livraison>::Run(other->getID_Livraison()));
	cout << Dossier_RDV Pct_DeuxPoint << endl;
	other->setID_RDV(Application<RendezVous>::Run(other->getID_RDV()));
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(Date * other)
{
	cout << Date_Jour Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setDay(zs.ValUInt());
	cout << Date_Mois Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setMonth(zs.ValUInt());
	cout << Date_Annee Pct_DeuxPoint << endl;
	if (zs.Ask()) other->setYear(zs.ValUInt());
}

template<class ENTITY>
inline void Formulaire<ENTITY>::Encode(Lancer * other)
{
}

template<class ENTITY>
inline void Formulaire<ENTITY>::getTitle(string* title)
{
	string entity = typeid(ENTITY).name();

	if (entity.find("Lancer") != std::string::npos) *title = Titre_Lancer Pct_DeuxPoint;
	if (entity.find("Dossier") != std::string::npos) *title = Titre_Dossier Pct_DeuxPoint;
	if (entity.find("Livraison") != std::string::npos) *title = Titre_Livraison Pct_DeuxPoint;
	if (entity.find("Commande") != std::string::npos) *title = Titre_Commande Pct_DeuxPoint;
	if (entity.find("Client") != std::string::npos) *title = Titre_Client Pct_DeuxPoint;
	if (entity.find("RendezVous") != std::string::npos) *title = Titre_RDV Pct_DeuxPoint;

}
