#pragma once
#include "DropdownList.h"
class Commande :
	public DropdownList<Commande>
{
public:
	Commande();
	~Commande();

	void setName(const char* value);

	const char* getName();

};

