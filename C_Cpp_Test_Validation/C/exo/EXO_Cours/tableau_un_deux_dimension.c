#include <stdio.h>
#define ARGS_TAB 10
int tab[ARGS_TAB];

void remplir_tableau(void);
void afficher_contenu_tab();
// autre manière int tab[10] = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
int main(void){
    // structure_while();

    remplir_tableau();
    afficher_contenu_tab();
}



void remplir_tableau(void) {
    for (int i = 0; i < ARGS_TAB; i++){ 
            tab[i] = i+1;
    }
};

void afficher_contenu_tab() {
    for (int i = 0; i < ARGS_TAB; i++) {
        if(tab[i])
        printf("tab[%d] = %d\n", (i+1) , tab[i]);
    }
};