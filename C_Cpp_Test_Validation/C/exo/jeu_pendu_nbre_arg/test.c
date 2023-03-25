#include <stdio.h>
#include <string.h>

#define NBRE_D_INDICE 1
#define NBRE_C_A_DEVINER 6
char liste[NBRE_D_INDICE][8] = { "mnitiaeu" };


int main(void) {
    int nbre = 0;
    int i = 0;
    while (i < NBRE_C_A_DEVINER) {
        nbre = nbAleatoire(0, 8);
        if (liste[NBRE_D_INDICE][nbre] != '_') {
            liste[NBRE_D_INDICE][nbre] = '_';
            i++;
        };
    };
    printf("%s", liste[NBRE_D_INDICE - 1]);
    return 0;
}

int nbAleatoire(int min, int max)
{
    int nbAl;
    nbAl = rand() % (max + 1) + min;
    return nbAl;
}
