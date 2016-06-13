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
		protected Professeur Prof;
		protected List<Professeur> ContainerProf;
		
		public FormPrincipal()
		{

			InitializeComponent();
            AddEvent();
        }

		private void NewProf()
		{
			Prof = new Professeur();
			ContainerProf.Add(Prof);
			DisplayToFormProf();
			ModeEdit(false);

		}

		private void DisplayToFormProf()
		{
			TextNom.Text = Prof.Nom;
			TextPrenom.Text = Prof.Prenom;
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
			this.TextNom.ReadOnly = !val;
			this.TextPrenom.ReadOnly = !val;
			this.BtModifier.Enabled = !val;
			this.BtNew.Enabled = !val;
			this.BtFirst.Enabled = !val;
			this.BtLast.Enabled = !val;
			this.BtNext.Enabled = !val;
			this.BtPrevious.Enabled = !val;
			ActiveControl = null;
		}

		private void RefreshCount()
		{
			this.TextCountProf.Text = ContainerProf.Count.ToString();
		}

		public void setContainer(List<Professeur> container)
		{
			ContainerProf = container;
		}

		private void SaveProf()
		{
			this.Prof.Nom = TextNom.Text;
			this.Prof.Prenom = TextPrenom.Text;
		}

		// EVENT .................................

		private void BtModifier_Click(object sender, EventArgs e)
		{
			ModeEdit(true);
		}


		private void BtSave_Click(object sender, EventArgs e)
		{
			SaveProf();
			ModeEdit(false);

		}

		private void FormPrincipal_Load(object sender, EventArgs e)
		{
			ActiveControl = BtModifier;
			if (ContainerProf.Count == 0)
            {
                Prof = ContainerProf.First();
                DisplayToFormProf();
            }


		}

		private void BtNew_Click(object sender, EventArgs e)
		{
			NewProf();
			ModeEdit(true);
			RefreshCount();
		}

		private void BtFirst_Click(object sender, EventArgs e)
		{
			Prof = ContainerProf.First();
			DisplayToFormProf();
		}

		private void BtLast_Click(object sender, EventArgs e)
		{
			Prof = ContainerProf.Last();
			DisplayToFormProf();
		}

		private void BtPrevious_Click(object sender, EventArgs e)
		{
			if (0 == ContainerProf.IndexOf(Prof)) return;
			Prof = ContainerProf[ContainerProf.IndexOf(Prof) - 1];
			DisplayToFormProf();
		}

		private void BtNext_Click(object sender, EventArgs e)
		{
			if (ContainerProf.Count-1 == ContainerProf.IndexOf(Prof)) return;
			Prof = ContainerProf[ContainerProf.IndexOf(Prof) + 1];
			DisplayToFormProf();
		}

		private void BtCancel_Click(object sender, EventArgs e)
		{
			DisplayToFormProf();

		}
	}
}
