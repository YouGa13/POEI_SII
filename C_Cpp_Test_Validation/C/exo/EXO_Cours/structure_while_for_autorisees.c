#include <stdio.h>

#define ARGS_TAB 5
int essai = 0;
int i = 0;
void structure_while_for(void);
int tab[ARGS_TAB];
void afficher_contenu_tab();

int main(void){
    structure_while_for();
    afficher_contenu_tab();
}

void structure_while_for(void){
    while( i < ARGS_TAB) {
        printf("Veuillez entrer un nombre\n");
        scanf("%d", &essai);    
        if ((essai > 1) && (essai < 10)) {
            tab[i] = essai;
            i++;
        }
    }
};

void afficher_contenu_tab() {
    for (int i = 0; i < ARGS_TAB; i++) {
        if(tab[i])
        printf("tab[%d] = %d\n", (i+1) , tab[i]);
    }
};