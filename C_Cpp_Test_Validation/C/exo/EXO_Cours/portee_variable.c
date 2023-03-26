#include <stdio.h>

#define ARGS_TAB 10
void initialiser_afficher();
void initialiser_afficher2(int arg);

int var;


int main(void){
    int var2 =0;
    initialiser_afficher();
    initialiser_afficher2(var2);
}
void initialiser_afficher2(int arg) {
    arg = 10;
    printf("la variable var2 entree vaut %d\n", arg);
};


void initialiser_afficher() {
    var = 10;
    printf("la variable var entree vaut %d\n", var);
};