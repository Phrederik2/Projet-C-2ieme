#pragma once
#ifndef ADRESSE_H
#define ADRESSE_H
#include<string>

#define TAILLE_STD 50
#define TAILLE_GRD TAILLE_STD*2
using namespace std;

class Adresse
{

protected:
	static unsigned long CompteurAdresse;
	static unsigned long AdresseEnVie;
	string* ID_Adresse;
	string* Localite;
	string* Rue;
	int Numero;
	char Boite;
	int Code_Postal;


public:
	Adresse();
	Adresse(Adresse& adresse);
	Adresse(string* localite, string* rue, int numero, char boite, int code_postal);
	~Adresse();


	// ------------ Seteur ------------ 
	void set_Id_Adresse(string* id_adresse);
	void set_Localite(string* localite);
	void set_Rue(string* rue);
	void set_Numero(int numero);
	void set_Boite(char boite);
	void set_Code_Postal(int code_postal);

	// ------------ Geteur ------------ 

	string* get_Id_Adresse(void);
	string* get_Localite(void);
	string* get_Rue(void);
	int get_Numero(void);
	char get_Boite(void);
	int get_Code_Postal(void);

	// ------------ Fonction ------------
	void InitializeString();
};

#endif // !ADRESSE_H
