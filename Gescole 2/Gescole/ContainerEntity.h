#pragma once
#include<iostream>
#include"Title.h"
#include"PrimaryKey.h"
#include"Text.h"
#include"Date.h"
#include"ZoneSaisie.h"


class ContainerEntity
{
			//DataMembre.
protected:
	PrimaryKey<ContainerEntity> ID;
	//Text text;
public:
	bool IsNew;
	bool IsChanged;
	bool IsDelete;

public:
			//Constructeur
	ContainerEntity(); // normal
	//ContainerEntity(ContainerEntity& other); // recopie
	virtual ~ContainerEntity(); // destructeur

			//Seteur.

			//Getteur.
	

	virtual unsigned long getID()=0;
	virtual unsigned long getAlive()=0;

			//Function membre.

			//Surcharge operateur
	//ContainerEntity& operator=(ContainerEntity& other);
	//friend ostream& operator<<(ostream& stream, ContainerEntity& other);
};

