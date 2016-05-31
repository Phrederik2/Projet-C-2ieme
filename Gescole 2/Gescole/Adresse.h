
#include "ContainerEntity.h"
#include"Text.h"
class Adresse :
	public ContainerEntity
{
	//DataMenbre
protected:
	static double Alive;
	static double Compter;
	static char Title[100];
	double ID;
	Text Localite;
	Text Rue;
	int Numero;
	char Boite;
	int CodePostal;


public:
	Adresse();
	Adresse(Adresse& other);
	~Adresse();

	void setLocalite(const char* localite);
	void setRue(const char* rue);
	void setNumero(int numero);
	void setBoite(char boite);
	void setCodePostal(int codepostal);

	double getID();
	const char* getLocalite();
	const char* getRue();
	int getNumero();
	char getBoite();
	int getCodePostal();
	double getAlive();

	void Display(ostream& stream = cout);
	void Encode();

	Adresse& operator=(Adresse& other);
	friend ostream& operator<<(ostream& COUT, Adresse& other);
};
