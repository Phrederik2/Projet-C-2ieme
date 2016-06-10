#include"Application.h"
#include"TestUnitaire.h"
#include"Lancer.h"
#include<conio.h>

using namespace std;


#pragma warning (disable:4996) 


void main(void)
{
	//test
	//TestUnitaire::Run();
	
	Application<Lancer>::Run();
	
	_getch();

}
