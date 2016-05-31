#pragma once
#include "ContainerEntity.h"
#include<iostream>
using namespace std;
class StatutLivraison :
	public ContainerEntity
{
protected:
	//static double Alive;
	//static double Compter;
public:
	StatutLivraison();
	~StatutLivraison();
	double getAlive();
	void Display(std::ostream& stream = std::cout);
	void Encode();
	friend ostream& operator<<(ostream& COUT, StatutLivraison& other) ;
};

