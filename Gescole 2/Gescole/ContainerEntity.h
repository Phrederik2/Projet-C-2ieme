#pragma once
#include<iostream>
class ContainerEntity
{
protected:
	static double Alive;
	static double Compter;

public:
	ContainerEntity();
	virtual ~ContainerEntity();
	virtual double getAlive()=0;
	virtual void Display(std::ostream& stream = std::cout)=0;
	virtual void Encode()=0;
	//virtual friend ostream& operator<<(ostream& COUT, Adresse& other) ;
};

