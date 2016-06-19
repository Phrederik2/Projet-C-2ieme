#ifndef MESSAGE_H
#define MESSAGE_H

// Ponctuation
#define Pct_Point ". "
#define Pct_DeuxPoint ": "
#define Pct_Espace " "
#define Pct_Tabulation "\t"
#define Pct_Tiret " - "

//#define LANG_EN

#ifndef LANG
#define LANG_FR
#endif

#ifdef LANG_FR 
#define LANG


//Menu
#define Menu_eDossier "Dossier"
#define Menu_eClient "Client"
#define Menu_eLivraison "Livraison"
#define Menu_eCommande "Commande"
#define Menu_eRDV "Rendez-Vous"
#define Menu_eSelect "Selectionne"
#define Menu_eCreate "Cree"
#define Menu_eRead "Afficher l'enregistrement courant"
#define Menu_eUpdate "Modifie"
#define Menu_eDelete "Effacer l'enregistrement courants"
#define Menu_eFirst "Premier"
#define Menu_eNext "Suivant"
#define Menu_ePrevious "Precedent"
#define Menu_eLast "Dernier"
#define Menu_eList "Lister les enregistrement"
#define Menu_eQuit "Quitte"
#define Menu_Choice "Votre choix"

//Titre
#define Titre_Lancer "Menu Principal"
#define Titre_Dossier "Dossier"
#define Titre_Livraison "Livraison"
#define Titre_Commande "Commande"
#define Titre_Client "Client"
#define Titre_RDV "Rendez-Vous"
// Dossier
#define Dossier_ID "ID"
#define Dossier_Client "Client"
#define Dossier_RDV "Rendez-vous"
#define Dossier_Livraison "Livraison"
#define Dossier_Commande "Commande"
// Client
#define Client_ID "ID"
#define Client_Nom "Nom"
#define Client_Prenom "Prenom"
#define Client_Societe "Societe"
#define Client_Localite "Localite"
#define Client_Rue "Rue"
#define Client_Numero "Numero"
#define Client_Boite "Boite"
#define Client_CodePostal "Code Postal"
// Livraison
#define Livraison_ID "ID"
#define Livraison_Statut "Statut"
// Commande
#define Commande_ID "ID"
#define Commande_Statut "Statut"
// Rendez-vous
#define RDV_ID "ID"
#define RDV_DateDebut "Date de debut"
#define RDV_DateFin "Date de fin"
#define RDV_Remarque "Remarque"
#define RDV_Debut "Debut"
#define RDV_Fin "Fin"
// Date
#define Date_Jour "Jour"
#define Date_Mois "Mois"
#define Date_Annee "Annee"





#endif // LANGUE == FR

#ifdef LANG_EN
#define LANG

//Menu
#define Menu_eDossier "Folder"
#define Menu_eClient "Customer"
#define Menu_eLivraison "Delivery"
#define Menu_eCommande "Order"
#define Menu_eRDV "Appointment"
#define Menu_eSelect "Selected"
#define Menu_eCreate "Creates"
#define Menu_eRead "View the current record"
#define Menu_eUpdate "Amended"
#define Menu_eDelete "Delete the current record"
#define Menu_eFirst "First"
#define Menu_eNext "Next"
#define Menu_ePrevious "Previous"
#define Menu_eLast "Last"
#define Menu_eList "List registration"
#define Menu_eQuit "Quits"
#define Menu_Choice "Your choice"

//Titre
#define Titre_Lancer "Main menu"
#define Titre_Dossier "Folder"
#define Titre_Livraison "Delivery"
#define Titre_Commande "Order"
#define Titre_Client "Customer"
#define Titre_RDV "Appiontment"
// Dossier
#define Dossier_ID "ID"
#define Dossier_Client "Customer"
#define Dossier_RDV "Appointment"
#define Dossier_Livraison "Delivery"
#define Dossier_Commande "Order"
// Client
#define Client_ID "ID"
#define Client_Nom "Last name"
#define Client_Prenom "First name"
#define Client_Societe "Society"
#define Client_Localite "Locality"
#define Client_Rue "Street"
#define Client_Numero "Number"
#define Client_Boite "box"
#define Client_CodePostal "Postal code"
// Livraison
#define Livraison_ID "ID"
#define Livraison_Statut "Statut"
// Commande
#define Commande_ID "ID"
#define Commande_Statut "Statut"
// Rendez-vous
#define RDV_ID "ID"
#define RDV_DateDebut "Start date"
#define RDV_DateFin "End date"
#define RDV_Remarque "note"
#define RDV_Debut "Start"
#define RDV_Fin "End"
// Date
#define Date_Jour "Day"
#define Date_Mois "Month"
#define Date_Annee "Year"

#endif // LANGUE == EN




#endif // !MESSAGE_H
