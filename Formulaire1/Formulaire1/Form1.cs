using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Formulaire1
{
    public partial class FormPrincipal : Form
    {
		protected Client temp;
		protected List<Client> CContainer;
		
		public FormPrincipal()
		{
			InitializeComponent();
            AddEvent();
        }

		private void NewClient()
		{
            temp = new Client();
			CContainer.Add(temp);
			DisplayToFormProf();
			ModeEdit(false);
            temp.IsNew = true;

		}

		private void DisplayToFormProf()
		{
            checkBoxSupprimer.Checked = temp.IsDelete;
            TextID.Text = temp.ID.ToString();
			TextNom.Text = temp.Nom;
			TextPrenom.Text = temp.Prenom;
            TextSociete.Text = temp.Societe;
            TextLocalite.Text = temp.Localite;
            TextRue.Text = temp.Rue;
            TextNumero.Text = temp.Numero.ToString();
            TextBoite.Text = temp.Boite.ToString();
            TextCodePostal.Text = temp.CodePostal.ToString();


			ModeEdit(false);
		}

		private void AddEvent()
		{
			this.BtSave.Click += BtSave_Click;
			this.BtModifier.Click += BtModifier_Click;
		}

		private void ModeEdit(bool val)
		{
			RefreshCount();
			// = val
			this.BtSave.Enabled = val;
			this.BtCancel.Enabled = val;

			// Not = val
            //Entity
			this.TextNom.ReadOnly = !val;
			this.TextPrenom.ReadOnly = !val;
            this.TextSociete.ReadOnly = !val;
            this.TextSociete.ReadOnly = !val;
            this.TextLocalite.ReadOnly = !val;
            this.TextRue.ReadOnly = !val;
            this.TextNumero.ReadOnly = !val;
            this.TextBoite.ReadOnly = !val;
            this.TextCodePostal.ReadOnly = !val;
            this.checkBoxSupprimer.Enabled = val;

            // Bouton
            this.BtNew.Enabled = !val;
            // Desactiver les deplacements et les boutons si list vide.

            if (CContainer.Count == 0)
            {
                this.BtFirst.Enabled = false;
                this.BtLast.Enabled = false;
                this.BtNext.Enabled = false;
                this.BtPrevious.Enabled = false;
                this.BtModifier.Enabled = false;
            }
            else
            {
                this.BtFirst.Enabled = !val;
                this.BtLast.Enabled = !val;
                this.BtNext.Enabled = !val;
                this.BtPrevious.Enabled = !val;
                this.BtModifier.Enabled = !val;
            }
            ActiveControl = null;
        }

		private void RefreshCount()
		{
			this.TextCount.Text = CContainer.Count.ToString();
		}

		public void setContainer(List<Client> container)
		{
			CContainer = container;
		}

		private void Save()
		{
            try
            {
                this.temp.IsDelete = checkBoxSupprimer.Checked;
                this.temp.Nom = TextNom.Text;
                this.temp.Prenom = TextPrenom.Text;
                this.temp.Societe = TextSociete.Text;
                this.temp.Localite = TextLocalite.Text;
                this.temp.Rue = TextRue.Text;
                this.temp.Numero = Convert.ToInt32(TextNumero.Text);
                if (temp.Boite != '\0') this.temp.Boite = Convert.ToChar(TextBoite.Text);
                this.temp.CodePostal = Convert.ToInt32(TextCodePostal.Text);
                if (!temp.IsNew) temp.IsChanged = true;
            }
            catch(Exception error)
            {
                MessageBox.Show(error.TargetSite + ": " + error.Message);
            }
        }

		// EVENT .................................

		private void BtModifier_Click(object sender, EventArgs e)
		{
			ModeEdit(true);
		}


		private void BtSave_Click(object sender, EventArgs e)
		{
            try
            {
                Save();
                ModeEdit(false);
            }
            catch { ModeEdit(true); }

		}

		private void FormPrincipal_Load(object sender, EventArgs e)
		{
			ActiveControl = BtModifier;

			if (CContainer.Count != 0)
            {
                temp = CContainer.First();
                DisplayToFormProf();
            }

            ModeEdit(false);

		}

		private void BtNew_Click(object sender, EventArgs e)
		{
			NewClient();
			ModeEdit(true);
			RefreshCount();
		}

		private void BtFirst_Click(object sender, EventArgs e)
		{
            temp = CContainer.First();
			DisplayToFormProf();
		}

		private void BtLast_Click(object sender, EventArgs e)
		{
            temp = CContainer.Last();
			DisplayToFormProf();
		}

		private void BtPrevious_Click(object sender, EventArgs e)
		{
			if (0 == CContainer.IndexOf(temp)) return;
            temp = CContainer[CContainer.IndexOf(temp) - 1];
			DisplayToFormProf();
		}

		private void BtNext_Click(object sender, EventArgs e)
		{
			if (CContainer.Count-1 == CContainer.IndexOf(temp)) return;
            temp = CContainer[CContainer.IndexOf(temp) + 1];
			DisplayToFormProf();
		}

		private void BtCancel_Click(object sender, EventArgs e)
		{
			DisplayToFormProf();
		}

    }
}
