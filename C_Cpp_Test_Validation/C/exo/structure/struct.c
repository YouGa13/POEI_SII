#include <stdio.h>
#include <stdlib.h>
#define MAX_TAILLE_NOM 30
#define MAX_TAILLE_PRENOM 50

struct pers {
    char nom[MAX_TAILLE_NOM];
    char prenom[MAX_TAILLE_PRENOM];
    float montant;
} djibril;
       
int main(){
 
    printf("Quel votre nom ?  ");
    scanf("%s", djibril.nom);

    printf("Quel votre prénom ?  ");
    scanf("%s", djibril.prenom);
  
    printf("Quel est le montant ?  ");
    scanf("%f", &djibril.montant);
   
    
    printf("Nom : %s\n Prenom : %s\n Montant : %f\n", djibril.nom, djibril.prenom, djibril.montant);
    
    
    
}

