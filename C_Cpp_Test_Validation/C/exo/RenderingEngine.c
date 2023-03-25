#include <stdio.h>

#define WIDTH 3
#define HEIGHT 5

char data2D[HEIGHT][WIDTH] = { { 0, 0, 1 } ,{ 0, 0, 1 } ,{ 0, 0, 1 } ,{ 0, 0, 1 }, { 0, 0, 1 }};

char bus[WIDTH + 1] = { '*', '*', '*','\0' }; // initialisation du chaine de caractère bus

void dataToBus(char* data);

char* getAdresseRowFomData2D(int row);

void displayData2D();

int main() {
	displayData2D();
	return 0;
}


void displayData2D() {
	for (int i = 0; i < HEIGHT; i++)
	{
		dataToBus(getAdresseRowFomData2D(i));
		puts(bus);
	}
}

// recupere l'index des matrices
char* getAdresseRowFomData2D(int row) {
	return &data2D[row];
}

// fonction qui modifie les carcatères du chaine de caractère u
void dataToBus(char* data) {
	for (int i = 0; i < WIDTH; i++) {
		bus[i] = (!data[i]) ? '_' : '*';
	}
}