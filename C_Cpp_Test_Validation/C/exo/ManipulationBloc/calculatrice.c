#include <stdio.h>
#include <stdlib.h>

int multiply(int x, int y);
int add(int x, int y);
int substract(int x, int y);
int calculatrice(int first, int second, int (*fonction)(int x, int y));

int main(){
    int a , b;

    char operateur;

    int (*operation)(int, int);

    while (1) {
        printf("Choisissez l'operateur : \n");
        scanf("%c", &operateur);

        switch (operateur) {
            case '+' : 
                operation = add;
                break;
            case '-' : 
                operation = substract;
                break;
            case '*' :
            case 'x' :
            case 'X' :
                operation = multiply;
                break;
            case 'q' :
                exit(1);
        }


        printf("Entrez 2 entiers : \n");
        scanf("%d %d", &a, &b);

        calculatrice(a, b, operation);
    }


    
}


int calculatrice(int first, int second, int (*fonction)(int x, int y)){
   int result = fonction(first, second);

    printf("\n%d\n", result);
    //     switch (fonction) {
    //     case multiply :
    //     case 'x':
    //     case '.':
    //         result = (first, second);
    //         break;
    //     case '+':
    //         result = add(first, second);
    //         break;
    //     case '-':
    //         result = substract(first, second);
    //         break;
    //     case '/':
    //         result = divide(first, second);
    //         break;
    //     default:
    //         fprintf(stderr, "%c is not supported\n", ope);
    //         exit(EXIT_FAILURE);
    //         break;
    // }

    }


int multiply(int x, int y) { return x * y; }
int add(int x, int y) { return x + y; }

int substract(int x, int y) { return x - y; }
