using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Formulaire1
{
    public class Client
    {
        private static int Compter = 0;
        private int _ID = Compter+1;
        private string _Nom = "Inconnu";
        private string _Prenom = "Inconnu";
        private string _Societe = "Inconnu";
        private string _Localite = "Inconnu";
        private string _Rue = "Inconnu";
        private int _Numero = 0;
        private char _Boite = ' ';
        private int _CodePostal = 0;
        private bool _IsDelete = false;
        private bool _IsNew = false;
        private bool _IsChanged = false;

        public Client(Client other)
        {
            ID = other.ID;
            Nom = other.Nom;
            Prenom = other.Prenom;
            Societe = other.Societe;
            Localite = other.Localite;
            Rue = other.Rue;
            Numero = other.Numero;
            Boite = other.Boite;
            CodePostal = other.CodePostal;
        }
        public Client()
        {
            if (ID > Compter) Compter = ID;
        }


        public int ID
        {
            get
            {
                return _ID;
            }

            set
            {
                _ID = value;
            }
        }

        public string Nom
        {
            get
            {
                return _Nom;
            }

            set
            {
                _Nom = value;
            }
        }

        public string Prenom
        {
            get
            {
                return _Prenom;
            }

            set
            {
                _Prenom = value;
            }
        }

        public string Societe
        {
            get
            {
                return _Societe;
            }

            set
            {
                _Societe = value;
            }
        }

        public string Localite
        {
            get
            {
                return _Localite;
            }

            set
            {
                _Localite = value;
            }
        }

        public string Rue
        {
            get
            {
                return _Rue;
            }

            set
            {
                _Rue = value;
            }
        }

        public int Numero
        {
            get
            {
                return _Numero;
            }

            set
            {
                _Numero = value;
            }
        }

        public char Boite
        {
            get
            {
                return _Boite;
            }

            set
            {
                _Boite = value;
            }
        }

        public int CodePostal
        {
            get
            {
                return _CodePostal;
            }

            set
            {
                _CodePostal = value;
            }
        }

        public bool IsDelete
        {
            get
            {
                return _IsDelete;
            }

            set
            {
                _IsDelete = value;
            }
        }

        public bool IsNew
        {
            get
            {
                return _IsNew;
            }

            set
            {
                _IsNew = value;
            }
        }

        public bool IsChanged
        {
            get
            {
                return _IsChanged;
            }

            set
            {
                _IsChanged = value;
            }
        }
    }
}
