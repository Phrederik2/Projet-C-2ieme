
#include "ContainerEntity.h"
#include"Text.h"
#include"PrimaryKey.h"
class Adresse :
	protected ContainerEntity
{
	//DataMenbre
protected:
	Title<Adresse> Titre;
	PrimaryKey<Adresse> ID;
	Text Localite;
	Text Rue;
	int Numero;
	char Boite;
	int CodePostal;


public:
	Adresse();
	Adresse(Adresse& other);
	~Adresse();

	void setTitle(const char* title);
	void setLocalite(const char* localite);
	void setRue(const char* rue);
	void setNumero(int numero);
	void setBoite(char boite);
	void setCodePostal(int codepostal);

	const char* getTitle();
	unsigned long getID();
	const char* getLocalite();
	const char* getRue();
	int getNumero();
	char getBoite();
	int getCodePostal();
	unsigned long getAlive();

	void Display(ostream& stream = cout);
	void Encode();

	Adresse& operator=(Adresse& other);
	friend ostream& operator<<(ostream& COUT, Adresse& other);
};
