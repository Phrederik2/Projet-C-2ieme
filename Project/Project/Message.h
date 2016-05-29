#pragma once


#define LANGUE_FR


//--------------------------
// Standard a toute les langues.
//--------------------------

#define ADRESSE_DEUXPOINT ": "
#define ASRESSE_LIGNE "---------------------------------------------"
#define ASRESSE_VIDE ''

#if defined (LANGUE_FR)

#define ADRESSE_ID "ID"
#define ASRESSE_LOCALITE "Localite"
#define ASRESSE_RUE "Rue"
#define ASRESSE_NUMERO "Numero"
#define ASRESSE_BOITE "Boite"
#define ASRESSE_CODEPOSTAL "Code Postal"
#define ASRESSE_INCONNU "Inconnu"
#define ASRESSE_ADRESSE "Adresse"
#define ASRESSE_INSTANCE "Nombre d'instance d'Adresse: "

#endif // Langue française

#if defined (LANGUE_EN)

#define ADRESSE_ID "ID"
#define ASRESSE_LOCALITE "Locality"
#define ASRESSE_RUE "Street"
#define ASRESSE_NUMERO "Number"
#define ASRESSE_BOITE "Box"
#define ASRESSE_CODEPOSTAL "Postal code"
#define ASRESSE_INCONNU "Unknown"
#define ASRESSE_ADRESSE "Address"
#define ASRESSE_INSTANCE "Number of instance of Address: "



#endif // Langue anglaise