#pragma once
#include"Client.h"
#include"Application.h"

template<class ENTITY>
class Search
{
public:

	ENTITY* ReturnValue(int id);
	Search();
	~Search();
};

template<class ENTITY>
inline ENTITY* Search<ENTITY>::ReturnValue(int id)
{
	Application<ENTITY>	app;
	ENTITY* temp;
	temp = app.First();

	while (temp)
	{
		if (temp->getID() == id) return temp;
		temp = app.Next();
	}

	return NULL;
}

template<class ENTITY>
Search<ENTITY>::Search()
{
}

template<class ENTITY>
Search<ENTITY>::~Search()
{
}


