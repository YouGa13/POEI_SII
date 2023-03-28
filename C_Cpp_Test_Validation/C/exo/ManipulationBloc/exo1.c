// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_NOM 50
// #define MAX_ADRESSE 100

// void copier_personne(unsigned char tab1[], unsigned char tab2[], int taille);
// void initialiser_personne(unsigned char tab1[], unsigned char tab2[]);

// int main() {
// 	unsigned char nom[MAX_NOM];
// 	unsigned char adresse[MAX_ADRESSE];
	
// 	unsigned char caracter[MAX_NOM];
// 	unsigned char adresse_caracter[MAX_ADRESSE];

// 	initialiser_personne(caracter, "Jean Dupont\0");
// 	initialiser_personne(adresse_caracter, "1 rue de la Paix, 75008 Paris\0" );

// 	copier_personne(nom, caracter, strlen(caracter));
// 	copier_personne(adresse, adresse_caracter, strlen(adresse_caracter));

// 	printf("Nom : %s \nAdresse : %s \n", nom, adresse);

// 	return 0;
// }

// void initialiser_personne(unsigned char tab1[], unsigned char tab2[]) {
// 	strcpy(tab1, tab2);
// 	// memcpy(destination, source, taille)
	
// }

// void copier_personne(unsigned char tab1[], unsigned char tab2[], int taille) {
// 	int Indice;
// 	for (Indice = 0; Indice < taille+1; Indice++) {
// 		tab1[Indice] = tab2[Indice];
// 	}
// }