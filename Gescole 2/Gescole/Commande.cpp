#include "Commande.h"



Commande::Commande()
{
}


Commande::~Commande()
{
}

void Commande::setName(const char * value)
{
	Name = value;
}

const char * Commande::getName()
{
	return Name.getText();
}


