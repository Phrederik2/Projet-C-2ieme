#include "Application.h"
#include "Professeur.h"
#include "FormProf.h"
#include <iostream>
#include <string>
#include<vector>
#include"MenuProf.h"



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
	this->Again = true;
	
	Container<Professeur> Professeur;

	do
	{
		this->MenuStandart->display(cout);

		Controller(this->MenuStandart->askChoice(cout));

	} while (this->Again);

}

void Application::Controller(eMENU mnemo)
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

