#pragma once
#include "adresse.h"
#include <string>
#include <iostream>
#include "form_adresse.h"
#include "Message.h"
#include "ZoneSaisie.h"

using namespace std;


ostream & operator<<(ostream & COUT, Adresse & adresse)
{
	
	Form_Adresse frm;

	frm.View_Adresse(adresse);
	
	return (COUT);
}


void Form_Adresse::operator<<(Adresse & adresse)
{
	cout << adresse;
}

void Form_Adresse::operator>>(Adresse & adresse)
{

	Encode_Adresse(adresse);

}

void Form_Adresse::View_Adresse(Adresse & adresse)
{
	
	cout << endl;
	cout << ADRESSE_ID << ADRESSE_DEUXPOINT << adresse.get_Id_Adresse() << endl;
	cout << ASRESSE_LOCALITE << ADRESSE_DEUXPOINT << adresse.get_Localite() << endl;
	cout << ASRESSE_RUE << ADRESSE_DEUXPOINT << adresse.get_Rue() << endl;
	cout << ASRESSE_NUMERO << ADRESSE_DEUXPOINT << adresse.get_Numero() << endl;
	cout << ASRESSE_BOITE << ADRESSE_DEUXPOINT << adresse.get_Boite() << endl;
	cout << ASRESSE_CODEPOSTAL << ADRESSE_DEUXPOINT << adresse.get_Code_Postal() << endl;
	cout << ASRESSE_LIGNE << endl;
}

void Form_Adresse::Encode_Adresse(Adresse & adresse)
{
	ZoneSaisie ZS;
	cout << endl;
	cout << ADRESSE_ID << ADRESSE_DEUXPOINT << adresse.get_Id_Adresse() << endl;
	cout << ASRESSE_LOCALITE << ADRESSE_DEUXPOINT << endl;
	
	if (ZS.Ask())adresse.set_Localite(ZS.ValString());
	cout << ASRESSE_RUE << ADRESSE_DEUXPOINT << endl;
	
	if (ZS.Ask())adresse.set_Rue(ZS.ValString());
	cout << ASRESSE_NUMERO << ADRESSE_DEUXPOINT << endl;
	
	if (ZS.Ask())adresse.set_Numero(ZS.ValInt());
	cout << ASRESSE_BOITE << ADRESSE_DEUXPOINT << endl;
	
	if (ZS.Ask())adresse.set_Boite(ZS.ValChar());
	cout << ASRESSE_CODEPOSTAL << ADRESSE_DEUXPOINT << endl;
	
	if (ZS.Ask())adresse.set_Code_Postal(ZS.ValULong());
	cout << ASRESSE_LIGNE << endl;
}
