#pragma once
#include"Menu.h"
#include"Container.h"
#include"Formulaire.h"

template<class ENTITY>
class Application
{

protected:
	Menu* MenuStandart;
	bool Again;
	Container<ENTITY> Container;
	Formulaire<ENTITY> Frm;
	ENTITY* Temp;

public:
	Application();
	~Application();
	virtual void setMenu(Menu* menuStandart);
	virtual void run();
	virtual void Create();
	virtual void Read();
	virtual void Update();
	virtual void Delete();
	virtual void DeleteAll();
	virtual void List();
	virtual void First();
	virtual void Next();
	virtual void Last();
	virtual void Previous();
	virtual void Sort();
	virtual void Shearch();
	virtual void Error();
	virtual void Quit();
	virtual void Bydefault();
protected:
	virtual void Controller(eMENU mnemo);
};



template <class ENTITY>
Application<ENTITY>::Application()
{
	this->MenuStandart = NULL;
}

template <class ENTITY>
Application<ENTITY>::~Application()
{
}

template <class ENTITY>
void Application<ENTITY>::setMenu(Menu * menuStandart)
{
	if (menuStandart)
	{
		this->MenuStandart = menuStandart;
	}
}

template <class ENTITY>
void Application<ENTITY>::run()
{
	this->Again = true;


	do
	{
		this->MenuStandart->display(cout);

		Controller(this->MenuStandart->askChoice(cout));

	} while (this->Again);

}

template <class ENTITY>
void Application<ENTITY>::Controller(eMENU mnemo)
{
	switch (mnemo)
	{

	case eCREATE:		Create();	break;
	case eREAD:			Read();		break;
	case eUPDATE:		Update();	break;
	case eDELETE:		Delete();	break;
	case eDELETEALL:	DeleteAll(); break;
	case eLIST:			List();		break;
	case eFIRST:		First();	break;
	case eNEXT:			Next();		break;
	case eLAST:			Last();		break;
	case ePREVIOUS:		Previous();	break;
	case eSORT:			Sort();		break;
	case eSEARCH:		Shearch();	break;
	case eERROR:		Error();	break;
	case eQUIT:			Quit();		break;
	default:			Bydefault(); break;

	}
}

template <class ENTITY>
void Application<ENTITY>::Delete()
{
	cout << "Delete" << endl;
}

template <class ENTITY>
void Application<ENTITY>::DeleteAll()
{
	cout << "Delete All" << endl;
}



template <class ENTITY>
void Application<ENTITY>::Sort()
{
	cout << "Sort" << endl;
}

template <class ENTITY>
void Application<ENTITY>::Shearch()
{
	cout << "Shearch" << endl;
}

template <class ENTITY>
void Application<ENTITY>::Error()
{
	cout << "Error" << endl;
}

template <class ENTITY>
void Application<ENTITY>::Quit()
{
	cout << "Quit" << endl;
	this->Again = false;
}

template <class ENTITY>
void Application<ENTITY>::Bydefault()
{
}

template <class ENTITY>
void Application<ENTITY>::Create()
{
	Temp = new Professeur;
	Container.Add(Temp);
	Frm >> *Temp;

}

template <class ENTITY>
void Application<ENTITY>::Update()
{
	Frm >> *Temp;
}

template <class ENTITY>
void Application<ENTITY>::List()
{
	this->Temp = this->Container.First();
	while (this->Temp)
	{
		Frm << *Temp;
		this->Temp = this->Container.Next();
	}
}

template <class ENTITY>
void Application<ENTITY>::First()
{
	this->Temp = this->Container.First();
	Frm << *this->Temp;
}

template <class ENTITY>
void Application<ENTITY>::Next()
{
	this->Temp = this->Container.Next();
	Frm << *this->Temp;
}

template <class ENTITY>
void Application<ENTITY>::Last()
{
	this->Temp = this->Container.Last();
	Frm << *this->Temp;
}

template <class ENTITY>
void Application<ENTITY>::Previous()
{
	this->Temp = this->Container.Previous();
	Frm << *this->Temp;
}

template <class ENTITY>
void Application<ENTITY>::Read()
{
	Frm << *Temp;
}




