using System;
using System.Collections.Generic;
using System.Text;

namespace Formulaire1
{

	public class Professeur
	{
		static long compteur = 0;

		//------Constructeur------------------
		public Professeur()
		{
			_idprof = ++compteur;
			_nom = "Professeur" + _idprof.ToString("D5");
			_prenom = "Inconnu";
			_anneenaissance = 2000;
			_salairemensuel = 1000;
		}
		//------Constructeur de recopie-------
		public Professeur(Professeur aprof)
		{
			_idprof = ++compteur;
			_nom = aprof._nom;
			_prenom = aprof._prenom;
			_anneenaissance = aprof._anneenaissance;
			_salairemensuel = aprof._salairemensuel;
		}
		//------Accesseurs--------------------
		protected long _idprof;         //variable
		public long idProf              //propriété
		{
			get { return _idprof; }
            set { _idprof = value; }
        }
		//------------------------------------
		protected string _prenom;
		public string Prenom            //propriété
		{
			get { return _prenom; }
			set { _prenom = value; }
		}
		//------------------------------------
		protected string _nom;          //variable
		public string Nom               //propriété
		{
			get { return _nom; }
			set { _nom = value; }
		}
		//------------------------------------
		protected long _anneenaissance; //variable
		public long AnneeNaissance      //propriété
		{
			get
			{
				return _anneenaissance;
			}
			set
			{
				if (value > 2016)
					_anneenaissance = 2016;
				else if (value < 1916)
					_anneenaissance = 1916;
				else
					_anneenaissance = value;
			}
		}
		//------------------------------------
		protected double _salairemensuel;
		public double SalaireMensuel
		{
			get
			{
				return _salairemensuel;
			}
			set
			{
				if (value < 0)
					_salairemensuel = 0;
				else if (value > 5000)
					_salairemensuel = 5000;
				else
					_salairemensuel = value;
			}
		}
		//------------------------------------

	}
}