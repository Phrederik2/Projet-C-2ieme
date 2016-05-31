
#include "ContainerEntity.h"
#include"Text.h"
class Adresse :
	public ContainerEntity
{
	//DataMenbre
protected:
	static double Alive;
	static double Compter;
	int ID;
	Text Localite;
	Text Rue;
	int Numero;
	char Boite;
	int CodePostal;


public:
	Adresse();
	~Adresse();

	void setLocalite(const char* localite);
	void setRue(const char* rue);
	void setNumero(int numero);
	void setBoite(char boite);
	void setCodePostal(int codepostal);

	int getID();
	const char* getLocalite();
	const char* getRue();
	int getNumero();
	char getBoite();
	int getCodePostal();
	double getAlive();

	void Display(Adresse& other);
	void Encode(Adresse& other);

	friend ostream& operator<<(ostream& COUT, Adresse& other);
};
