#include <stdio.h>

#define WIDTH 3
#define HEIGHT 5

void displayRow(unsigned char* row);
void displayTable(unsigned char* table);
void dataToBus(unsigned char *row, int value);

char bus[WIDTH + 1] = { ' ',' ',' ','\0' };

int main()
{
    unsigned char patternstorage[10][5][3] = { {{1,1,1},{1,0,1},{1,0,1},{1,0,1},{1,1,1}},   // 0
                                               {{0,0,1},{0,1,1},{1,0,1},{0,0,1},{0,0,1}},   // 1
                                               {{1,1,1},{0,0,1},{1,1,1},{1,0,0},{1,1,1}},   // 2
                                               {{1,1,1},{0,0,1},{1,1,1},{0,0,1},{1,1,1}},   // 3
                                               {{1,0,1},{1,0,1},{1,1,1},{0,0,1},{0,0,1}},   // 4
                                               {{1,1,1},{1,0,0},{1,1,1},{0,0,1},{1,1,1}},   // 5
                                               {{1,1,1},{1,0,0},{1,1,1},{1,0,1},{1,1,1}},   // 6
                                               {{1,1,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1}},   // 7
                                               {{1,1,1},{1,0,1},{1,1,1},{1,0,1},{1,1,1}},   // 8
                                               {{1,1,1},{1,0,1},{1,1,1},{0,0,1},{1,1,1}} }; // 9
    
    int choice_menu = 0;
    int number = 0;

    printf("Que veux-tu faire ?\n(1) Choisir un nombre a afficher.\n(2) Afficher tous les nombres.\n");
    scanf("%d", &choice_menu);

    if (choice_menu == 1) {
        printf("Quel nombre veux-tu afficher ?\n");
        scanf("%d", &number);
        displayTable(patternstorage[number]);
    }
    else if (choice_menu == 2) {
        for (; number < 10; number++) {
            displayTable(patternstorage[number]);       // Ou     displaynumber(patternstorage + number);    -> On donne en argument l'adresse du debut du tableau du nombre voulu.
            printf("\n");
        }

    }
    return 0;
}


void displayRow(unsigned char* row) {
    /* Prend en entree l'adresse du debut d'une ligne, affiche le bus lie a cette ligne. */
    for (int colonne = 0; colonne < WIDTH; colonne++) {
        dataToBus(row, colonne);
    }
    puts(bus);
}

void displayTable(unsigned char* table) {
    /* Prend en entree l'adresse d'un tableau 2D, affiche le bus lie a ce tableau. */
    for (int ligne = 0; ligne < HEIGHT; ligne++) {
        displayRow(table + ligne*WIDTH);              // adresse de table + (1 * 3), pour le forcer a se rendre en ligne suivante.
    }
}

void dataToBus(unsigned char *row, int row_idx) {
    /* Prend en entree l'adresse du debut d'une ligne et un index pour se reperer
       sur cette ligne, puis attribue le symbole correspondant dans le bus.        */
    if (row[row_idx] == 0) {
        bus[row_idx] = ' ';
    }
    else {
        bus[row_idx] = '*';
    }
}