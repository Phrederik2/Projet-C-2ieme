#pragma once
#include"Menu.cpp"
#include"Container.h"
#include"Formulaire.h"

template<class ENTITY>
class Application
{

protected:
	Menu<ENTITY> MenuStandart;
	bool Again;
	static Container<ENTITY> Container;
	Formulaire<ENTITY> Frm;
	ENTITY* Temp;

public:
	Application();
	~Application();

	void run();
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
	static void Run();
protected:
	void Controller(eMENU mnemo);
};

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
void Application<ENTITY>::run()
{
	this->Again = true;


	do
	{
		this->MenuStandart.display(cout);

		Controller(this->MenuStandart.askChoice(cout));

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
inline void Application<ENTITY>::Run()
{
	Application Appli;
	Appli.run();
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
	Frm << this->Temp;
	return Temp;
}

template <class ENTITY>
ENTITY* Application<ENTITY>::Next()
{
	this->Temp = this->Container.Next();
	Frm << this->Temp;
	return Temp;
}

template <class ENTITY>
ENTITY* Application<ENTITY>::Last()
{
	this->Temp = this->Container.Last();
	Frm << this->Temp;
	return Temp;
}

template <class ENTITY>
ENTITY* Application<ENTITY>::Previous()
{
	this->Temp = this->Container.Previous();
	Frm << this->Temp;
	return Temp;
}

template <class ENTITY>
void Application<ENTITY>::Read()
{
	Frm << Temp;
}




