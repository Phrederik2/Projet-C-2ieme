#pragma once
#include "ContainerEntity.h"
#include<iostream>
using namespace std;
class StatutLivraison :
	public ContainerEntity
{
	//DataMembre.
protected:
	PrimaryKey<StatutLivraison> ID;
	Text Name;

public:
	//Constructeur
	StatutLivraison();// normal
	StatutLivraison(StatutLivraison& other); // recopie
	~StatutLivraison(); // destructeur

					  //Seteur.
	void setName(const char* name);

					  //Getteur
	const char* getName();

	

	unsigned long getID();
	unsigned long getAlive();

	//Function membre.
	void Display(std::ostream& stream = std::cout);
	void Encode();

	//Surcharge operateur
	StatutLivraison& operator=(StatutLivraison& other);
	friend ostream& operator<<(ostream& COUT, StatutLivraison& other);
};

