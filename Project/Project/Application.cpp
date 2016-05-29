#include "Application.h"
#include "Adresse.h"
#include "form_adresse.h"
#include <iostream>
#include <string>
#include<vector>
#include"Menu_Adresse.h"



Application::Application()
{
	this->MenuStandart = NULL;
}


Application::~Application()
{
}

void Application::setMenu(Menu * menuStandart)
{
	if (menuStandart)
	{
		this->MenuStandart = menuStandart;
	}
}

void Application::run()
{
	if (!MenuStandart)
	{
		cout << "Pas de menu accocher à l'application en cours! " << endl;
		return;
	}

	this->Again = true;

	//Container<Adresse> Professeur;

	do
	{
		this->MenuStandart->display(cout);

		switch (this->MenuStandart->askChoice(cout))
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

void Application::Create()
{
	cout << "Create" << endl;
}

void Application::Read()
{
	cout << "Read" << endl;
}

void Application::Update()
{
	cout << "Update" << endl;
}

void Application::Delete()
{
	cout << "Delete" << endl;
}

void Application::DeleteAll()
{
	cout << "Delete All" << endl;
}

void Application::List()
{
	cout << "List" << endl;
}

void Application::First()
{
	cout << "First" << endl;
}

void Application::Next()
{
	cout << "Next" << endl;
}

void Application::Last()
{
	cout << "Last" << endl;
}

void Application::Previous()
{
	cout << "Previous" << endl;
}

void Application::Sort()
{
	cout << "Sort" << endl;
}

void Application::Shearch()
{
	cout << "Shearch" << endl;
}

void Application::Error()
{
	cout << "Error" << endl;
}

void Application::Quit()
{
	cout << "Quit" << endl;
	this->Again = false;
}

void Application::Bydefault()
{
}

void Application::Controller(enum_Menu mnemo)
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
	