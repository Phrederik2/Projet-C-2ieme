#include"MenuProf.h"
#include"ApplicationProf.h"
#include<fstream>
#include<iostream>
#include"MultiType.h"
#include<conio.h>


using namespace std;


#pragma warning (disable:4996) 


void main(void)
{

	
	Menu menu("Test");
	ApplicationProf AppProf;

	AppProf.setMenu(&menu);
	AppProf.run();
	_getch();

}
