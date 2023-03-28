#include <stdio.h>
#include <stdlib.h>
#include "arithmetic.h"
#include "io.h"

void operations(char operator[1], float *tabArguments[]) {
    switch (operator[0]) {
        case '+':
            int somme = 0;
            for (int i = 0; i < sizeof(tabArguments); i++)
                somme = somme + atof(tabArguments[i]);
                print_result(somme, tabArguments);
            break;
        case '*':
        case '.':
        case 'x':
        case 'X':
            int multiplication = 1;
            for (int i = 0; i < sizeof(tabArguments); i++)
                multiplication *= atof(tabArguments[i]);
            
            print_result(somme, tabArguments);
            break;
        case '/':
            int division = atof(tabArguments[0]);
            for (int i = 1; i < sizeof(tabArguments); i++)
                division = division / atof(tabArguments[i]);
            break;
        case '-':
            int somme = 0;
            for (int i = 0; i < sizeof(tabArguments); i++)
                somme = somme + tabArguments[i];
            
            printf("Le resultat de l'addition de ces nombres est %lf\n", somme);
            break;
        default:
            printf("Vous vous êtes trompés d'operateur");
    }
}