#pragma once
#include "DropdownList.h"
class Livraison :
	public DropdownList<Livraison>
{
protected:
public:
	Livraison();
	~Livraison();
};
