#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOM 50
#define MAX_PRENOM 50

typedef struct{
	char nom[MAX_NOM];
	char prenom[MAX_PRENOM];
	int age;
}personne;

void afficherPersonne(struct personne *lui);
void afficherToutesLesPersonnes(personne* tableau, int taille);
int comparer_personne_par_nom(const void* a, const void* b);
int comparer_personne_par_age(const void* a, const void* b);
int rechercher_personne_par_nom(personne * nom, personne* tableau, int taille);
void copier(personne* dest, personne* src);

int main(int argc, char* argv[])
{
	personne tableau[4] = { { "CGO","Christian",52}, { "CGO","lui",33}, { "LUI","lui",33}, { "ELLE","elle",60 } };

	int taille = sizeof(tableau) / sizeof(tableau[0]);

	puts("######################################");

	afficherToutesLesPersonnes(tableau, taille);
	puts("######################################");
	puts("Tri par age");
	qsort(tableau, taille, sizeof(personne), comparer_personne_par_age);
	afficherToutesLesPersonnes(tableau, taille);
	puts("Tri par nom");
	qsort(tableau, taille, sizeof(personne), comparer_personne_par_nom);
	afficherToutesLesPersonnes(tableau, taille);



	puts("");

	char nom[MAX_NOM] = "CGO";
	personne tmp = { "CGO", "CGO", 0 };
	int position = rechercher_personne_par_nom(&tmp, tableau, taille);

	if (position == -1) {
		printf("%s n'a pas et trouve.\n", nom);
	}
	else {
		printf("%s a ete trouve a l'indice %d.\n", nom, position );
		afficherPersonne(&tableau[position]);
	}

	exit(EXIT_SUCCESS);
}

void afficherPersonne(personne * lui) 
{
	puts("");
	printf("Nom    : %s\t", lui->nom);
	printf("Prenom : %s\t", lui->prenom);
	printf("age    : %d\n", lui->age);
}

void afficherToutesLesPersonnes(personne* tableau, int taille)
{
	for (int i = 0; i < taille; i++)
	{
		afficherPersonne(&tableau[i]);
	}
}

void copier(personne* dest, personne * src)
{
	*dest = *src;
}

int comparer_personne_par_nom(const void* a, const void* b)
{
	const personne* pa = (const personne*)a;
	const personne* pb = (const personne*)b;
	return (strcmp(pa->nom , pb->nom));
}

int comparer_personne_par_age(const void* a, const void* b)
{
	const personne* pa = (const personne*)a;
	const personne* pb = (const personne*)b;
	return (pa->age - pb->age);
}

int rechercher_personne_par_nom(personne* nom, personne* tableau, int taille)
{
	personne* result = bsearch(nom, tableau, taille, sizeof(personne), comparer_personne_par_nom);
	if (result == NULL)
		return -1;
	else 
		return (result - tableau);
}

