#pragma once
#include<iostream>
#include"PrimaryKey.h"
#include"Text.h"
#include"ZoneSaisie.h"
class ContainerEntity
{
	//DataMembre.
protected:
	PrimaryKey<ContainerEntity> ID;
	Text text;

public:
	//Constructeur
	ContainerEntity(); // normal
	//ContainerEntity(ContainerEntity& other); // recopie
	virtual ~ContainerEntity(); // destructeur

	//Seteur.


	//Getteur

	

	virtual unsigned long getID()=0;
	virtual unsigned long getAlive()=0;

	//Function membre.
	virtual void Display(std::ostream& stream = std::cout)=0;
	virtual void Encode()=0;

	//Surcharge operateur
	//ContainerEntity& operator=(ContainerEntity& other);
	//virtual friend ostream& operator<<(ostream& stream, ContainerEntity& other);
};

