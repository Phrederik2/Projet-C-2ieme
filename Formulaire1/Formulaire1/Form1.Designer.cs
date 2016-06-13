namespace Formulaire1
{
    partial class FormPrincipal
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
			this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
			this.LabNom = new System.Windows.Forms.Label();
			this.TextNom = new System.Windows.Forms.TextBox();
			this.TextPrenom = new System.Windows.Forms.TextBox();
			this.LabPrenom = new System.Windows.Forms.Label();
			this.BtSave = new System.Windows.Forms.Button();
			this.BtModifier = new System.Windows.Forms.Button();
			this.TextCountProf = new System.Windows.Forms.TextBox();
			this.LblCountProf = new System.Windows.Forms.Label();
			this.BtNew = new System.Windows.Forms.Button();
			this.BtPrevious = new System.Windows.Forms.Button();
			this.BtNext = new System.Windows.Forms.Button();
			this.BtFirst = new System.Windows.Forms.Button();
			this.BtLast = new System.Windows.Forms.Button();
			this.BtCancel = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// LabNom
			// 
			this.LabNom.AutoSize = true;
			this.LabNom.Location = new System.Drawing.Point(72, 66);
			this.LabNom.Name = "LabNom";
			this.LabNom.Size = new System.Drawing.Size(42, 20);
			this.LabNom.TabIndex = 0;
			this.LabNom.Text = "Nom";
			// 
			// TextNom
			// 
			this.TextNom.BorderStyle = System.Windows.Forms.BorderStyle.None;
			this.TextNom.Location = new System.Drawing.Point(177, 66);
			this.TextNom.Name = "TextNom";
			this.TextNom.ReadOnly = true;
			this.TextNom.Size = new System.Drawing.Size(232, 19);
			this.TextNom.TabIndex = 1;
			// 
			// TextPrenom
			// 
			this.TextPrenom.BorderStyle = System.Windows.Forms.BorderStyle.None;
			this.TextPrenom.Location = new System.Drawing.Point(177, 98);
			this.TextPrenom.Name = "TextPrenom";
			this.TextPrenom.ReadOnly = true;
			this.TextPrenom.Size = new System.Drawing.Size(232, 19);
			this.TextPrenom.TabIndex = 3;
			// 
			// LabPrenom
			// 
			this.LabPrenom.AutoSize = true;
			this.LabPrenom.Location = new System.Drawing.Point(72, 98);
			this.LabPrenom.Name = "LabPrenom";
			this.LabPrenom.Size = new System.Drawing.Size(64, 20);
			this.LabPrenom.TabIndex = 2;
			this.LabPrenom.Text = "Prenom";
			// 
			// BtSave
			// 
			this.BtSave.Enabled = false;
			this.BtSave.Location = new System.Drawing.Point(289, 256);
			this.BtSave.Name = "BtSave";
			this.BtSave.Size = new System.Drawing.Size(106, 51);
			this.BtSave.TabIndex = 4;
			this.BtSave.Text = "Save";
			this.BtSave.UseVisualStyleBackColor = true;
			// 
			// BtModifier
			// 
			this.BtModifier.Location = new System.Drawing.Point(177, 256);
			this.BtModifier.Name = "BtModifier";
			this.BtModifier.Size = new System.Drawing.Size(106, 51);
			this.BtModifier.TabIndex = 5;
			this.BtModifier.Text = "Modifier";
			this.BtModifier.UseVisualStyleBackColor = true;
			// 
			// TextCountProf
			// 
			this.TextCountProf.BorderStyle = System.Windows.Forms.BorderStyle.None;
			this.TextCountProf.Location = new System.Drawing.Point(177, 32);
			this.TextCountProf.Name = "TextCountProf";
			this.TextCountProf.ReadOnly = true;
			this.TextCountProf.Size = new System.Drawing.Size(232, 19);
			this.TextCountProf.TabIndex = 7;
			// 
			// LblCountProf
			// 
			this.LblCountProf.AutoSize = true;
			this.LblCountProf.Location = new System.Drawing.Point(72, 32);
			this.LblCountProf.Name = "LblCountProf";
			this.LblCountProf.Size = new System.Drawing.Size(65, 20);
			this.LblCountProf.TabIndex = 6;
			this.LblCountProf.Text = "Nombre";
			// 
			// BtNew
			// 
			this.BtNew.Location = new System.Drawing.Point(65, 256);
			this.BtNew.Name = "BtNew";
			this.BtNew.Size = new System.Drawing.Size(106, 51);
			this.BtNew.TabIndex = 8;
			this.BtNew.Text = "Nouveau";
			this.BtNew.UseVisualStyleBackColor = true;
			this.BtNew.Click += new System.EventHandler(this.BtNew_Click);
			// 
			// BtPrevious
			// 
			this.BtPrevious.Location = new System.Drawing.Point(177, 313);
			this.BtPrevious.Name = "BtPrevious";
			this.BtPrevious.Size = new System.Drawing.Size(106, 51);
			this.BtPrevious.TabIndex = 9;
			this.BtPrevious.Text = "<";
			this.BtPrevious.UseVisualStyleBackColor = true;
			this.BtPrevious.Click += new System.EventHandler(this.BtPrevious_Click);
			// 
			// BtNext
			// 
			this.BtNext.Location = new System.Drawing.Point(289, 313);
			this.BtNext.Name = "BtNext";
			this.BtNext.Size = new System.Drawing.Size(106, 51);
			this.BtNext.TabIndex = 10;
			this.BtNext.Text = ">";
			this.BtNext.UseVisualStyleBackColor = true;
			this.BtNext.Click += new System.EventHandler(this.BtNext_Click);
			// 
			// BtFirst
			// 
			this.BtFirst.Location = new System.Drawing.Point(65, 313);
			this.BtFirst.Name = "BtFirst";
			this.BtFirst.Size = new System.Drawing.Size(106, 51);
			this.BtFirst.TabIndex = 11;
			this.BtFirst.Text = "<<";
			this.BtFirst.UseVisualStyleBackColor = true;
			this.BtFirst.Click += new System.EventHandler(this.BtFirst_Click);
			// 
			// BtLast
			// 
			this.BtLast.Location = new System.Drawing.Point(401, 313);
			this.BtLast.Name = "BtLast";
			this.BtLast.Size = new System.Drawing.Size(106, 51);
			this.BtLast.TabIndex = 12;
			this.BtLast.Text = ">>";
			this.BtLast.UseVisualStyleBackColor = true;
			this.BtLast.Click += new System.EventHandler(this.BtLast_Click);
			// 
			// BtCancel
			// 
			this.BtCancel.Location = new System.Drawing.Point(401, 256);
			this.BtCancel.Name = "BtCancel";
			this.BtCancel.Size = new System.Drawing.Size(106, 51);
			this.BtCancel.TabIndex = 13;
			this.BtCancel.Text = "Annule";
			this.BtCancel.UseVisualStyleBackColor = true;
			this.BtCancel.Click += new System.EventHandler(this.BtCancel_Click);
			// 
			// FormPrincipal
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(549, 393);
			this.Controls.Add(this.BtCancel);
			this.Controls.Add(this.BtLast);
			this.Controls.Add(this.BtFirst);
			this.Controls.Add(this.BtNext);
			this.Controls.Add(this.BtPrevious);
			this.Controls.Add(this.BtNew);
			this.Controls.Add(this.TextCountProf);
			this.Controls.Add(this.LblCountProf);
			this.Controls.Add(this.BtModifier);
			this.Controls.Add(this.BtSave);
			this.Controls.Add(this.TextPrenom);
			this.Controls.Add(this.LabPrenom);
			this.Controls.Add(this.TextNom);
			this.Controls.Add(this.LabNom);
			this.Name = "FormPrincipal";
			this.Text = "FormPrincipal";
			this.Load += new System.EventHandler(this.FormPrincipal_Load);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion
		private System.ComponentModel.BackgroundWorker backgroundWorker1;
		private System.Windows.Forms.Label LabNom;
		private System.Windows.Forms.TextBox TextNom;
		private System.Windows.Forms.TextBox TextPrenom;
		private System.Windows.Forms.Label LabPrenom;
		private System.Windows.Forms.Button BtSave;
		private System.Windows.Forms.Button BtModifier;
		private System.Windows.Forms.TextBox TextCountProf;
		private System.Windows.Forms.Label LblCountProf;
		private System.Windows.Forms.Button BtNew;
		private System.Windows.Forms.Button BtPrevious;
		private System.Windows.Forms.Button BtNext;
		private System.Windows.Forms.Button BtFirst;
		private System.Windows.Forms.Button BtLast;
		private System.Windows.Forms.Button BtCancel;
	}
}

