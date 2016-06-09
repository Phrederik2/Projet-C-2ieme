#pragma once
#include"sqlite3.h"
#include<string>
#include"File.h"

class SQL
{
protected:
	sqlite3 *DB; // Objet DB
	char* MessageError; // Recup message d'erreur
	int CodeRetour; // Code de message return
public:
	sqlite3_stmt* Requete; // Objet requete qui contien les row de retour d'un select
public:
	SQL(std::string path = "maBaseDeDonne.db");
	~SQL();

protected:

	int Initialize(std::string path);
	int Open(std::string path);
	void Close();

public:

	void Exec(std::string sql);
	void Select(std::string sql);
	int Requete_int(int row);
	bool Requete_bool(int row);
	const unsigned char* Requete_string(int row);
	const char Requete_char(int row);
	bool Step();
	size_t NumberColumn();
	std::string NameColumn(int row);
	void AddFile(std::string path = "");
	void Display();
};

