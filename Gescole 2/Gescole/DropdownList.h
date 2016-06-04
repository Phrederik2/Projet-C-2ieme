#pragma once
#include "ContainerEntity.h"
#include<iostream>
using namespace std;

template<class ENTITY>
class DropdownList :
	public ContainerEntity
{
	//DataMembre.
protected:
	static Text Title;
	PrimaryKey<ENTITY> ID;
	Text Name;

public:
	//Constructeur
	DropdownList();// normal
	DropdownList(ENTITY& other); // recopie
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

	//Surcharge operateur
	DropdownList& operator=(DropdownList& other);
};

template<class ENTITY>
Text DropdownList<ENTITY>::Title;

template<class ENTITY>
DropdownList<ENTITY>::DropdownList()
{
	Title = "DropdownList";
}

template<class ENTITY>
DropdownList<ENTITY>::DropdownList(ENTITY & other)
{

}

template<class ENTITY>
DropdownList<ENTITY>::~DropdownList()
{
}

template<class ENTITY>
void DropdownList<ENTITY>::setTitle(const char * title)
{
	Title = title;
}

template<class ENTITY>
void DropdownList<ENTITY>::setName(const char * name)
{
	Name = name;
}

template<class ENTITY>
const char * DropdownList<ENTITY>::getTitle()
{
	return Title.getText();
}

template<class ENTITY>
const char * DropdownList<ENTITY>::getName()
{
	return Name.getText();
}

template<class ENTITY>
unsigned long DropdownList<ENTITY>::getID()
{
	return ID.getPrimaryKey();
}

template<class ENTITY>
unsigned long DropdownList<ENTITY>::getAlive()
{
	return ID.getAlive();
}

template<class ENTITY>
DropdownList<ENTITY> & DropdownList<ENTITY>::operator=(DropdownList<ENTITY> & other)
{
	if (this == &other)return *this;
	Name = other.Name;
	return *this;
}
