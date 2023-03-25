#include <stdio.h>

#include "io.h"

void print_result(float x, char operator, float y, float result) {
    printf("%f %c %f = %f\n", x, operator, y, result);
}
