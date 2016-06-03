#pragma once
#include "ContainerEntity.h"
class Dossier :
	public ContainerEntity
{
	//DataMembre.
protected:
	static Text Title;
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
	void setID_Client(unsigned int id_client);
	void setID_Commande(unsigned int id_commande);
	void setID_Livraison(unsigned int id_livraison);
	void setID_RDV(unsigned int id_rdv);
	void setTitle(const char* title);

	//Getteur.
	unsigned int getID_Client();
	unsigned int getID_Commande();
	unsigned int getID_Livraison();
	unsigned int getID_RDV();
	const char* getTitle();


	unsigned long getID() ;
	unsigned long getAlive();

	//Function membre.
	void Display(std::ostream& stream = std::cout);
	void Encode();

	//Surcharge operateur
	Dossier& operator=(Dossier& other);
	friend ostream& operator<<(ostream& stream, Dossier& other);
};

