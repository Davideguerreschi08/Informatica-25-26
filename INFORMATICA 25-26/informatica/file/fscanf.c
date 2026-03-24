#include <stdio.h>
 int main(){
    FILE *file=fopen("dati.txt", "w");
    char riga[100];
    if(file==NULL){
        printf("\nerrore apertura file");
        return 1;
    }
    fprintf(file , "%s %d %f", "Luca", 12, 6.5);
    fclose(file);
    return 0;
 }