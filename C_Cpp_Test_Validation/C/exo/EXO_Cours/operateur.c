#include <stdio.h>

#define NBRE_ESSAI_MAX 3
int valeur_a_deviner;
int nbre_essai = 0;
void message(int value, int essai);


int main(void){
    
    

    while ((nbre_essai < NBRE_ESSAI_MAX) && (valeur_a_deviner != 9)) {

        printf("Veuillez entrez un nombre \n");
        scanf_s("%d", &valeur_a_deviner);
        

       
        if(valeur_a_deviner == 9){
            nbre_essai = 2;
        }

        nbre_essai++;
    }

   
    message(valeur_a_deviner, nbre_essai);
    
    return 0;
}

void message(int value, int essai) {
  
        if (essai == NBRE_ESSAI_MAX) {
            if (value == 9) {
                printf("Termine, Vous avez gagne.e, le nombre à deviner est bien 9");
            }
            else printf("Termine, Vous avez perdu.e");
        }
        else {
            if (value == 9) {
                printf("Vous avez gagne.e, le nombre à deviner est bien %d", value);
            }
            else if (( value > 47 ) && (value  < 58)) {
                printf("Il vous reste des essai(s) %d", (NBRE_ESSAI_MAX - essai));
            }
            else {
                printf("veuillez entrer un nombre entier");
            };
        }

    ;
    
}
