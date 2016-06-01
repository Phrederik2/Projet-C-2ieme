#pragma once
#include "ContainerEntity.h"
class RendezVous :
	public ContainerEntity
{
	//DataMembre.
protected:
	Title<RendezVous> m_Title;
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
	void setTitle(const char* title);
	void setDateDebut(int day, int month, int year);
	void setDateFin(int day, int month, int year);
	void setRemark(const char* remark);



					//Getteur.
	const char* getTitle();
	const char* getDateDebut();
	const char* getDateFin();
	const char* getRemark();

	unsigned long getID();
	unsigned long getAlive();

	//Function membre.
	void Display(std::ostream& stream = std::cout);
	void Encode();

	//Surcharge operateur
	RendezVous& operator=(RendezVous& other);
	friend ostream& operator<<(ostream& stream, RendezVous& other);
};

