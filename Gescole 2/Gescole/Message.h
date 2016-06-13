#ifndef MESSAGE_H
#define MESSAGE_H

//#define LANG_FR

#ifndef LANG
#define LANG_FR
#endif

#ifdef LANG_FR 
#define LANG
// Ponctuation
#define Pct_Point ". "
#define Pct_DeuxPoint ": "
#define Pct_Espace " "
#define Pct_Tabulation "\t"
#define Pct_Tiret " - "

//Menu
#define Menu_eDossier "Dossier"
#define Menu_eClient "Client"
#define Menu_eLivraison "Livraison"
#define Menu_eCommande "Commande"
#define Menu_eRDV "Rendez-Vous"
#define Menu_eSelect "Selectionner"
#define Menu_eCreate "Cree"
#define Menu_eRead "Afficher l'enregistrement courant"
#define Menu_eUpdate "Modifier"
#define Menu_eDelete "Effacer l'enregistrement courants"
#define Menu_eFirst "Premier"
#define Menu_eNext "Suivant"
#define Menu_ePrevious "Precedent"
#define Menu_eLast "Dernier"
#define Menu_eList "Lister les enregistrement"
#define Menu_eQuit "Quitter"
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
#define Dossier_ ""
#define Dossier_ ""
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


#endif // LANGUE == EN




#endif // !MESSAGE_H
