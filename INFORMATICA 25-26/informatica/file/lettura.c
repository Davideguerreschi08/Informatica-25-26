#include <stdio.h>

int main(){
    FILE *file=fopen("dati.txt", "r");
    char nome[100];
    int eta;
    float media=0;

    if(file==NULL){
        printf("\nerrore apertura file");
        return 1;
    } 
    fscanf(file, "%s %d %f", nome, &eta, &media);
    printf("nome: %s ETA': %d MEDIA: %.2f", nome, eta, media);
    fclose(file);
    return 0;
}