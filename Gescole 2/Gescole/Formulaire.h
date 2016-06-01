#pragma once

#include "Message.h"
#include <iostream>
#include "ZoneSaisie.h"

template<class ENTITY>
class Formulaire
{
public:

	void operator<<(ENTITY& other);
	void operator>>(ENTITY& other);

};


template<class ENTITY>
void Formulaire<ENTITY>::operator<<(ENTITY& other)
{
	if (&other)
	{
		other.Display();
	}

}

template<class ENTITY>
void Formulaire<ENTITY>::operator >> (ENTITY& other)
{
	if (!other)
	{
		cout << "Aucun enregistrement selectionné !"<< endl;
		return;
	}
	other.Encode();
}

