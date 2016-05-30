#pragma once
#include "adresse.h"
#include <string>
#include <iostream>
#include "form_adresse.h"
#include "Message.h"
#include "ZoneSaisie.h"
#include<iostream>

using namespace std;

template <class ENTITY>
ostream & operator<<(ostream & COUT, ENTITY & other)
{
	
	Form_Adresse<ENTITY> frm;

	frm.View_Adresse(other);
	
	return (COUT);
}

template <class ENTITY>
void Form_Adresse::operator<<(ENTITY & other)
{
	cout << other;
}

template <class ENTITY>
void Form_Adresse::operator>>(ENTITY & other)
{

	Encode_Adresse(other);

}

template <class ENTITY>
void Form_Adresse::View_Adresse(ENTITY & other)
{
	
	cout << endl;
	cout << ADRESSE_ID << ADRESSE_DEUXPOINT << other.get_Id_Adresse() << endl;
	cout << ADRESSE_LOCALITE << ADRESSE_DEUXPOINT << other.get_Localite() << endl;
	cout << ADRESSE_RUE << ADRESSE_DEUXPOINT << other.get_Rue() << endl;
	cout << ADRESSE_NUMERO << ADRESSE_DEUXPOINT << other.get_Numero() << endl;
	cout << ADRESSE_BOITE << ADRESSE_DEUXPOINT << other.get_Boite() << endl;
	cout << ADRESSE_CODEPOSTAL << ADRESSE_DEUXPOINT << other.get_Code_Postal() << endl;
	cout << ADRESSE_LIGNE << endl;
}

template <class ENTITY>
void Form_Adresse::Encode_Adresse(ENTITY & other)
{
	ZoneSaisie ZS;
	cout << endl;
	cout << ADRESSE_ID << ADRESSE_DEUXPOINT << other.get_Id_Adresse() << endl;
	cout << ADRESSE_LOCALITE << ADRESSE_DEUXPOINT << endl;
	
	if (ZS.Ask())other.set_Localite(ZS.ValString());
	cout << ADRESSE_RUE << ADRESSE_DEUXPOINT << endl;
	
	if (ZS.Ask())other.set_Rue(ZS.ValString());
	cout << ADRESSE_NUMERO << ADRESSE_DEUXPOINT << endl;
	
	if (ZS.Ask())other.set_Numero(ZS.ValInt());
	cout << ADRESSE_BOITE << ADRESSE_DEUXPOINT << endl;
	
	if (ZS.Ask())other.set_Boite(ZS.ValChar());
	cout << ADRESSE_CODEPOSTAL << ADRESSE_DEUXPOINT << endl;
	
	if (ZS.Ask())other.set_Code_Postal(ZS.ValULong());
	cout << ADRESSE_LIGNE << endl;
}
