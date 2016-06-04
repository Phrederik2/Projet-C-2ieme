#pragma once
#include "DropdownList.h"
class Livraison :
	public DropdownList<Livraison>
{
public:
	Livraison();
	~Livraison();

	void setName(const char* value);

	const char* getName();
};
