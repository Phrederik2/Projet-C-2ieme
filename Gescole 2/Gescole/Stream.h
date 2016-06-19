#pragma once
#include"SQL.h"
#include"Client.h"
#include"Application.h"
#include<sstream>
#include"Lancer.h"


class Stream
{
	SQL* sql;

protected:
	Client* Write(Client* temp);
	Livraison* Write(Livraison* temp);
	Commande* Write(Commande* temp);
	RendezVous* Write(RendezVous* temp);
	Dossier* Write(Dossier* temp);

public:
	Stream();
	~Stream();

	void Write(List<Client>& container);
	void Write(List<Livraison>& container);
	void Write(List<Commande>& container);
	void Write(List<RendezVous>& container);
	void Write(List<Dossier>& container);
	void Write(List<Lancer>& container);

	template<typename ENTITY>
	ENTITY* Write(int id, ENTITY* temp, string table);
	
	
	void Read(List<Client>& container);
	void Read(List<Livraison>& container);
	void Read(List<Commande>& container);
	void Read(List<RendezVous>& container);
	void Read(List<Dossier>& container);
	void Read(List<Lancer>& container);

protected:
	template<typename ENTITY>
	void InsertOrUpdate(ENTITY* entity, string insert, string update);
};

template<typename ENTITY>
ENTITY * Stream::Write(int id, ENTITY * temp, string table)
{
	stringstream requete;
	requete << R"(Select * from )" << table << R"( WHERE id=)" << id << R"(;)";
	sql->Select(requete.str());


	while (sql->Step()) Write(temp);


	return temp;
}

