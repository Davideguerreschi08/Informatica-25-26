/*funzioni FGETS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char buffer[20];

    printf("inserisci una stringa: ");
    if(fgets(buffer, 20, stdin)!=NULL){
        printf("hai inserito %s", buffer);
    }
}
