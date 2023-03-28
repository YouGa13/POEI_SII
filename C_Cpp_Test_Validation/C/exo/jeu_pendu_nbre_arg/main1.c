#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int evaluate_expression(int counter, ...);

typedef struct {
    char op;
    double d;
} op_oper;
double evaluate_struct(int nbr, ...);

int main( ) {

    int result = evaluate_expression(3,'+', 3, '-', 11);
    printf( "addition( 3, 3, '-', 11 ) == %d\n", result );     


    //result = evaluate_expression( 3 , 4, 5, 6 );
    //printf( "addition( 3, 4, 5, 6 ) == %d\n", result ); 

    return EXIT_SUCCESS;

}

int evaluate_expression(int counter, ...) {
    int sum = 0;
    va_list parametersInfos;
    /* Initialize the va_list structure */
    va_start(parametersInfos, counter);

    // int sum = va_arg(parametersInfos, int);

    /* for all unnamed integer, do an addition */
    for (int i = 0; i < counter; i++) {
        switch (va_arg(parametersInfos, char)) {
        case '-':
            sum -= va_arg(parametersInfos, int);
            break;
        case '+':
            sum += va_arg(parametersInfos, int);
            break;
        default:
            printf("Verifiez vos entrés");
            break;
        };
    }
    va_end(parametersInfos);
    return sum;
}

double evaluate_struct(int nbr, ...) {
    
}

