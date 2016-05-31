#pragma once

#include "Message.h"
#include <iostream>
#include "ZoneSaisie.h"

template<class ENTITY>
class Formulaire
{
public:

	void operator<<(ENTITY& Prof);
	void operator>>(ENTITY& Prof);

};


template<class ENTITY>
void Formulaire<ENTITY>::operator<<(ENTITY& Prof)
{
	if (&Prof)
	{
		Prof.Display();
	}

}

template<class ENTITY>
void Formulaire<ENTITY>::operator >> (ENTITY& Prof)
{
	Prof.Encode();
}

