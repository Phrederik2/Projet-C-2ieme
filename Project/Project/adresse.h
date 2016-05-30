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
	int ID_Adresse;
	char* Localite;
	char* Rue;
	int Numero;
	char Boite;
	int Code_Postal;


public:
	Adresse();
	Adresse(Adresse& adresse);
	Adresse(char* localite, char* rue, int numero, char boite, int code_postal);
	~Adresse();


	// ------------ Seteur ------------ 
	void set_Id_Adresse(int id_adresse);
	void set_Localite(char* localite);
	void set_Rue(char* rue);
	void set_Numero(int numero);
	void set_Boite(char boite);
	void set_Code_Postal(int code_postal);

	// ------------ Geteur ------------ 

	int get_Id_Adresse(void);
	char* get_Localite(void);
	char* get_Rue(void);
	int get_Numero(void);
	char get_Boite(void);
	int get_Code_Postal(void);

	// ------------ Fonction ------------
	void Initialize(char* localite, char* rue, int numero, char boite, int code_postal);
};

#endif // !ADRESSE_H
