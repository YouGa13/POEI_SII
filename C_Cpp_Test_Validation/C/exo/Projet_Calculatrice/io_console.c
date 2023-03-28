#include <stdio.h>
#include "io.h"

void print_result(float x, char y){
    switch (y) {
        case "+" : 
            printf("Le resultat de l'addition de ces nombres est %lf\n", x); 
                    break;
        case "*" : 
            printf("Le resultat de la multiplication de ces nombres est %lf\n", x);
                    break;
        default : 
            printf("vous vous êtes trompés d'aperateur"); 
    }
}