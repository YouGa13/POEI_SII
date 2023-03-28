#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uart_morse.h"


int verification_commandes(int args_value, char **tab){
	int i=1;
	int bool_een = 0;
	while( i < args_value){
		if((strcmp( tab[i], "-t") == 0) || (strcmp(tab[i], "-m") == 0) 
			|| (strcmp(tab[i] ,"-b") == 0) || (strcmp(tab[i] , "-n") == 0)
			|| (strcmp(tab[i] , "-s") == 0) || (strcmp(tab[i] , "-h") == 0) )  {
			bool_een = 0;
		} else {
			bool_een ++;
		} 
		i++;
	};
	return bool_een;
};

void acceuil_ou_aide(){
		
		printf(" \t-t : les trois timers permettant la gestion des temps du protocole MORSE  :\n");
		printf(" \t-b : envoie le message en boucle  \n");
		printf(" \t-n : permet à l’utilisateur de choisir un nombre de répétition du message   \n");
		printf(" \t-s : permet l’arrêt immédiat de l’envoi de messages  \n");
		printf(" \t-m : précise le message   \n");
		printf(" \t-h : affiche l’aide   \n");
}

void ordre_parametres(){
		printf(" Votre ligne de commande doit respecter l'ordre suivant : \n");
};

int contrainte_sur_commande(int args_value, char **tab){
	if(verification_commandes(args_value, tab) > 1) {
		acceuil_ou_aide();
	} else {
		if ((strcmp(tab[1] ,"-b") != 0));
	}
};