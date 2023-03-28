#include <stdio.h>

#define LONGUEUR    20
#define LARGEUR     5

void console_rectangle();
int main(void){
    console_rectangle();
}

void console_rectangle(){
    for(int i=0; i< LARGEUR; i++){
        for(int j=0; j<LONGUEUR; j++){ 
            printf("*");
        }
        
        printf("\n");
    }
};