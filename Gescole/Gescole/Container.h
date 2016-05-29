#pragma once

#include<vector>
#include"Professeur.h"
#include<iostream>
using namespace std;

template<class ENTITY>
class Container
{
public:
	const Container<ENTITY>& operator=(const Container<ENTITY>& other);
	Container();
	Container(const Container<ENTITY>& other);
	~Container();
	ENTITY* Add(ENTITY* other);
	ENTITY* First();
	ENTITY* Last();
	ENTITY* Next();
	ENTITY* Previous();
	Container<ENTITY>& Duplication(const Container<ENTITY>& other);
	bool Flush();
	size_t Size() const;
	bool isOwner();
	Container<ENTITY>* getOwner();
	void setMaster();
	void setOwner();

protected:
	ENTITY* Find(ENTITY* other);
	

protected:
	static double inLife;
	static Container<ENTITY>* idOwner;
	typename vector<ENTITY*> m_container;
	typename vector<ENTITY*>::iterator m_it;

};

