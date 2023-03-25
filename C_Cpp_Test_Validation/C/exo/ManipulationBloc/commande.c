#include <stdio.h>
#include <stdlib.h>

char commande[] = "";

int main(){
    while(1){
        printf("$");
        scanf("%30s", commande);
       if (commande == "exit") {
         system("exit");
       };
        system(commande);
       // printf("%30s\n", commande);
        // char commande[] = "dir";
        // system(commande);
    }
    
    return 0;
}
    
