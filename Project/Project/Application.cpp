#include "Application.h"
#include "Adresse.h"
#include "form_adresse.cpp"
#include <iostream>
#include <string>
#include<vector>
#include"Menu_Adresse.h"


template <class ENTITY>
Application::Application()
{
	this->menu = NULL;
}

template <class ENTITY>
Application::~Application()
{
}

template <class ENTITY>
void Application::setMenu(Menu * menu)
{
	if (menu)
	{
		this->MMEnu = menu;
	}
}

template <class ENTITY>
void Application::run()
{
	if (!MMEnu)
	{
		cout << "Pas de menu accocher à l'application en cours! " << endl;
		return;
	}

	this->Again = true;


	do
	{
		this->MMEnu->display(cout);

		switch (this->MMEnu->askChoice(cout))
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


	} while (this->Again);


}

template <class ENTITY>
void Application::Create()
{
	Temp = new ENTITY;
	Container.Add(Temp);
	//Frm >> *Temp;
}

template <class ENTITY>
void Application::Read()
{
	cout << "Read" << endl;
}

template <class ENTITY>
void Application::Update()
{
	cout << "Update" << endl;
}

template <class ENTITY>
void Application::Delete()
{
	cout << "Delete" << endl;
}

template <class ENTITY>
void Application::DeleteAll()
{
	cout << "Delete All" << endl;
}

template <class ENTITY>
void Application::List()
{
	cout << "List" << endl;
}

template <class ENTITY>
void Application::First()
{
	cout << "First" << endl;
}

template <class ENTITY>
void Application::Next()
{
	cout << "Next" << endl;
}

template <class ENTITY>
void Application::Last()
{
	cout << "Last" << endl;
}

template <class ENTITY>
void Application::Previous()
{
	cout << "Previous" << endl;
}

template <class ENTITY>
void Application::Sort()
{
	cout << "Sort" << endl;
}

template <class ENTITY>
void Application::Shearch()
{
	cout << "Shearch" << endl;
}

template <class ENTITY>
void Application::Error()
{
	cout << "Error" << endl;
}

template <class ENTITY>
void Application::Quit()
{
	cout << "Quit" << endl;
	this->Again = false;
}

template <class ENTITY>
void Application::Bydefault()
{
}

template <class ENTITY>
void Application::Controller(enum_Menu menu)
{
	switch (menu)
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
	