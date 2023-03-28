#include <stdio.h>
int a,b;
int *ptr_sup(int*a, int*b);
int sup(int a, int b);

void main ()
{
    printf("Entrez deux nombres entiers \n");
    scanf("%d %d", &a, &b);

    sup(a,b);

    printf("%d", *ptr_sup(&a, &b));

    return 0;
}

int *ptr_sup(int*a, int*b){
    if(*a < *b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int sup(int a, int b){
     
    if(a < b)
    {
        printf("a est inferieur à b \n" );
    }
    else
    {
        printf("a est superieur ou égale à b\n" );
    }
}