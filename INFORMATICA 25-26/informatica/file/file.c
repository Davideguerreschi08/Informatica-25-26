//scrivi un file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *file=fopen("dati.txt", "w");
    if(file==NULL){
        printf("\nerrore apertura file");
        return 1;
    } 
    fprintf(file, "ciao\n");
    fprintf(file, "il numero: %d", 10 );

    fclose(file);//chiude il file
    return 0;

}