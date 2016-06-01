#pragma once
#include "DropdownList.h"
class Commande :
	public DropdownList
{
protected:
	PrimaryKey<Commande> ID;
public:
	Commande();
	~Commande();

};

