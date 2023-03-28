#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uart_morse.h"

int main(int argc, char **argv){
	
	if(verification_commandes(argc, argv) > 1) {
		acceuil_ou_aide();
	} else {
		for(int i=0; i < argc; i++){
			printf(" argument [%d]  est  : %s\n", (i+1), argv[i]);
		}	
	}
}	