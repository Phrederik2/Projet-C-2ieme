#include "Stream.h"


Stream::Stream()
{
	

}

Stream::~Stream()
{
}

void Stream::Write(List<Client>& container)
{
	Client* temp;
	std::string requete = R"(Select * from client;)";
	sql.Select(requete);
	while (sql.Step())
	{
		temp = new Client;
		container.Add(Write(temp));
	}

}

void Stream::Write(List<Livraison>& container)
{
	Livraison* temp;
	std::string requete = R"(Select * from livraison;)";
	sql.Select(requete);
	while (sql.Step())
	{
		temp = new Livraison;
		container.Add(Write(temp));
	}
}

void Stream::Write(List<Commande>& container)
{
	Commande* temp;
	std::string requete = R"(Select * from commande;)";
	sql.Select(requete);
	while (sql.Step())
	{
		temp = new Commande;
		container.Add(Write(temp));
	}
}

void Stream::Write(List<RendezVous>& container)
{
	RendezVous* temp;
	std::string requete = R"(Select * from rendezvous;)";
	sql.Select(requete);
	while (sql.Step())
	{
		temp = new RendezVous;
		container.Add(Write(temp));
	}
}

void Stream::Write(List<Dossier>& container)
{
	Dossier* temp;
	std::string requete = R"(Select * from rendezvous;)";
	sql.Select(requete);
	while (sql.Step())
	{
		temp = new Dossier;
		container.Add(Write(temp));
	}
}


Client* Stream::Write(Client* temp)
{

	temp->setID(sql.Requete_int(0));
	temp->setNom((const char*)sql.Requete_string(1));
	temp->setPrenom((const char*)sql.Requete_string(2));
	temp->setSociete((const char*)sql.Requete_string(3));
	temp->setLocalite((const char*)sql.Requete_string(4));
	temp->setRue((const char*)sql.Requete_string(5));
	temp->setNumero(sql.Requete_int(6));
	temp->setBoite(sql.Requete_char(7));
	temp->setCodePostal(sql.Requete_int(8));
	temp->IsDelete = sql.Requete_bool(9);

	return temp;
}

Livraison* Stream::Write(Livraison* temp)
{
	temp->setID(sql.Requete_int(0));
	temp->setName((const char*)sql.Requete_string(1));
	temp->IsDelete = sql.Requete_bool(2);

	return temp;
}

Commande* Stream::Write(Commande* temp)
{
	temp->setID(sql.Requete_int(0));
	temp->setName((const char*)sql.Requete_string(1));
	temp->IsDelete = sql.Requete_bool(2);

	return temp;
}

RendezVous* Stream::Write(RendezVous* temp)
{
	temp->setID(sql.Requete_int(0));
	temp->setDateDebut(sql.Requete_int(1), sql.Requete_int(2), sql.Requete_int(3));
	temp->setDateFin(sql.Requete_int(4), sql.Requete_int(5), sql.Requete_int(6));
	temp->setRemark((const char*)sql.Requete_string(6));
	temp->IsDelete = sql.Requete_bool(7);

	return temp;
}

Dossier * Stream::Write(Dossier * temp)
{
	temp->setID(sql.Requete_int(0));
	temp->setID_Client(sql.Requete_int(1));
	temp->setID_Commande(sql.Requete_int(2));
	temp->setID_Livraison(sql.Requete_int(3));
	temp->setID_RDV(sql.Requete_int(4));
	temp->IsDelete = sql.Requete_bool(5);

	return temp;
}


void Stream::Read(List<Client>& container)
{
	Client* temp;
	
	temp = container.First();

	while (temp)
	{
		stringstream insert;
		stringstream update;

		insert << "INSERT INTO Client (id,nom,prenom,societe,localite,rue,numero,boite,codepostal,isdelete) VALUES (";
		insert << temp->getID() << ", ";
		insert << "'" << temp->getNom() << "', ";
		insert << "'" << temp->getPrenom() << "', ";
		insert << "'" << temp->getSociete() << "', ";
		insert << "'" << temp->getLocalite() << "', ";
		insert << "'" << temp->getRue() << "', ";
		insert << temp->getNumero() << ", ";
		insert << "'" << temp->getBoite() << "', ";
		insert << temp->getCodePostal() << ",";
		insert << temp->IsDelete << ");";

		update << "UPDATE Client SET ";
		update << "nom= '" << temp->getNom() << "', ";
		update << "prenom= '" << temp->getPrenom() << "', ";
		update << "societe= '" << temp->getSociete() << "', ";
		update << "localite= '" << temp->getLocalite() << "', ";
		update << "rue= '" << temp->getRue() << "', ";
		update << "numero= " << temp->getNumero() << ", ";
		update << "boite= '" << temp->getBoite() << "', ";
		update << "codepostal= " << temp->getCodePostal() << ", ";
		update << "isdelete= " << temp->IsDelete << " ";
		update << "WHERE id= " << temp->getID() << ";";

		InsertOrUpdate(temp, insert.str(), update.str());


		temp = container.Next();
	}
}

void Stream::Read(List<Livraison>& container)
{
	Livraison* temp;

	temp = container.First();

	while (temp)
	{
		stringstream insert;
		stringstream update;

		insert << "INSERT INTO livraison (id,name,isdelete) VALUES (";
		insert << temp->getID() << ", ";
		insert << "'" << temp->getName() << "', ";
		insert << temp->IsDelete << ");";

		update << "UPDATE livraison SET ";
		update << "name= '" << temp->getName() << "', ";
		update << "isdelete= " << temp->IsDelete << " ";
		update << "WHERE id= " << temp->getID() << ";";

		InsertOrUpdate(temp, insert.str(), update.str());
		

		temp = container.Next();
	}
}

void Stream::Read(List<Commande>& container)
{
	Commande* temp;

	temp = container.First();

	while (temp)
	{
		stringstream insert;
		stringstream update;

		insert << "INSERT INTO commande (id,name,isdelete) VALUES (";
		insert << temp->getID() << ", ";
		insert << "'" << temp->getName() << "', ";
		insert << temp->IsDelete << ");";

		update << "UPDATE commande SET ";
		update << "name= '" << temp->getName() << "', ";
		update << "isdelete= " << temp->IsDelete << " ";
		update << "WHERE id= " << temp->getID() << ";";

		InsertOrUpdate(temp, insert.str(), update.str());


		temp = container.Next();
	}
}

void Stream::Read(List<RendezVous>& container)
{
	RendezVous* temp;

	temp = container.First();

	while (temp)
	{
		stringstream insert;
		stringstream update;

		insert << "INSERT INTO rendezvous (id,datedebutyear,datedebutmonth,datedebutday,datefinyear,datefinmonth,datefinday,remark,isdelete) VALUES (";
		insert << temp->getID() << ", ";
		insert << "" << temp->getDateDebutYear() << ", ";
		insert << "" << temp->getDateDebutMonth() << ", ";
		insert << "" << temp->getDateDebutDay() << ", ";
		insert << "" << temp->getDateFinYear() << ", ";
		insert << "" << temp->getDateFinMonth() << ", ";
		insert << "" << temp->getDateFinDay() << ", ";
		insert << "'" << temp->getRemark() << "', ";
		insert << temp->IsDelete << ");";

		update << "UPDATE rendezvous SET ";
		update << "datedebutyear= " << temp->getDateDebutYear() << ", ";
		update << "datebebutmonth= " << temp->getDateDebutMonth() << ", ";
		update << "datedebutday= " << temp->getDateDebutDay() << ", ";
		update << "datefinyear= " << temp->getDateFinYear() << ", ";
		update << "datefinmonth= " << temp->getDateFinMonth() << ", ";
		update << "datefinday= " << temp->getDateFinDay() << ", ";
		update << "remark= '" << temp->getRemark() << "', ";
		update << "isdelete= " << temp->IsDelete << " ";
		update << "WHERE id= " << temp->getID() << ";";

		InsertOrUpdate(temp, insert.str(), update.str());


		temp = container.Next();
	}
}

void Stream::Read(List<Dossier>& container)
{
	Dossier* temp;

	temp = container.First();

	while (temp)
	{
		stringstream insert;
		stringstream update;

		insert << "INSERT INTO dossier (id,idclient,idcommande,idlivraison,idrdv,isdelete) VALUES (";
		insert << temp->getID() << ", ";
		insert << temp->getID_Client() << ", ";
		insert << temp->getID_Commande() << ", ";
		insert << temp->getID_Livraison() << ", ";
		insert << temp->getID_RDV() << ", ";
		insert << temp->IsDelete << ");";

		update << "UPDATE dossier SET ";
		update << "idclient= " << temp->getID_Client() << ", ";
		update << "idcommande= " << temp->getID_Commande() << ", ";
		update << "idlivraison= " << temp->getID_Livraison() << ", ";
		update << "idrdv= " <<temp->getID_RDV() << ", ";
		update << "isdelete= " << temp->IsDelete << " ";
		update << "WHERE id= " << temp->getID() << ";";

		InsertOrUpdate(temp, insert.str(), update.str());


		temp = container.Next();
	}
}


template<typename ENTITY>
void Stream::InsertOrUpdate(ENTITY * entity, string insert, string update)
{
	string requete;

	if (entity->IsNew)
	{
		requete = insert;
		entity->IsNew = false;
	}

	if (entity->IsChanged)
	{
		requete = update;
		entity->IsChanged = false;
	}

	if (requete.size()) sql.Exec(requete.c_str());

}