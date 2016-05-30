#pragma once
#include"Menu.h"
#include"form_adresse.h"
template <class ENTITY>
class Application
{

protected:
	Menu* MMenu;
	bool Again;
	Container<ENTITY> Container;
	Form_Adresse<ENTITY> Frm;
	ENTITY* Temp;

public:
	Application();
	~Application();
	void setMenu(Menu* menu);
	void run();
	void Create();
	void Read();
	void Update();
	void Delete();
	void DeleteAll();
	void List();
	void First();
	void Next();
	void Last();
	void Previous();
	void Sort();
	void Shearch();
	void Error();
	void Quit();
	void Bydefault();

protected:
	void Controller(enum_Menu menu);
};
