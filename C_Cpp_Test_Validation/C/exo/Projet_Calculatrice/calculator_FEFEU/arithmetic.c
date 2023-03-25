#include "arithmetic.h"

#include <stdio.h>
#include <stdlib.h>

float multiply(float x, float y) { return x * y; }
float add(float x, float y) { return x + y; }

float substract(float x, float y) { return x - y; }

float divide(float x, float y) {
    if (y == 0) {
        fprintf(stderr, "WARNING. Cannot divide by 0\n");
        exit(EXIT_FAILURE);
    } else {
        return x / y;
    }
}