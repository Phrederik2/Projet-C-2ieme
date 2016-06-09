#pragma once
#include "ContainerEntity.h"
#include"Text.h"
#include"PrimaryKey.h"

class Client :
	public ContainerEntity
{
	//DataMenbre
protected:
	static Text Title;
	PrimaryKey<Client> ID;
	Text Nom;
	Text Prenom;
	Text Societe;
	Text Localite;
	Text Rue;
	int Numero;
	char Boite;
	int CodePostal;


public:
	Client();
	Client(Client& other);
	~Client();

	void setTitle(const char* title);
	void setID(int id);
	void setNom(const char* nom);
	void setPrenom(const char* prenom);
	void setSociete(const char* societe);
	void setLocalite(const char* localite);
	void setRue(const char* rue);
	void setNumero(int numero);
	void setBoite(char boite);
	void setCodePostal(int codepostal);

	const char* getTitle();
	const char* getNom();
	const char* getPrenom();
	const char* getSociete();
	unsigned long getID();
	const char* getLocalite();
	const char* getRue();
	int getNumero();
	char getBoite();
	int getCodePostal();
	unsigned long getAlive();

	Client& operator=(Client& other);
};
