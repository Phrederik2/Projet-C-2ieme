#include "Professeur.h"
#include <string.h>
#include <iostream>
#include "Message.h"

#define DEBUG ON

#pragma warning (disable:4996) 

using namespace std;

#define prNOMLEN 50
#define prPRENOMLEN 50

unsigned long Professeur::EnVie = 0;
unsigned long Professeur::Compteur = 0;

//----------Constructeur----------
Professeur::Professeur(void)
{
	
	InitProfesseur(NULL, FRM_PROF_INCONNU, 1900, 0, 0);
	
}

//----------Constructeur de recopie----------
Professeur::Professeur(Professeur& Prof)
{
	if (&Prof == this) return;
	InitProfesseur(Prof.Nom, Prof.Prenom, Prof.AnneeNaissance, Prof.SalaireMensuel_Eur, Prof.Poids_Kg);
}

//----------Constructeur avec parametre----------
Professeur::Professeur(const char* nom,const char* prenom, unsigned int anneenaissance, float salairemensuel_eur, float poids_kg)
{
	
	InitProfesseur(nom, prenom, anneenaissance, salairemensuel_eur, poids_kg);
	
}

//----------Destructeur----------
Professeur::~Professeur(void)
{

#ifdef DEBUG ON
	cout << FRM_PROF_SUPPRIME << FRM_PROF_DEUXPOINTS << endl;
#endif // DEBUG 

	EnVie--;

#ifdef DEBUG ON
	cout << FRM_PROF_TITRE_CLASS << EnVie << endl;
#endif // DEBUG 
	
	delete[] Nom;
	delete[] Prenom;
}

//----------Accesseurs----------
void Professeur::setNom (const char* nom)
{
	if (!nom) { *Nom = 0; return; }
	strncpy(Nom,nom,prNOMLEN);
	Nom[prNOMLEN - 1] = 0;

}

void Professeur::setPrenom (const char* prenom)
{
	if (!prenom) { *Prenom = 0; return; }
	
	strcpy(Prenom, prenom);
	Prenom[prNOMLEN - 1] = 0;

}

void Professeur::setAnneeNaissance (unsigned int anneenaissance)
{
	
	if (anneenaissance <= 99) anneenaissance+=1900;

	AnneeNaissance = anneenaissance;
}

void Professeur::setSalaireMensuel_Eur (float salairemensuel_eur)
{
	if (salairemensuel_eur < 0) salairemensuel_eur = -salairemensuel_eur;
	if (salairemensuel_eur > 1000) salairemensuel_eur = 1000;

	SalaireMensuel_Eur = salairemensuel_eur;
}

void Professeur::setPoids_Kg (float poids_kg)
{
	if (poids_kg < 0) poids_kg = -poids_kg;
	if (poids_kg > 200) poids_kg = 200;

	Poids_Kg = poids_kg;
}

unsigned long Professeur::getId(void)
{
	return (idProfesseur);
}

const char* Professeur::getNom(void)
{
return (Nom);
}

const char* Professeur::getPrenom(void)
{
return (Prenom);
}

unsigned int Professeur::getAnneeNaissance(void)
{
return (AnneeNaissance);
}

float Professeur::getSalaireMensuel_Eur(void)
{
return (SalaireMensuel_Eur);
}

float Professeur::getPoids_Kg(void)
{
return (Poids_Kg);
}

//----------Operateurs----------

Professeur & Professeur::operator=(Professeur & prof)
{
	if (&prof == this) return (*this);

	idProfesseur = prof.idProfesseur;
	setNom(prof.Nom);
	setPrenom(prof.Prenom);
	setAnneeNaissance(prof.AnneeNaissance);
	setPoids_Kg(prof.Poids_Kg);
	setSalaireMensuel_Eur(prof.SalaireMensuel_Eur);

	return (*this);
}

void Professeur::Display(Professeur Prof)
{
	cout << FRM_PROF_ID << FRM_PROF_DEUXPOINTS << Prof.getId() << endl;
	cout << FRM_PROF_NOM << FRM_PROF_DEUXPOINTS << Prof.getNom() << endl;
	cout << FRM_PROF_PRENOM << FRM_PROF_DEUXPOINTS << Prof.getPrenom() << endl;
	cout << FRM_PROF_ANNEE_NAISSANCE << FRM_PROF_DEUXPOINTS << Prof.getAnneeNaissance() << endl;
	cout << FRM_PROF_POIDS << FRM_PROF_DEUXPOINTS << Prof.getPoids_Kg() << endl;
	cout << FRM_PROF_SALAIRE << FRM_PROF_DEUXPOINTS << Prof.getSalaireMensuel_Eur() << endl;
	cout << "------------------" << endl;
}

void Professeur::InitProfesseur(const char * nom, const char * prenom, unsigned int anneenaissance, float salairemensuel_eur, float poids_kg)
{
	
	char buf_Nom[prNOMLEN]; // pour concatenation du nom avant l'envoi dans le seteur
	Compteur++;
	EnVie++;
	idProfesseur = Compteur;
	sprintf(buf_Nom, "%s%04d",FRM_PROF_TITRE_CLASS, idProfesseur);

	// Création de variable en allocation dinamique
	Nom = new char[prNOMLEN];
	Prenom = new char[prPRENOMLEN];

	// Vider memoire allouée pour etre sur de ce qu'on va trouver a l'interieur.
	memset(Nom, 0, prNOMLEN*sizeof(char));
	memset(Prenom, 0, prPRENOMLEN*sizeof(char));

	if (!nom) setNom(buf_Nom);
	else setNom(nom);

	setPrenom(prenom);
	setAnneeNaissance(anneenaissance);
	setPoids_Kg(poids_kg);
	setSalaireMensuel_Eur(salairemensuel_eur);

	cout <<  FRM_PROF_TITRE_CLASS <<" [" << EnVie << "] " << FRM_PROF_EN_VIE << "." << endl;
}
