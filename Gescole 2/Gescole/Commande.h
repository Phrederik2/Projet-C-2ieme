#pragma once
#include "DropdownList.h"
class Commande :
	public DropdownList<Commande>
{
protected:
	PrimaryKey<Commande> ID;
public:
	Commande();
	~Commande();

};

