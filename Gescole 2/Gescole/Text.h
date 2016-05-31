#pragma once
#include<iostream>

#define TAILLESTD 50
#define TAILLEGRD TAILLESTD*2

using namespace std;

class Text
{
protected:
	char* m_Text;
	size_t m_Size;
public:
	Text(size_t size = TAILLEGRD); // constructeur avec taille fixe par defaut
	Text(Text& other); // constructeur de recopie basé sur l'operateur de copie

	Text& operator=(Text& other); // operateur de copie
	Text& operator=(const char* other); // operateur d'assignation
	friend ostream& operator<<(ostream& COUT, Text& other);
	~Text(); // destructeur (delete)
	void setText(const char* text);
	const char* getText();


protected:
	void setSize(size_t size);
	size_t getSize();

};


