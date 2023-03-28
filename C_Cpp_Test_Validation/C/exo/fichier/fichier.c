#include <stdio.h>
#include <ctype.h>



int compte(FILE* fichier)
{
	int c;
	int nLignes = 0;
	int c2 = '\0';
	

	while ((c = fgetc(fichier)) != EOF)
	{
		if (c == '\n')
			nLignes++;
		c2 = c;
	}

	/* Ici, c2 est égal au caractère juste avant le EOF. */
	if (c2 != '\n')
		nLignes++; /* Derni�re ligne non finie */

	return nLignes;
}

int main(void)
{
	FILE* fichier = fopen("fichier_a_copier.txt", "r");
	FILE* fichier1 = fopen("fichier_a_copier.txt", "r");
	if (fichier != NULL)
	{	
		int nMots = compte_mots(fichier);

		fclose(fichier);

		int nLignes = compte(fichier1);


		fclose(fichier1);

		printf("Nombre de lignes : %d\nNombre de mots : %d\n", nLignes, nMots);
	}
	else
		puts("Erreur en ouverture du fichier.");
	return 0;
}

int compte_mots(FILE* fichier)
{
	int c;
	int inside_word = 0;
	int nmots = 0;

	/* while (!feof(mon_fichier)) */
	while ((c = fgetc(fichier)) != EOF) /* suite � la remarque de ++Taz */
	{
		//C=fgetc(mon_fichier);
		if (isspace(c))
		{
			if (inside_word)
			{
				nmots++;
				inside_word = 0;
			}
		}
		else
			inside_word = 1;
	}
	
	return nmots;
}
