#pragma once
#include"sqlite3.h"
#include<string>

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
	std::string Requete_string(int row);
	bool Step();
	size_t NumberColumn();
	std::string NameColumn(int row);
	void AddFile(std::string path = "");
	void Display();
};

