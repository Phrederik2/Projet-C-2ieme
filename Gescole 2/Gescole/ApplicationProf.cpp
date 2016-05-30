#include "ApplicationProf.h"


void ApplicationProf::Create()
{
	Temp = new Professeur;
	Container_Professeur.Add(Temp);
	Frm >> *Temp;

}

void ApplicationProf::List()
{
	this->Temp = this->Container_Professeur.First();
	while (this->Temp)
	{
		Frm << *Temp;
		this->Temp = this->Container_Professeur.Next();
	}
}

void ApplicationProf::First()
{
	this->Temp = this->Container_Professeur.First();
	Frm << *this->Temp;
}

void ApplicationProf::Next()
{
	this->Temp = this->Container_Professeur.Next();
	Frm << *this->Temp;
}

void ApplicationProf::Last()
{
	this->Temp = this->Container_Professeur.Last();
	Frm << *this->Temp;
}

void ApplicationProf::Previous()
{
	this->Temp = this->Container_Professeur.Previous();
	Frm << *this->Temp;
}

void ApplicationProf::Read()
{
	Frm << *Temp;
}
