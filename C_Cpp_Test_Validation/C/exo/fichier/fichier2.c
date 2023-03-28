#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {

    FILE* fichier = fopen("fichier_a_copier.txt", "r");

    int c;
    int inside_word = 0;
    int nmots = 0;

    /* while (!feof(mon_fichier)) */
    while ((c = fgetc(fichier)) != EOF) /* suite à la remarque de ++Taz */
    {
        //C=fgetc(mon_fichier);
        if (isspace(c))
        {
            if (inside_word)
            {
                nmots++;
                inside_word = 0;
            }
        }
        else
            inside_word = 1;
    }
    fclose(fichier); //edit etourderie (merci ++Taz)
    printf("%d mots\n", nmots);
    return 0;
}