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

