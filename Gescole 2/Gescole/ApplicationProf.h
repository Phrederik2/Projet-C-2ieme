#pragma once
#include"Application.h"
#include"Container.cpp"
#include"Professeur.h"
#include"FormProf.h"
class ApplicationProf
	:public Application
{
protected:
	Container<Professeur> Container_Professeur;
	FormProf Frm;
	Professeur* Temp;


public:
	void Create();
	void List();
	void First();
	void Next();
	void Last();
	void Previous();
	void Read();

};

