#pragma once
#include "ContainerEntity.h"
#include<iostream>
using namespace std;
class DropdownList :
	protected ContainerEntity
{
	//DataMembre.
protected:
	Title<DropdownList> Titre;
	//PrimaryKey<DropdownList> ID;
	Text Name;

public:
	//Constructeur
	DropdownList();// normal
	DropdownList(DropdownList& other); // recopie
	~DropdownList(); // destructeur

					  //Seteur.
	void setTitle(const char* title);
	void setName(const char* name);

					  //Getteur
	const char* getTitle();
	const char* getName();

	

	unsigned long getID();
	unsigned long getAlive();

	//Function membre.
	void Display(std::ostream& stream = std::cout);
	void Encode();

	//Surcharge operateur
	DropdownList& operator=(DropdownList& other);
	friend ostream& operator<<(ostream& COUT, DropdownList& other);
};

