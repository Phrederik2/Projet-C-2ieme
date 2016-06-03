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
	//Text Title;
	PrimaryKey<ContainerEntity> ID;
	//Text text;

public:
			//Constructeur
	ContainerEntity(); // normal
	//ContainerEntity(ContainerEntity& other); // recopie
	virtual ~ContainerEntity(); // destructeur

			//Seteur.
	virtual void setTitle(const char* title)=0;

			//Getteur.
	virtual const char* getTitle()=0;
	

	virtual unsigned long getID()=0;
	virtual unsigned long getAlive()=0;

			//Function membre.
	virtual void Display(std::ostream& stream = std::cout)=0;
	virtual void Encode()=0;

			//Surcharge operateur
	//ContainerEntity& operator=(ContainerEntity& other);
	//friend ostream& operator<<(ostream& stream, ContainerEntity& other);
};

