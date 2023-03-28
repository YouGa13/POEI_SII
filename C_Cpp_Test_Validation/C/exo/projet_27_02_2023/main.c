#include <stdio.h>

#include "modify.h"

int x,y ;

int main() {
    
    printf("Entrez les valeurs de X et Y \n");

    int res = scanf("%d  %d", &x , &y);

    printf("x vaut %d et y vaut %d ", x, y);

    modifyX();
    modifyY();
    
    printf("x vaut now %d et y vaut now %d ", x, y);

    return 0;
}