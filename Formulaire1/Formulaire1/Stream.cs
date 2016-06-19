using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Formulaire1
{ 
    class Stream
    {
        private ConnectSQLite db = new ConnectSQLite();

        public void Read(List<Client> list)
        {

            db.SelectExecute("SELECT * from client;");

            while (db.Reader.Read())
            {
                Client temp = new Client();
                temp.ID = db.Reader.GetInt32(0);
                temp.Nom = db.Reader.GetString(1);
                temp.Prenom = db.Reader.GetString(2);
                temp.Societe = db.Reader.GetString(3);
                temp.Localite = db.Reader.GetString(4);
                temp.Rue = db.Reader.GetString(5);
                temp.Numero = db.Reader.GetInt32(6);
                temp.Boite = db.Reader.GetString(7);
                temp.CodePostal = db.Reader.GetInt32(8);
                temp.IsDelete = db.Reader.GetBoolean(9);

                list.Add(temp);
            }
            db.Close();

            db.SelectExecute("SELECT seq FROM sqlite_sequence WHERE name = 'client';");
            while (db.Reader.Read())
            {
                Client.Compter = db.Reader.GetInt16(0);
            }
            db.Close();


        }

        public void Write(List<Client> list)
        {

            foreach (var temp in list)
            {
                if (temp.IsNew == true) Insert(temp);
                else if (temp.IsChanged == true) Update(temp);
            }

        }

        public void Insert(Client temp)
        {
            string requete = "INSERT INTO client VALUES(" +
                    "" + temp.ID + "," +
                    "'" + temp.Nom + "'," +
                    "'" + temp.Prenom + "'," +
                    "'" + temp.Societe + "'," +
                    "'" + temp.Localite + "'," +
                    "'" + temp.Rue + "'," +
                    "" + temp.Numero + "," +
                    "'" + temp.Boite + "'," +
                    "" + temp.CodePostal + "," +
                    "" + Convert.ToInt16(temp.IsDelete) + "" +
                    ");";
            db.Execute(requete);
            db.Close();
        }

        public void Update(Client temp)
        {
            string requete = "UPDATE client SET " +
                    "nom= '" + temp.Nom + "', " +
                    "prenom= '" + temp.Prenom + "', " +
                    "societe= '" + temp.Societe + "', " +
                    "localite= '" + temp.Localite + "', " +
                    "rue= '" + temp.Rue + "', " +
                    "numero=" + temp.Numero + ", " +
                    "boite= '" + Convert.ToChar(temp.Boite) + "', " +
                    "codepostal= " + temp.CodePostal + ", " +
                    "isdelete= " + Convert.ToInt16(temp.IsDelete) + " " +
                    "WHERE id= " + temp.ID + "" +
                    ";";
            db.Execute(requete);
            db.Close();
        }
    }
}
