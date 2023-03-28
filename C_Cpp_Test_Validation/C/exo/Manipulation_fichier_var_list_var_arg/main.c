#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "io.h"


int main() {

    int X;

    printf("Veuillez saisir unnombre entier : ");
    scanf("%d", &X);
   
    print_result(sqr(X));

    return EXIT_SUCCESS;
}