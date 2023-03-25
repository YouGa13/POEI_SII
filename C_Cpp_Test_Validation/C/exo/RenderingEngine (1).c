#include <stdio.h>

#define WIDTH 3
#define HEIGHT 5
char data2D[HEIGHT][WIDTH] = { { 0, 0, 1 } ,{ 0, 0, 1 } ,{ 0, 0, 1 } ,{ 0, 0, 1 }, { 0, 0, 1 }};
char data2DTmp[HEIGHT][WIDTH] = { { 1, 0, 0 } ,{ 1, 0, 0 } ,{ 1, 0, 1 } ,{ 0, 0, 1 }, { 0, 0, 1 } };

char bus[WIDTH + 1] = { '*', '*', '*','\0' };
char* ptr_r1data2d = &data2D[1]; // for debug
char* ptr_r2data2d = &data2D[2]; //for debug

void dataToBus(char* data);
char* getAdresseRowFomData2D(int row); //deprecated
char* getAdresseRowFromData2DAdresse(int row, char* data2d);
void displayData2D(char* ptr_data2d);

int main() {
	displayData2D(data2D);
	puts("Nv display.");
	displayData2D(data2DTmp);
	return 0;
}

void displayData2D(char* ptr_data2D) {
	for (int i = 0; i < HEIGHT; i++)
	{
		dataToBus(getAdresseRowFromData2DAdresse(i, ptr_data2D));
		puts(bus);
	}
}

char* getAdresseRowFomData2D(int row) {
	return &data2D[row];
}
char* getAdresseRowFromData2DAdresse(int row, char* data2d) {
	return &data2d[row*WIDTH];
}

void dataToBus(char* data) {
	for (int i = 0; i < WIDTH; i++) {
		bus[i] = (!data[i]) ? '_' : '*';
	}
}