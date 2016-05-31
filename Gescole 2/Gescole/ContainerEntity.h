#pragma once
class ContainerEntity
{
protected:
	static double Alive;
	static double Compter;

public:
	ContainerEntity();
	virtual ~ContainerEntity();
	virtual double getAlive() =0;
	virtual void Display() =0;
	//virtual friend ostream& operator<<(ostream& COUT, Adresse& other) ;
};

