#include "DropdownList.h"

DropdownList::DropdownList()
{
}

DropdownList::DropdownList(DropdownList & other)
{

}

DropdownList::~DropdownList()
{
}

void DropdownList::setTitle(const char * title)
{
	Titre = title;
}

void DropdownList::setName(const char * name)
{
	Name = name;
}

const char * DropdownList::getTitle()
{
	return Titre.getTitle();
}

const char * DropdownList::getName()
{
	return Name.getText();
}

unsigned long DropdownList::getID()
{
	return ID.getPrimaryKey();
}

unsigned long DropdownList::getAlive()
{
	return ID.getAlive();
}

void DropdownList::Display(std::ostream & stream)
{
	stream << ID.getPrimaryKey() << endl;
	stream << Name.getText() << endl;
	
}

void DropdownList::Encode()
{
	ZoneSaisie zs;
	cout << "ID: " << getID() << endl;
	cout << "Statut: " << endl;
	if (zs.Ask()) setName(zs.ValString());
}

DropdownList & DropdownList::operator=(DropdownList & other)
{
	if (this == &other)return *this;
	Name = other.Name;
	return *this;
}

ostream & operator<<(ostream & stream, DropdownList & other)
{
	other.Display(stream);
	return stream;
}
