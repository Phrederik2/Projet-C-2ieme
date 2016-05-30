#ifndef PROFESSEUR_H
#include <iostream>

#define PROFESSEUR_H

#define prNOMLEN 50
#define prPRENOMLEN 50

class Professeur
{
protected:
	
	static unsigned long EnVie; // compteur de vie 
	static unsigned long Compteur; // compteur d'ID objets
	unsigned long idProfesseur;
	char* Nom;
	char* Prenom;
	unsigned int  AnneeNaissance;
	float SalaireMensuel_Eur;
	float Poids_Kg;

public:
		 Professeur(void);// Constructeur sans paramettres
		 Professeur(Professeur& prof);// Constructeur sans paramettres
		 Professeur(const char* nom,const char* prenom, unsigned int anneenaissance, float salairemensuel_eur, float poids_kg);// Constructeur sans paramettres

		~Professeur(void);// Destructeur sans paramettres

	void setNom (const char* nom);
	void setPrenom (const char* prenom);
	void setAnneeNaissance (unsigned int anneenaissance);
	void setSalaireMensuel_Eur (float salairemensuel_eur);
	void setPoids_Kg (float poids_kg);

	unsigned long getId(void);
	const char* getNom(void);
	const char* getPrenom(void);
	unsigned int getAnneeNaissance(void);
	float getSalaireMensuel_Eur(void);
	float getPoids_Kg(void);

	Professeur& operator = (Professeur& prof);

	void Display(Professeur Prof);

protected:
	void InitProfesseur(const char* nom, const char* prenom, unsigned int anneenaissance, float salairemensuel_eur, float poids_kg);// Constructeur sans paramettres
	
	

} ;

#endif