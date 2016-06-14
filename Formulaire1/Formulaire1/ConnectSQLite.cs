using System;
using System.Collections.Generic;
using System.Data.OleDb;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SQLite;

namespace Formulaire1
{
    public class ConnectSQLite
    {
        // DataMembre
        protected const string DataBase = @"Database.db";
        protected const string ConnectionString = @"Data Source = " + DataBase + "; Version=3;";
        protected SQLiteConnection MaConnection;
        protected SQLiteDataReader Reader;

        // Function
        public ConnectSQLite()
        {
            if (!System.IO.File.Exists(DataBase)) CreateDB();
            MaConnection = new SQLiteConnection(ConnectionString);
        }

        public void Execute(string sql)
        {
            Open();
            SQLiteCommand Requete = new SQLiteCommand(sql, MaConnection);

            try
            {
                Requete.ExecuteNonQuery();
            }
            catch (Exception error)
            {
                MessageBox.Show("Execute: Erreur a l'execution de la requete: " + error.Message);
                Close();
            }
        }

        public void SelectExecute(string sql)
        {
            Open();
            SQLiteCommand Requete = new SQLiteCommand(sql, MaConnection);

            try
            {
                Reader = Requete.ExecuteReader();
            }
            catch (Exception error)
            {
                MessageBox.Show("SELECT :Erreur a l'execution de la requete: " + error.Message);
                Close();
            }
        }

        public void Open()
        {
            try
            {
                MaConnection.Open();
            }
            catch(Exception error)
            {
                MessageBox.Show("Connection a " + DataBase + " : Erreur : " + error.Message);
                Close();
            }
           
        }

        public void Write(List<Client> list)
        {
            SelectExecute("SELECT * from client;");

            while(Reader.Read())
            {
                Client temp = new Client();
                temp.ID = Reader.GetInt32(0);
                temp.Nom = Reader.GetString(1);
                temp.Prenom = Reader.GetString(2);
                temp.Societe = Reader.GetString(3);
                temp.Localite = Reader.GetString(4);
                temp.Rue = Reader.GetString(5);
                temp.Numero = Reader.GetInt32(6);
                temp.Boite = Convert.ToChar(Reader.GetString(7));
                temp.CodePostal = Reader.GetInt32(8);
                temp.IsDelete = Reader.GetBoolean(9);

                list.Add(temp);
            }


            Close();

        }

        public void Read(List<Client> list)
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
                    "'" + Convert.ToChar(temp.Boite) + "'," +
                    "" + temp.CodePostal + "," +
                    "" + Convert.ToInt16(temp.IsDelete) + "" +
                    ");";
            Execute(requete);
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
            Execute(requete);
        }


        public void Close()
        {
            if (MaConnection != null)MaConnection.Close();
        }

        public void CreateDB()
        {
            SQLiteConnection.CreateFile(DataBase);
            string requete = @"CREATE TABLE ""client"" (
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
                             );";
            Execute(requete);
            Close();
        }








    }
    
}
