#include <stdio.h>
int value1, value2;
float val1, val2, val3, val4, val5;
int produit();
float division();
float moyenne();
int trois_puissance();
char operation = ' ';

void choisir_operation(){
    printf( "Ecrivez p si c'est une multiplication que vous voulez faire\n");
    printf( "Ecrivez d si c'est une division que vous voulez faire\n");
    printf( "Ecrivez m si c'est calculer une moyenne que vous voulez faire\n");
    printf( "Ecrivez t si c'est calculer trois à la puissance un nombre que vous voulez faire\n");
}


int main(void){
    printf (" Bonjour, Quelle operation voulez-vous faire ??\n");
    choisir_operation();
    scanf("%c", &operation);
    
        switch (operation)
        {
        case 'p':
            printf("%d", produit());
            break;
        case 'd':
            printf("%f", division());
            break;
        case 'm':
            printf("%f", moyenne());
            break;
        case 't':
            printf("%d", trois_puissance());;
            break;
        default:
            printf("Vous vous etes trompes de choix");
            break;
        }
 
    

}

int produit() {
    printf("Veuillez entrer le premier nombre \n");
    scanf("%d", &value1);
    printf("Veuillez entrer le second nombre \n");
    scanf("%d", &value2);
    return (value1 * value2);
};
float division(){

    printf("Veuillez entrer le premier nombre \n");
    scanf("%d", &value1);
    printf("Veuillez entrer le second nombre \n");
    scanf("%d", &value2);

    if (value1 == 0) printf("La division par zéro est impossible");

    return ((float)value1/(value2));
};
float moyenne(){
    printf("Veuillez entrer le premier nombre \n");
    scanf("%f", &val1);
    printf("Veuillez entrer le second nombre \n");
    scanf("%f", &val2);
   
    float somme_args = val1 + val2 ;
    return (somme_args/2);
};
int trois_puissance(){

    printf("Veuillez entrer le  nombre \n");
    scanf("%d", &value1);

    int result = 1;
    for(int i= 0; i <value1; i++){
        result = result*3;
    }
    return result;
};