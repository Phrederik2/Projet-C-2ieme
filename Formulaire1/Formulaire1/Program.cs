﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Formulaire1
{
    static class Program
    {
        /// <summary>
        /// Point d'entrée principal de l'application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
			FormPrincipal Form = new FormPrincipal();
			List<Client> Container = new List<Client>();
            Stream db = new Stream();
            db.Read(Container);
			Form.setContainer(Container);
			Application.Run(Form);
            db.Write(Container);

        }
    }
}
