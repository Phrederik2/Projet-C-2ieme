#pragma once


#define LANGUE_FR


//--------------------------
// Standard a toute les langues.
//--------------------------

#define ADRESSE_DEUXPOINT ": "
#define ADRESSE_LIGNE "---------------------------------------------"
#define ADRESSE_VIDE ''

#if defined (LANGUE_FR)

#define ADRESSE_ID "ID"
#define ADRESSE_LOCALITE "Localite"
#define ADRESSE_RUE "Rue"
#define ADRESSE_NUMERO "Numero"
#define ADRESSE_BOITE "Boite"
#define ADRESSE_CODEPOSTAL "Code Postal"
#define ADRESSE_INCONNU "Inconnu"
#define ADRESSE_ADRESSE "Adresse"
#define ADRESSE_INSTANCE "Nombre d'instance d'Adresse: "

#endif // Langue française

#if defined (LANGUE_EN)

#define ADRESSE_ID "ID"
#define ADRESSE_LOCALITE "Locality"
#define ADRESSE_RUE "Street"
#define ADRESSE_NUMERO "Number"
#define ADRESSE_BOITE "Box"
#define ADRESSE_CODEPOSTAL "Postal code"
#define ADRESSE_INCONNU "Unknown"
#define ADRESSE_ADRESSE "Address"
#define ADRESSE_INSTANCE "Number of instance of Address: "



#endif // Langue anglaise