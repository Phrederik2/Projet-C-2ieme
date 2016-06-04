#include "Livraison.h"



Livraison::Livraison()
{
	setTitle("Livraison");
}


Livraison::~Livraison()
{
}

void Livraison::setName(const char * value)
{
	Name = value;
}

const char * Livraison::getName()
{
	return Name.getText();
}
