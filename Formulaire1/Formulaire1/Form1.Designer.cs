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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormPrincipal));
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.LabNom = new System.Windows.Forms.Label();
            this.TextNom = new System.Windows.Forms.TextBox();
            this.TextPrenom = new System.Windows.Forms.TextBox();
            this.LabPrenom = new System.Windows.Forms.Label();
            this.BtSave = new System.Windows.Forms.Button();
            this.BtModifier = new System.Windows.Forms.Button();
            this.TextCount = new System.Windows.Forms.TextBox();
            this.LblCountProf = new System.Windows.Forms.Label();
            this.BtNew = new System.Windows.Forms.Button();
            this.BtPrevious = new System.Windows.Forms.Button();
            this.BtNext = new System.Windows.Forms.Button();
            this.BtFirst = new System.Windows.Forms.Button();
            this.BtLast = new System.Windows.Forms.Button();
            this.BtCancel = new System.Windows.Forms.Button();
            this.TextSociete = new System.Windows.Forms.TextBox();
            this.LabSociete = new System.Windows.Forms.Label();
            this.TextLocalite = new System.Windows.Forms.TextBox();
            this.LabLocalite = new System.Windows.Forms.Label();
            this.TextNumero = new System.Windows.Forms.TextBox();
            this.LabNumero = new System.Windows.Forms.Label();
            this.TextRue = new System.Windows.Forms.TextBox();
            this.LabRue = new System.Windows.Forms.Label();
            this.TextBoite = new System.Windows.Forms.TextBox();
            this.LabBoite = new System.Windows.Forms.Label();
            this.TextCodePostal = new System.Windows.Forms.TextBox();
            this.LabCodePostal = new System.Windows.Forms.Label();
            this.TextID = new System.Windows.Forms.TextBox();
            this.LabID = new System.Windows.Forms.Label();
            this.checkBoxSupprimer = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // LabNom
            // 
            resources.ApplyResources(this.LabNom, "LabNom");
            this.LabNom.Name = "LabNom";
            // 
            // TextNom
            // 
            this.TextNom.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this.TextNom, "TextNom");
            this.TextNom.Name = "TextNom";
            this.TextNom.ReadOnly = true;
            // 
            // TextPrenom
            // 
            this.TextPrenom.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this.TextPrenom, "TextPrenom");
            this.TextPrenom.Name = "TextPrenom";
            this.TextPrenom.ReadOnly = true;
            // 
            // LabPrenom
            // 
            resources.ApplyResources(this.LabPrenom, "LabPrenom");
            this.LabPrenom.Name = "LabPrenom";
            // 
            // BtSave
            // 
            resources.ApplyResources(this.BtSave, "BtSave");
            this.BtSave.Name = "BtSave";
            this.BtSave.UseVisualStyleBackColor = true;
            // 
            // BtModifier
            // 
            resources.ApplyResources(this.BtModifier, "BtModifier");
            this.BtModifier.Name = "BtModifier";
            this.BtModifier.UseVisualStyleBackColor = true;
            // 
            // TextCount
            // 
            this.TextCount.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this.TextCount, "TextCount");
            this.TextCount.Name = "TextCount";
            this.TextCount.ReadOnly = true;
            this.TextCount.TabStop = false;
            // 
            // LblCountProf
            // 
            resources.ApplyResources(this.LblCountProf, "LblCountProf");
            this.LblCountProf.Name = "LblCountProf";
            // 
            // BtNew
            // 
            resources.ApplyResources(this.BtNew, "BtNew");
            this.BtNew.Name = "BtNew";
            this.BtNew.UseVisualStyleBackColor = true;
            this.BtNew.Click += new System.EventHandler(this.BtNew_Click);
            // 
            // BtPrevious
            // 
            resources.ApplyResources(this.BtPrevious, "BtPrevious");
            this.BtPrevious.Name = "BtPrevious";
            this.BtPrevious.UseVisualStyleBackColor = true;
            this.BtPrevious.Click += new System.EventHandler(this.BtPrevious_Click);
            // 
            // BtNext
            // 
            resources.ApplyResources(this.BtNext, "BtNext");
            this.BtNext.Name = "BtNext";
            this.BtNext.UseVisualStyleBackColor = true;
            this.BtNext.Click += new System.EventHandler(this.BtNext_Click);
            // 
            // BtFirst
            // 
            resources.ApplyResources(this.BtFirst, "BtFirst");
            this.BtFirst.Name = "BtFirst";
            this.BtFirst.UseVisualStyleBackColor = true;
            this.BtFirst.Click += new System.EventHandler(this.BtFirst_Click);
            // 
            // BtLast
            // 
            resources.ApplyResources(this.BtLast, "BtLast");
            this.BtLast.Name = "BtLast";
            this.BtLast.UseVisualStyleBackColor = true;
            this.BtLast.Click += new System.EventHandler(this.BtLast_Click);
            // 
            // BtCancel
            // 
            resources.ApplyResources(this.BtCancel, "BtCancel");
            this.BtCancel.Name = "BtCancel";
            this.BtCancel.UseVisualStyleBackColor = true;
            this.BtCancel.Click += new System.EventHandler(this.BtCancel_Click);
            // 
            // TextSociete
            // 
            this.TextSociete.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this.TextSociete, "TextSociete");
            this.TextSociete.Name = "TextSociete";
            this.TextSociete.ReadOnly = true;
            // 
            // LabSociete
            // 
            resources.ApplyResources(this.LabSociete, "LabSociete");
            this.LabSociete.Name = "LabSociete";
            // 
            // TextLocalite
            // 
            this.TextLocalite.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this.TextLocalite, "TextLocalite");
            this.TextLocalite.Name = "TextLocalite";
            this.TextLocalite.ReadOnly = true;
            // 
            // LabLocalite
            // 
            resources.ApplyResources(this.LabLocalite, "LabLocalite");
            this.LabLocalite.Name = "LabLocalite";
            // 
            // TextNumero
            // 
            this.TextNumero.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this.TextNumero, "TextNumero");
            this.TextNumero.Name = "TextNumero";
            this.TextNumero.ReadOnly = true;
            // 
            // LabNumero
            // 
            resources.ApplyResources(this.LabNumero, "LabNumero");
            this.LabNumero.Name = "LabNumero";
            // 
            // TextRue
            // 
            this.TextRue.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this.TextRue, "TextRue");
            this.TextRue.Name = "TextRue";
            this.TextRue.ReadOnly = true;
            // 
            // LabRue
            // 
            resources.ApplyResources(this.LabRue, "LabRue");
            this.LabRue.Name = "LabRue";
            // 
            // TextBoite
            // 
            this.TextBoite.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this.TextBoite, "TextBoite");
            this.TextBoite.Name = "TextBoite";
            this.TextBoite.ReadOnly = true;
            // 
            // LabBoite
            // 
            resources.ApplyResources(this.LabBoite, "LabBoite");
            this.LabBoite.Name = "LabBoite";
            // 
            // TextCodePostal
            // 
            this.TextCodePostal.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this.TextCodePostal, "TextCodePostal");
            this.TextCodePostal.Name = "TextCodePostal";
            this.TextCodePostal.ReadOnly = true;
            // 
            // LabCodePostal
            // 
            resources.ApplyResources(this.LabCodePostal, "LabCodePostal");
            this.LabCodePostal.Name = "LabCodePostal";
            // 
            // TextID
            // 
            this.TextID.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this.TextID, "TextID");
            this.TextID.Name = "TextID";
            this.TextID.ReadOnly = true;
            this.TextID.TabStop = false;
            // 
            // LabID
            // 
            resources.ApplyResources(this.LabID, "LabID");
            this.LabID.Name = "LabID";
            // 
            // checkBoxSupprimer
            // 
            resources.ApplyResources(this.checkBoxSupprimer, "checkBoxSupprimer");
            this.checkBoxSupprimer.Name = "checkBoxSupprimer";
            this.checkBoxSupprimer.UseVisualStyleBackColor = true;
            // 
            // FormPrincipal
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.checkBoxSupprimer);
            this.Controls.Add(this.TextID);
            this.Controls.Add(this.LabID);
            this.Controls.Add(this.TextCodePostal);
            this.Controls.Add(this.LabCodePostal);
            this.Controls.Add(this.TextBoite);
            this.Controls.Add(this.LabBoite);
            this.Controls.Add(this.TextNumero);
            this.Controls.Add(this.LabNumero);
            this.Controls.Add(this.TextRue);
            this.Controls.Add(this.LabRue);
            this.Controls.Add(this.TextLocalite);
            this.Controls.Add(this.LabLocalite);
            this.Controls.Add(this.TextSociete);
            this.Controls.Add(this.LabSociete);
            this.Controls.Add(this.BtCancel);
            this.Controls.Add(this.BtLast);
            this.Controls.Add(this.BtFirst);
            this.Controls.Add(this.BtNext);
            this.Controls.Add(this.BtPrevious);
            this.Controls.Add(this.BtNew);
            this.Controls.Add(this.TextCount);
            this.Controls.Add(this.LblCountProf);
            this.Controls.Add(this.BtModifier);
            this.Controls.Add(this.BtSave);
            this.Controls.Add(this.TextPrenom);
            this.Controls.Add(this.LabPrenom);
            this.Controls.Add(this.TextNom);
            this.Controls.Add(this.LabNom);
            this.Name = "FormPrincipal";
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
		private System.Windows.Forms.TextBox TextCount;
		private System.Windows.Forms.Label LblCountProf;
		private System.Windows.Forms.Button BtNew;
		private System.Windows.Forms.Button BtPrevious;
		private System.Windows.Forms.Button BtNext;
		private System.Windows.Forms.Button BtFirst;
		private System.Windows.Forms.Button BtLast;
		private System.Windows.Forms.Button BtCancel;
        private System.Windows.Forms.TextBox TextSociete;
        private System.Windows.Forms.Label LabSociete;
        private System.Windows.Forms.TextBox TextLocalite;
        private System.Windows.Forms.Label LabLocalite;
        private System.Windows.Forms.TextBox TextNumero;
        private System.Windows.Forms.Label LabNumero;
        private System.Windows.Forms.TextBox TextRue;
        private System.Windows.Forms.Label LabRue;
        private System.Windows.Forms.TextBox TextBoite;
        private System.Windows.Forms.Label LabBoite;
        private System.Windows.Forms.TextBox TextCodePostal;
        private System.Windows.Forms.Label LabCodePostal;
        private System.Windows.Forms.TextBox TextID;
        private System.Windows.Forms.Label LabID;
        private System.Windows.Forms.CheckBox checkBoxSupprimer;
    }
}

