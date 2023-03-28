#include <stdio.h>

#define NBRE_A_DEVINER 99
#define ARGS_TAB 10
int essai = 0;
void structure_while(void);
int tab[ARGS_TAB];
void remplir_tableau(void);
void afficher_contenu_tab();

int main(void){
    // structure_while();

    remplir_tableau();
    afficher_contenu_tab();
}

void structure_while(void){
    while(essai != 99){
        printf("Veuillez entrer un nombre\n");
        scanf("%d", &essai);
    }
};

void remplir_tableau(void) {
    for (int i = 0; i < ARGS_TAB; i++) {
        if (essai != 51) {
            printf("Veuillez entrer un nombre\n");
            scanf("%d", &essai);
            tab[i] = essai;
        } else i = ARGS_TAB;
    }
    
};

void afficher_contenu_tab() {
    for (int i = 0; i < ARGS_TAB; i++) {
        if(tab[i])
        printf("tab[%d] = %d\n", (i+1) , tab[i]);
    }
};