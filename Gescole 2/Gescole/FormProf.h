#ifndef FORMPROF_H

#define FORMPROF_H

#include "Professeur.h"
#include <iostream>

class FormProf
{
public:

	void operator<<(Professeur& Prof);
	void operator>>(Professeur& Prof);

};



#endif