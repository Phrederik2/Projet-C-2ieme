#pragma once
#include "ContainerEntity.h"
class Dossier :
	public ContainerEntity
{
	//DataMembre.
protected:
	PrimaryKey<Dossier> ID;
	unsigned int ID_Client;
	unsigned int ID_Commande;
	unsigned int ID_Livraison;
	unsigned int ID_RDV;

public:
	//Constructeur
	Dossier(); // normal
	Dossier(Dossier& other); // recopie
	virtual ~Dossier(); // destructeur

	//Seteur.
	void setID(int id);
	void setID_Client(unsigned int id_client);
	void setID_Commande(unsigned int id_commande);
	void setID_Livraison(unsigned int id_livraison);
	void setID_RDV(unsigned int id_rdv);

	//Getteur.
	unsigned int getID_Client();
	unsigned int getID_Commande();
	unsigned int getID_Livraison();
	unsigned int getID_RDV();

	unsigned long getID() ;
	unsigned long getAlive();

	//Function membre.

	//Surcharge operateur
	Dossier& operator=(Dossier& other);
};

