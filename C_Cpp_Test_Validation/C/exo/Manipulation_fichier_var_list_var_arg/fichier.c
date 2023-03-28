#include <stdio.h>
#include "io.h"


void print_result(long x) {
	FILE *fichier = fopen("output.txt", "w");

	if(!fichier) return;

	fprintf(fichier, "Resultat %ld", x);

	fclose(fichier);
}