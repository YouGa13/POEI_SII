#include <stdio.h>

#define ARGS_TAB 10


int sum_tabs[ARGS_TAB];

void remplir_tableau(int tabs[]);
void afficher_somme_tabs(int tab_arg1[], int tab_arg2[]);
// autre manière int tab[10] = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
int main(void){
    // structure_while();
    int tab[ARGS_TAB];
    int tab1[ARGS_TAB];

    remplir_tableau(tab);
    remplir_tableau(tab1);

    afficher_somme_tabs(tab, tab1);
}



void remplir_tableau(int tabs[]) {
    for (int i = 0; i < ARGS_TAB; i++){ 
            tabs[i] = i+1;
    }
};

void afficher_somme_tabs(int tab_arg1[], int tab_arg2[]) {
    for (int i = 0; i < ARGS_TAB; i++) {
        if(tab_arg1[i])
            if(tab_arg2[i]){
                sum_tabs[i] = tab_arg1[i] + tab_arg2[i];
                printf("la somme de tab[%d] + tab1[%d] = %d\n", (i+1) , (i+1), sum_tabs[i]);
            }     
    }
};