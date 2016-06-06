#pragma once
#include"Menu.cpp"
#include"Container.h"
#include"Formulaire.h"

template<class ENTITY>
class Application
{

protected:
	static Menu<ENTITY> MenuStandart;
	bool Again;
	static Container<ENTITY> Container;
	Formulaire<ENTITY> Frm;
	ENTITY* Temp;

public:
	Application();
	~Application();

	ENTITY* run(bool value= 0);
	ENTITY* Select();
	void Create();
	void Read();
	void Update();
	void Delete();
	void DeleteAll();
	void List();
	ENTITY* First();
	ENTITY* Next();
	ENTITY* Last();
	ENTITY* Previous();
	void Sort();
	void Search();
	void Error();
	void Quit();
	void Bydefault();
	static ENTITY* Run(bool value = 0);
protected:
	void Controller(eMENU mnemo);
};

template <class ENTITY>
Menu<ENTITY> Application<ENTITY>::MenuStandart;
template <class ENTITY>
Container<ENTITY> Application<ENTITY>::Container ;

template <class ENTITY>
Application<ENTITY>::Application()
{

}

template <class ENTITY>
Application<ENTITY>::~Application()
{
}

template <class ENTITY>
ENTITY* Application<ENTITY>::run(bool value)
{
	this->Again = true;


	do
	{
		this->MenuStandart.display(cout,value);

		Controller(this->MenuStandart.askChoice(cout));

	} while (this->Again);

	return Temp;

}

template<class ENTITY>
inline ENTITY * Application<ENTITY>::Select()
{
	Quit();
	return Temp;
}

template <class ENTITY>
void Application<ENTITY>::Controller(eMENU mnemo)
{
	switch (mnemo)
	{
	case eSELECT:		Select();	break;
	case eCREATE:		Create();	break;
	case eREAD:			Read();		break;
	case eUPDATE:		Update();	break;
	case eDELETE:		Delete();	break;
	case eDELETEALL:	DeleteAll(); break;
	case eLIST:			List();		break;
	case eFIRST:		Frm << First();  	break;
	case eNEXT:			Frm << Next();		break;
	case eLAST:			Frm << Last();		break;
	case ePREVIOUS:		Frm << Previous(); 	break;
	case eSORT:			Sort();		break;
	case eSEARCH:		Search();	break;
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
void Application<ENTITY>::Search()
{
	cout << "Search" << endl;
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

template<class ENTITY>
ENTITY*  Application<ENTITY>::Run(bool value)
{
	Application Appli;
	return Appli.run(value);
}

template <class ENTITY>
void Application<ENTITY>::Create()
{
	Temp = new ENTITY;
	Container.Add(Temp);
	Frm >> Temp;

}

template <class ENTITY>
void Application<ENTITY>::Update()
{
	Frm >> Temp;
}

template <class ENTITY>
void Application<ENTITY>::List()
{
	this->Temp = this->Container.First();
	if (Temp)
	{
		while (this->Temp)
		{
			Frm << Temp;
			this->Temp = this->Container.Next();
		}
	}
	
}

template <class ENTITY>
ENTITY* Application<ENTITY>::First()
{
	this->Temp = this->Container.First();
	return Temp;
}

template <class ENTITY>
ENTITY* Application<ENTITY>::Next()
{
	this->Temp = this->Container.Next();
	return Temp;
}

template <class ENTITY>
ENTITY* Application<ENTITY>::Last()
{
	this->Temp = this->Container.Last();
	return Temp;
}

template <class ENTITY>
ENTITY* Application<ENTITY>::Previous()
{
	this->Temp = this->Container.Previous();
	return Temp;
}

template <class ENTITY>
void Application<ENTITY>::Read()
{
	Frm << Temp;
}




