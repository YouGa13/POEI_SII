#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAILLE_NOM 30
#define MAX_TAILLE_PRENOM 50

struct pers {
    char nom[MAX_TAILLE_NOM];
    char prenom[MAX_TAILLE_PRENOM];
    int age;
} djibril,
    nicolas = { "mouton-besson", "Nicolas", 27 }, 
    personne_a_copier = { "bah", "djibril", 33 }
    ;

void copier(struct pers *pers1, struct pers *pers2);
void afficher(struct pers *pers_afficher);
void comparer(struct pers *pers1, struct pers *pers2);



char tab_nom[3];
int tab_age[3];
int comparer_personne_par_age(const void* first, const void* second);
int comparer_personne_par_nom(const void* first, const void* second);
void chercher_personne_par_nom();


char recup_nom(struct pers personne);
int recup_age(struct pers personne);



int main(){
    copier(&djibril, &personne_a_copier);
   // afficher(&djibril);
    // comparer(&djibril, &nicolas);
    struct pers tab_struct_pers[3] = { djibril, personne_a_copier, nicolas };
    // tab_struct_pers[0] = djibril;
    // tab_struct_pers[1] = personne_a_copier;
    // tab_struct_pers[2] = nicolas;

    for (int i = 0; i < 3; i++) {
        tab_age[i] = recup_age(tab_struct_pers[i]);
    }

    qsort(tab_age, 3, sizeof(int), comparer_personne_par_age);
    qsort(tab_struct_pers, 3, sizeof(struct pers), comparer_personne_par_nom);

    for (int i = 0; i < 3; i++) {
        printf(" - %u\n", tab_age[i]);
        printf("%s\n", tab_struct_pers[i]);
    }
   
}

void copier(struct pers* pers1, struct pers* pers2) {
    memcpy(pers1, pers2, sizeof(struct pers));
   // pers1->age = pers2->age;
};

void afficher(struct pers* pers_afficher) {
    printf("Nom : %s\nPrenom : %s\nAge : %d\n", 
        pers_afficher->nom, pers_afficher->prenom, pers_afficher->age);
};

void comparer(struct pers* pers1, struct pers* pers2){
     if (pers1->age > pers2->age){
         printf("La premiere personne est plus agée");
     } else {
         printf("La seconde personne est plus agée");
     }
}

char recup_nom(struct pers personne) {
    return personne.nom;
};



int recup_age(struct pers personne) {
    return personne.age;
};


int comparer_personne_par_age(const void* first, const void* second) {
    int firstInt = *(const int*)first;
    int secondInt = *(const int*)second;
    return firstInt - secondInt;
};

int comparer_personne_par_nom(const void* first, const void* second) {
    const struct pers *firstInt = (const struct pers*)first;
    const struct pers *secondInt = (const struct pers*)second;
    return (strcmp(firstInt->nom , secondInt->nom));
};
