#include "SQL.h"
#include "sqlite3.h"
#include <string>
#include<iostream>
#include"List.h"
#include<fstream>



SQL::SQL(std::string path)
{
	this->MessageError=0; // Recup message d'erreur
	this->CodeRetour=0; // Code de message return
	Initialize(path);
}


SQL::~SQL()
{
	//sqlite3_finalize(this->Requete);
	sqlite3_close(this->DB);
}

int SQL::Initialize(std::string path)
{
	std::ifstream input;
	input.open(path);
	if (input)
	{
		input.close();
		Open(path);
	}
	else
	{
		Open(path);
		Create();
	}
	return 0;
}

int SQL::Open(std::string path)
{
	this->CodeRetour = sqlite3_open_v2(path.c_str(), &DB, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

	if (this->CodeRetour)
	{

		printf("Impossible d'ouvrir la base de donn�es : %s\n", sqlite3_errmsg(this->DB));
		sqlite3_close(this->DB);
		return 1;
	}

	return 0;
}

void SQL::Exec(std::string sql)
{
	
	this->CodeRetour = sqlite3_exec(this->DB, sql.c_str(), NULL, 0, &this->MessageError);

	if (this->CodeRetour && this->MessageError != NULL) 
	{
		std::cout << "SQL: " << sql << std::endl;
		std::cout << "Message d'erreur: " << this->MessageError << std::endl;
		sqlite3_free(this->MessageError);
		this->CodeRetour = 0;
		this->MessageError = NULL;
	}
}

void SQL::Select(std::string sql)
{
	this->CodeRetour=sqlite3_prepare_v2(this->DB, sql.c_str(), sql.size(), &this->Requete,NULL);
	if (this->CodeRetour && this->MessageError != NULL)
	{
		std::cout << "SQL: " << sql << std::endl;
		std::cout << "Message d'erreur: " << this->MessageError << std::endl;
		sqlite3_free(this->MessageError);
		this->CodeRetour = 0;
		this->MessageError = NULL;
	}
}

int SQL::Requete_int(int row)
{
	if (sqlite3_column_count(this->Requete) - 1 < row) return 0;
	return sqlite3_column_int(this->Requete,row);
}

bool SQL::Requete_bool(int row)
{
	if (Requete_int(row)) return true;
	return false;
}

const unsigned char* SQL::Requete_string(int row)
{
//	if (sqlite3_column_count(this->Requete) - 1 < row) return "";

	return (const unsigned char*)sqlite3_column_text(this->Requete, row);
	
}

const char SQL::Requete_char(int row)
{
	if (sqlite3_column_count(this->Requete) - 1 < row) return ' ';

	return sqlite3_column_text(this->Requete, row)[0];

}

bool SQL::Step()
{
	return !(sqlite3_step(this->Requete) -100);
}

size_t SQL::NumberColumn()
{
	return sqlite3_column_count(this->Requete);
}

std::string SQL::NameColumn(int row)
{
	return sqlite3_column_name(this->Requete, row);
}

void SQL::AddFile(std::string path)
{
	
	int i = 0;
	if (!path.size()) std::cout << "Introduisez le fichier a charger dans la base." << std::endl;
	File file(path);

	while (file.RecoverNextLine())
	{
		Exec(file.getCurrentLine());
		i++;
	}
	std::cout << " Ligne chargees = " << i << " Chargement termine." << std::endl;
}

void SQL::Display()
{
	std::cout << std::endl;
	std::cout <<"\t";
	for (size_t i = 0; i < this->NumberColumn(); i++)
	{
		std::cout << "| "<< this->NameColumn(i) << "\t\t";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	while (Step())
	{
		std::cout << "\t";
		for (size_t i = 0; i < this->NumberColumn(); i++)
		{
			std::cout << "| " << this->Requete_string(i) << "\t\t";
		}
		std::cout << std::endl;
	}
}

void SQL::Close()
{
	sqlite3_finalize(this->Requete);
	sqlite3_close(this->DB);
}

void SQL::Create()
{
	Exec(R"(CREATE TABLE "client" (
	`ID`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	`nom`	TEXT,
	`prenom`	TEXT,
	`societe`	TEXT,
	`localite`	TEXT,
	`rue`	TEXT,
	`numero`	INTEGER,
	`boite`	TEXT,
	`codepostal`	INTEGER,
	`isdelete`	INTEGER
	);)");
	Exec(R"(CREATE TABLE "commande" (
	`id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT,
	`isdelete`	INTEGER
	);)");
	Exec(R"(CREATE TABLE "dossier" (
	`id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	`idclient`	INTEGER,
	`idcommande`	INTEGER,
	`idlivraison`	INTEGER,
	`idrdv`	INTEGER,
	`isdelete`	INTEGER
	);)");
	Exec(R"(CREATE TABLE "livraison" (
	`id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT,
	`isdelete`	INTEGER
	);)");
	Exec(R"(CREATE TABLE "rendezvous" (
	`id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	`datedebutyear`	INTEGER,
	`datedebutmonth`	INTEGER,
	`datedebutday`	INTEGER,
	`datefinyear`	INTEGER,
	`datefinmonth`	INTEGER,
	`datefinday`	INTEGER,
	`remark`	TEXT,
	`isdelete`	INTEGER
	);)");
}

