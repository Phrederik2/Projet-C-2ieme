#pragma once
#include"Menu.h"

class Application
{

protected:
	Menu* MenuStandart;
	bool Again;

public:
	Application();
	~Application();
	void setMenu(Menu* menuStandart);
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
};
