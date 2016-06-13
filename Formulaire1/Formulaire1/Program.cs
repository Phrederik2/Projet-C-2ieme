using System;
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
			List<Professeur> ContainerProf = new List<Professeur>();
            ConnectAccess Mydb = new ConnectAccess(ContainerProf);
			Form.setContainer(ContainerProf);
			Application.Run(Form);

        }
    }
}
