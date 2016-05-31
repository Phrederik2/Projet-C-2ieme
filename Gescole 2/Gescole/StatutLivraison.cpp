#include "StatutLivraison.h"

StatutLivraison::StatutLivraison()
{
}

StatutLivraison::StatutLivraison(StatutLivraison & other)
{
}

StatutLivraison::~StatutLivraison()
{
}

void StatutLivraison::setName(const char * name)
{
	Name = name;
}

const char * StatutLivraison::getName()
{
	return Name.getText();
}

unsigned long StatutLivraison::getID()
{
	return ID.getPrimaryKey();
}

unsigned long StatutLivraison::getAlive()
{
	return ID.getAlive();
}

void StatutLivraison::Display(std::ostream & stream)
{
	stream << ID.getPrimaryKey() << endl;
	stream << Name.getText() << endl;
	
}

void StatutLivraison::Encode()
{
	ZoneSaisie zs;
	cout << "ID: " << getID() << endl;
	cout << "Statut: " << endl;
	if (zs.Ask()) setName(zs.ValString());
}

StatutLivraison & StatutLivraison::operator=(StatutLivraison & other)
{
	if (this == &other);
	Name = other.Name;
	return *this;
}

ostream & operator<<(ostream & stream, StatutLivraison & other)
{
	other.Display(stream);
	return stream;
}
