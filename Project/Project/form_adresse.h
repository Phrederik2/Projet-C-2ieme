#pragma once
#include <iostream>


using namespace std;
template <class ENTITY>
class Form_Adresse
{
friend
ostream & operator<<(ostream & COUT, ENTITY & other);

public:
	void operator<<(ENTITY & other);
	void operator>>(ENTITY & other);
	void View_Adresse(ENTITY& other);
	void Encode_Adresse(ENTITY& other);

private:

};





