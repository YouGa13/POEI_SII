#include <stdio.h>


int main() {
	float x = 100;
	float *ptr_x = &x;

	float **ptr_ptr_x = &ptr_x;

	printf("la valeur de x : %f \nLa valeur de *ptr_x est : %f \nLa valeur de **ptr_ptr_x est : %f", x, *ptr_x, **ptr_ptr_x);

	return 0;
}
