#include <stdio.h>

#include "io.h"

void print_result(float x, char operator, float y, float result) {
    FILE *file_ptr;
    char *filename = "output.txt";

    file_ptr = fopen(filename, "w");
    if (file_ptr == NULL) {
        fprintf(stderr, "Couldn't open %s\n", filename);
        return;
    }
    fprintf(file_ptr, "%f %c %f = %f\n", x, operator, y, result);
    fclose(file_ptr);
}
