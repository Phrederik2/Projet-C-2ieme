#pragma once
#include<iostream>
#include"PrimaryKey.h"
class ContainerEntity
{
protected:
	
	PrimaryKey<ContainerEntity> ID;

public:
	//Constructeur
	ContainerEntity();// normal
	//ContainerEntity(ContainerEntity& other); // recopie

	virtual ~ContainerEntity(); // destructeur

	virtual unsigned long getID()=0;
	virtual unsigned long getAlive()=0;
	virtual void Display(std::ostream& stream = std::cout)=0;
	virtual void Encode()=0;
	//Adresse& operator=(Adresse& other);
	//virtual friend ostream& operator<<(ostream& COUT, Adresse& other) ;
};

