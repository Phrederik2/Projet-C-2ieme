#pragma once
#include "ContainerEntity.h"
#include<chrono>
class RendezVous :
	public ContainerEntity
{
	//DataMembre.
protected:
	PrimaryKey<RendezVous> ID;
	Date DateDebut;
	Date DateFin;
	Text Remark;

public:
	//Constructeur
	RendezVous(); // normal
	RendezVous(RendezVous& other); // recopie
	~RendezVous(); // destructeur

					//Seteur.
	void setID(int id);
	void setDateDebut(int day, int month, int year);
	void setDateDebutYear(int year);
	void setDateDebutMonth(int month);
	void setDateDebutDay(int day);
	void setDateDebut(const char* date);
	void setDateFin(int day, int month, int year);
	void setDateFinYear(int year);
	void setDateFinMonth(int month);
	void setDateFinDay(int day);
	void setDateFin(const char* date);
	Date* setDateDebut();
	Date* setDateFin();
	void setRemark(const char* remark);



					//Getteur.
	const char* getDateDebut();
	int getDateDebutYear();
	int getDateDebutMonth();
	int getDateDebutDay();
	const char* getDateFin();
	int getDateFinYear();
	int getDateFinMonth();
	int getDateFinDay();
	const char* getRemark();

	unsigned long getID();
	unsigned long getAlive();

	//Function membre.
	

	//Surcharge operateur
	RendezVous& operator=(RendezVous& other);
};

