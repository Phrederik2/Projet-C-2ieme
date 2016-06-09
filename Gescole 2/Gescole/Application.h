#pragma once
#include"List.h"
#include"Formulaire.h"
#include"Menu.h"
#include"Stream.h"

template<class ENTITY>
class Application
{

protected:
	Menu<ENTITY>* MenuStandart;
	bool Again;
	List<ENTITY> Container;
	Formulaire<ENTITY> Frm;
	ENTITY* Temp;

public:
	Application();
	~Application();

	int run(bool value= 0);
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
	static int Run(bool value = 0);
protected:
	void Controller(eMENU mnemo);
};

template <class ENTITY>
Application<ENTITY>::Application()
{
	Temp = NULL;
	MenuStandart = new Menu<ENTITY>;
	Stream stream;
	stream.Write(Container);
	First();
}

template <class ENTITY>
Application<ENTITY>::~Application()
{
	Stream stream;
	stream.Read(Container);
	delete MenuStandart;
}

template <class ENTITY>
int Application<ENTITY>::run(bool value)
{
	this->Again = true;


	do
	{
		this->MenuStandart->display(cout,value);

		Controller(this->MenuStandart->askChoice(cout));

	} while (this->Again);

	if (Temp) return Temp->getID();
	return 0;

}

template<class ENTITY>
inline ENTITY * Application<ENTITY>::Select()
{
	if (!Temp) return Temp;
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
	Temp->IsDelete = true;
	Temp->IsChanged = true;
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
	this->Again = false;
}

template <class ENTITY>
void Application<ENTITY>::Bydefault()
{
}

template<class ENTITY>
int  Application<ENTITY>::Run(bool value)
{
	Application appli;
	return appli.run(value);
	
}

template <class ENTITY>
void Application<ENTITY>::Create()
{
	Temp = new ENTITY;
	Temp->IsNew = true;
	Container.Add(Temp);
	Frm >> Temp;

}

template <class ENTITY>
void Application<ENTITY>::Update()
{
	if (!Temp)return;
	if(!Temp->IsNew) Temp->IsChanged = true;
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




