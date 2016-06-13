using System;
using System.Collections.Generic;
using System.Data.OleDb;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Formulaire1
{
    public class ConnectAccess
    {
        protected const string ConnectionString = @"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\frederic\Documents\Database.mdb";
        protected List<Professeur> ListProf;
        


        public ConnectAccess(List<Professeur> listprof)
        {
            ListProf = listprof;
            OleDbConnection connection = new OleDbConnection(ConnectionString);
            //MessageBox.Show("Connection a la base de donnée.");
            
            try // essaye.
            {
                connection.Open();
  
                const string SQL = "SELECT * FROM Professeur";
                OleDbCommand SelectProf = new OleDbCommand(SQL,connection);
                OleDbDataReader ReadSQL = SelectProf.ExecuteReader();

                if(ReadSQL.HasRows)
                {
                    while(ReadSQL.Read())
                    {
                        Professeur Prof = new Professeur();
                       
                        Prof.idProf = ReadSQL.GetInt32(0);
                        Prof.Nom = ReadSQL.GetString(1);
                        Prof.Prenom = ReadSQL.GetString(2);
                        Prof.AnneeNaissance = ReadSQL.GetInt32(3);
                        Prof.SalaireMensuel = ReadSQL.GetDouble(4);

                        ListProf.Add(Prof);
                    }
                    ReadSQL.Close();
                }
            }
            catch(Exception ex)//si erreur.
            {
                MessageBox.Show("Connection a la base de donnée:Erreur:" + "\n" + ex.Message);
            }
            finally
            {
                if (connection != null) connection.Close();
            }
        }
    }
    
}
