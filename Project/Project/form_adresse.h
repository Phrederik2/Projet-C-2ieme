#pragma once
#include <iostream>


using namespace std;

class Form_Adresse
{
friend
ostream & operator<<(ostream & COUT, Adresse & adresse);

public:
	void operator<<(Adresse & adresse);
	void operator>>(Adresse & adresse);
	void View_Adresse(Adresse& adresse);
	void Encode_Adresse(Adresse& adresse);

private:

};





