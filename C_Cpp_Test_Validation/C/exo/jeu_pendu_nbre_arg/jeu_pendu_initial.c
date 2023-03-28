#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "jeu_pendu.h"

// Declaration des procedures du bonhomme pendu et fonction Random
void pendu1();
void pendu6();
void pendu5();
void pendu4();
void pendu3();
void pendu2();

int main()
{
       char liste[][30] = { "abolir", "ablution", "bachot", "balisie", "cabina", "camphre", "dibit", "decorumo",
                            "echoir", "egouts", "famine", "fantoche", "gazeux", "granite", "hiatusu", "hideux", 
                            "ignoble", "iguani", "rojouir", "jonglero", "kaolin", "kiosqui", "lezerd", "linotype", 
                            "malice", "mastequer", "nymphey", "nickel", "orageo", "optique", "oraison", "parution", 
                            "pendu", "quartza", "quater", "rayon", "repide", "scenarioe", "scolaire", "tacher", 
                            "terminus", "universu", "urbanusme", "vestibule", "violent", "wagon", "water-polo", 
                            "xelophone", "yard", "yen", "zinith", "zephyr"
                     };
       char mask[][30] = {  "ab____", "a______n", "b__h__", "b__i___", "c_b___", "___ph__", "d____", "d_____m_", 
                            "_c___r", "_go___", "f_i__", "f____c__", "g____x", "g___i__", "h_a___", "h____x", 
                            "i_____e", "_g____", "__j___r", "j__g____", "k___i_", "k____u_", "l____d", "l____y__",
                            "m__i__", "m____q___", "n___h__", "n__k__", "___g__", "_p__q__", "o_a____", "p______n", 
                            "p___u", "qu_____", "q____r", "r_y__", "r_p___", "_c__a___", "s___a____", "t__h__", 
                            "t_r_____", "_n_v____", "_rb______", "v__t_____", "v__l__", "w____", "_a___-p___", 
                            "x_l____n_", "_ar_", "___", "z_____", "z___y_"
                     };

       char  nom[20], c_lenght;
       int i, nbre_c_manquant, indice_mot, essai, nbre_c_valide;
       srand(time(NULL));
       indice_mot = nbAleatoire(0, 51); // je récupère l'indice du mot à déviner dans les différents tableaux
       printf("Donnez votre nom tout d'abord\n");
       gets(nom);
       system("CLS");
       c_lenght = strlen(liste[indice_mot]); // je stocke la taille de la chaine à déviner 
       // Calcul du nombre de lettres cachées dans le mot
       for (i = 0, nbre_c_manquant = 1; mask[indice_mot][i] != '\0'; i++)
       {
              if (mask[indice_mot][i] == '_')
              {
                     nbre_c_manquant++; // je compte le nombre de caractère à déviner
              }
       }
       // Debut du jeu
       printf("\t\tBIENVENUE << %s >> dans le jeu le PENDU !!\n\tVous avez droit a 6 erreurs pour trouver le mot cach\x82 \n\t\t\tBONNE CHANCE...\n\n", nom);
       puts(mask[indice_mot]);;
       essai = 0;
       do
       {
              if (nbre_c_manquant > 0 && essai <= 5)
              {
                     printf("Donnez une lettre\t");
                     c_lenght = getch();
                     printf("%c\n", c_lenght);
                     // nbre_c_valide : Variable a partir de laquelle on pourra savoir si la lettre est valide ( si cpt est decrementé ou pas )
                     nbre_c_valide = nbre_c_manquant;
                     for (i = 0; liste[indice_mot][i] != '\0'; i++)
                     {
                         if (liste[indice_mot][i] == c_lenght && mask[indice_mot][i] == '_') // je vérifie que la lettre entrée est valide
                         {
                             mask[indice_mot][i] = c_lenght;
                             nbre_c_manquant--;
                         };
                         
                     }
                     // Si la variable nbre_c_manquant à varier alors : selon le nombre d'essais restant
                     if (nbre_c_valide == nbre_c_manquant && essai != 6)
                     {
                             essai = essai + 1;
                             if ((nbre_c_dans_une_chaine(liste[indice_mot], c_lenght) != 0) &&  (nbre_c_dans_une_chaine(liste[indice_mot], c_lenght) == nbre_c_dans_une_chaine(mask[indice_mot], c_lenght))) {
                                 essai = essai - 1;
                                 printf("\n\nAttention : La lettre \"%c\" fait bien parti des lettres du mot à trouv\x82s\nIl vous reste %d erreurs : Profitez en bien ...\n\n",
                                     c_lenght, 6 - essai);
                             } else printf("\n\nAttention : La lettre \"%c\" n'existe pas parmi les lettres cach\x82s\nIl vous reste %d erreurs : Profitez en bien ...\n\n", c_lenght, 6 - essai);
                             switch_pendu_by_essai(essai);
                     }
                     puts(mask[indice_mot]);
              }
       } while (nbre_c_manquant > 1 && essai <= 5);
       // Si le mot est trouvé
       if (nbre_c_manquant && essai <= 5)
       {
              printf("\n\nBravo !!! Maintenant vous meritez votre vie %s !!! Fantastique...\nLe mot \x82tait bien \"%s\"", nom, liste[indice_mot]);
       }
       // Sinon
       else if (nbre_c_manquant = 0 || essai >= 6)
       {
              printf("\nD\x82sol\x82 %s ... Faites vos dernieres prieres... Vous serez pendu hahahahaha!!!", nom);
       }

       getch();
       return 0;
}

int nbAleatoire(int min, int max)
{
       int nbAl;
       nbAl = rand() % (max + 1) + min;
       return nbAl;
}

int nbre_c_dans_une_chaine(char* chaine, char c) {
    int nbre = 0;
    for (int i = 0; i < strlen(chaine); i++) {
        if (chaine[i] == c) {
            nbre++;
        }
    }
    return nbre;
};


void pendu6()
{
       printf(" _\n");
       printf("|_|\n");
       printf("_|_\n");
       printf(" |\n");
       printf("/ \\\n");
}

void pendu5()
{
       printf(" _\n");
       printf("|_|\n");
       printf("_|_\n");
       printf(" |\n");
       printf("/ \n");
}

void pendu4()
{
       printf(" _\n");
       printf("|_|\n");
       printf("_|_\n");
       printf(" |\n\n");
}

void pendu2()
{
       printf(" _\n");
       printf("|_|\n");
       printf(" |\n\n");
}

void pendu3()
{
       printf(" _\n");
       printf("|_|\n");
       printf(" |\n |\n\n");
}

void pendu1()
{
       printf(" _\n");
       printf("|_|\n\n");
}

void switch_pendu_by_essai(int essai) {
    switch (essai)
    {
    case 1:
        pendu1();
        break;
    case 2:
        pendu2();
        break;
    case 3:
        pendu3();
        break;
    case 4:
        pendu4();
        break;
    case 5:
        pendu5();
        break;
    case 6:
        pendu6();
        break;
    default:;
    }
};