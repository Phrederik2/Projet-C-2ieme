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
        protected const string DataBase = @"C:\Users\Public\Documents\maBaseDeDonnee.db";
        protected const string ConnectionString = @"Data Source = " + DataBase + @"; Version=3;";
        protected SQLiteConnection MaConnection;
        public SQLiteDataReader Reader;

        // Function
        public ConnectSQLite()
        {
            MaConnection = new SQLiteConnection(ConnectionString);
            if (!System.IO.File.Exists(DataBase)) CreateDB();
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
            catch (Exception error)
            {
                MessageBox.Show("Connection a " + DataBase + " : Erreur : " + error.Message);
                Close();
            }

        }

        public void Close()
        {
            if (MaConnection != null) MaConnection.Close();
        }

        public void CreateDB()
        {
            SQLiteConnection.CreateFile(DataBase);
            string requete = @"CREATE TABLE client (
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
