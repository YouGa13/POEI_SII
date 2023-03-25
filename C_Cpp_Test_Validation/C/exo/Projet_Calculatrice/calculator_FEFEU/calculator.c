#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arithmetic.h"
#include "io.h"

int main(int argc, char **argv) {
    float first  = 0;
    float second = 1;
    char  ope    = '+';
    float result = 0;

    /* arguments handling */
    if (argc != 4) {
        fprintf(stderr, "Usage %s: FIRST_FLOAT OPERATOR SECOND_FLOAT\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }
    /* end of arguments handling */

    first  = (float) atof(argv[1]);
    ope    = argv[2][0];
    second = (float) atof(argv[3]);

    switch (ope) {
        case '*':
        case 'x':
        case '.':
            result = multiply(first, second);
            break;
        case '+':
            result = add(first, second);
            break;
        case '-':
            result = substract(first, second);
            break;
        case '/':
            result = divide(first, second);
            break;
        default:
            fprintf(stderr, "%c is not supported\n", ope);
            exit(EXIT_FAILURE);
            break;
    }

    print_result(first, ope, second, result);

    exit(EXIT_SUCCESS);
}
