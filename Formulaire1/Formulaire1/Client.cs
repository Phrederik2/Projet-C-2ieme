using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Formulaire1
{
    public class Client
    {
        private static int _Compter = 0;
        private int _ID = Compter+1;
        private string _Nom = "Inconnu";
        private string _Prenom = "Inconnu";
        private string _Societe = "Inconnu";
        private string _Localite = "Inconnu";
        private string _Rue = "Inconnu";
        private int _Numero = 0;
        private string _Boite = "";
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

        public string Boite
        {
            get
            {
                return _Boite;
            }

            set
            {
                if(value.Length > 1)
                {
                char[] temp = value.ToCharArray();
                 _Boite = temp[0].ToString();
                }
                else
                {
                    _Boite = value;
                }
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

        public static int Compter
        {
            get
            {
                return _Compter;
            }

            set
            {
                _Compter = value;
            }
        }
    }
}
