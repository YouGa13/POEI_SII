#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRENOM 50
#define MAX_NOM 50
struct user {

	char *prenom;
	char *nom;
	float montant;
} don_mbr;

void Initialiser_compte(char* prenom, char* nom, float *montant);
void Initialiser_compte(char *prenom,char *nom, float *montant) {


	printf("Veuillez saisir votre prenom \n");
	scanf("%s", prenom);

	printf("Veuillez saisir votre nom \n");
	scanf("%s", nom);

	printf("Veuillez saisir le montant du don \n");
	scanf("%f", montant);

}

int main() {
	don_mbr.prenom = (char*)malloc(MAX_PRENOM * sizeof(char));
	don_mbr.nom = (char*)malloc(MAX_NOM * sizeof(char));
	Initialiser_compte(don_mbr.prenom, don_mbr.nom, &don_mbr.montant);

	printf("%s %s a sur son compte %f CHF \n", don_mbr.prenom, don_mbr.nom, don_mbr.montant);

	free(don_mbr.prenom);
	free(don_mbr.nom);

	return 0;
	
}

